#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int isCardinal(int x);
int main(int argc, char *argv[])
{
	int i,j;
	int v=0;
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		int x=rand()%100+10;
		while(x>100)
			x=rand()%100+10;;
		for(j=2;j<10;j++)
		{
			if((x%j)==0)
				v++;
		}
		(v==0)?printf("%d.Cardinal number\n\n",x):printf("%d.not cardinal number\n\n",x);
	}
	system("PAUSE");
	return 0;
}
