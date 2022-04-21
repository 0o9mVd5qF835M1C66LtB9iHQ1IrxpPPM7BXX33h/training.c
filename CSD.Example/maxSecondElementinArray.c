#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main(void)
{
	int x[SIZE];
	int maxFirst,maxSecond,i,k,temp;
	srand(time(0));
	for(k=0;k<SIZE;++k)
		x[k]=rand()%1000;
	maxFirst=x[0];
	maxSecond=x[1];
	if(x[1]>x[0])
	{
		maxFirst=x[1];
		maxSecond=x[0];
	}
	for(k=2;k<SIZE;++k)
		if(x[k]>maxFirst)
		{
			maxSecond=maxFirst;
			maxFirst=x[k];
		}
		else if(x[k]>maxSecond)
			maxSecond=x[k];
	printf("print maxSecond:%d\n",maxSecond);
	for(i=0;i<SIZE-1;++i)
		for(k=0;k<SIZE-1-i;++k)
			if(x[k]>x[k+1])
			{
				temp=x[k];
				x[k]=x[k+1];
				x[k+1]=temp;
			}
	printf("print ordinary array:\n");
	for(k=0;k<SIZE;++k)
	printf("%3d",x[k]);
	getch();
	return 0;
}
