#include <stdio.h>

#define X_SIZE 10

void insertionSort(int *p, int size);
void printArray(int *p, int size);

int main(void)
{
	int x[X_SIZE]={0,8,6,9,1,5,7,3,2,4};

	printArray(x,X_SIZE);
	insertionSort(x,X_SIZE);
	printArray(x,X_SIZE);
	getch();
	return 0;
}
void insertionSort(int *p, int size)
{
	int i,j,t;
	for(i=0;++i<size;)
	{
		t=p[i];
		for(j=i;p[j-1]>t;)
		{
			p[j]=p[j-1];
			if(--j<=0)
				break;
		}
		p[j]=t;
	}
}
void printArray(int *p, int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d",p[i]);
	putchar('\n');
}
