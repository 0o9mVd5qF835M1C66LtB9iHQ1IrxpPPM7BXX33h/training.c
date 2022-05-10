#include <winsock2.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define DEFAULT_PORT		5150

int gPort=DEFAULT_PORT;					//Port on server to connect to
char g_szServerName[128]="nameserver";	//Server to connect to

int main(void)
{
	WSADATA wsd;
	SOCKET sClient;
	int ret, ch;
	struct sockaddr_in server;
	struct hostent *host=NULL;

	if(WSAStartup (MAKEWORD(2,2),&wsd)!=0)
	{
		fprintf(stderr,"Failed to load Winsockvlibrary!\n");
		return 1;
	}
	//Create the socket, and attempt to connect to the server
	sClient=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sClient==INVALID_SOCKET)
	{
		fprintf(stderr,"socket() failed:%d\n", WSAGetLastError());
		return 1;
	}
	//Select the local interface and bind to it
	server.sin_family=AF_INET;
	server.sin_port=htons(gPort);
	server.sin_addr.s_addr=inet_addr(g_szServerName);
	//If the suplied server address wasn't in the form
	//"xx.xxx.xxx.xxx" it is a hostname, so try to resolve it.
	if(server.sin_addr.s_addr==INADDR_NONE)
	{
		host=gethostbyname(g_szServerName);
		if(host==NULL)
		{
			fprintf(stderr,"Unable to resolve server:%s\n",g_szServerName);
			return 1;
		}
		copyMemory(&server.sin_addr,host->h_addr_list[0],host->h_length);
	}
	if(connect(sClient,(struct sockaddr *)&server, sizeof(server))==SOCKET_ERROR)
	{
		fprintf(stderr,"connect failed: %d\n", WSAGetLastError());
		return 1;
	}
	for(;;)
	{
		ch=getch();
		if(ch=='\r')
			ch='\n';
		putchar(ch);
		ret=send(sClient,(char *) &ch,1,0);
		if(ret==0)
			break;
		if(ret==SOCKET_ERROR)
		{
			fprintf(stderr,"send() failed: %d\n",WSAGetLastError());
			break;
		}
		if(ch='\x1b')
			break;
	}
	closesocket(sClient);
}
