#include<stdio.h>
#include<stdlib.h>

int areFriends(int x, int y);
int main(int argc, char *argv[])
{
	int x;
	int y;
	int result;
	printf("please insert the x and y value");
	scanf("%d",&x);
	scanf("%d",&y);
	result=areFriends(x,y);
	system("PAUSE");
	return 0;
}
int areFriends(int x, int y)
{
	int i;
	int xResult=0;
	int yResult=0;
	for(i=1;i<x;i++)
	{
		if((x%i)==0)
			xResult=xResult+i;
		printf("%d-%d\n",i,xResult);
	}
	for(i=1;i<y;i++)
	{
		if((y%i)==0)
			yResult=yResult+i;
		printf("%d-%d\n",i,yResult);
	}
	if(xResult==y && yResult==x)
		printf("x,y values are friends.\n\n");
		return 0;
}