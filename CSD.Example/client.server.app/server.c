#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_PORT 5150

int gPort=DEFAULT_PORT;		// Port to listen for clients on
int g_szAddress[128];

DWORD WINAPI ClientThread(LPVOID lpParam)
{
	SOCKET sock=(SOCKET)lpParam;
	int ret;
	char ch;

	for(;;)
	{
		ret=recv(sock,&ch,1,0);
		if(ret==0)					//Graceful close
			break;
		if(ret==SOCKET_ERROR)
		{
			fprintf(stderr,"recv() failed:%d\n",WSAGetLastError());
			break;
		}
		if(ch=='\x1b')
			break;
		putchar(ch);
	}
	return 0;
}
int main(void)
{
	WSADATA wsd;
	SOCKET sListen,sClient;
	int addrSize;
	HANDLE hThread;
	DWORD dwThreadId;
	struct sockaddr_in local, client;

	if(WSAStartup (MAKEWORD(2,2),&wsd)!=0)
	{
		fprintf(stderr,"Failed to load Winsock!\n");
		return 1;
	}
	// Create our listening socket
	sListen=socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
	if(sListen==SOCKET_ERROR)
	{
		fprintf(stderr, "socket() failed:%d\n",WSAGetLastError());
		return 1;
	}

	//Select the local interface and bind to it
	local.sin_addr.s_addr=htonl(INADDR_ANY);
	local.sin_family=AF_INET;
	local.sin_port=htons(gPort);

	if(bind(sListen,(struct sockaddr*)&local,sizeof(local))==SOCKET_ERROR)
	{
		fprintf(stderr,"bind() failed:%d\n",WSAGetLastError());
		return 1;
	}
	listen(sListen,8);
	for(;;)
	{
		addrSize=sizeof(client);
		sClient=accept(sListen,(struct sockaddr *)&client,&addrSize);
		if(sClient==INVALID_SOCKET)
		{
			fprintf(stderr,"accept() failed:%d\n",WSAGetLastError());
			break;
		}
		fprintf(stderr,"Accepted client:%s:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
			hThread=CreateThread(NULL,0,ClientThread,(LPVOID)sClient,0,&dwThreadId);
			if(hThread==NULL)
			{
				fprintf(stderr,"CreateThread() failed:%d\n", GetLastError());
				break;
			}
			CloseHandle(hThread);
		}
		closesocket(sListen);
		WSACleanup();
		return 0; 
	}
