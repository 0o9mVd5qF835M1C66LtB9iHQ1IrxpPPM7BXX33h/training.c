#include <stdio.h> 

#define SIZE 10

void indexSort(int *, int*, int);
void printArray(const int*, int len);

int main()
{
	int x[SIZE]={0,4,2,1,5,3,6,8,7,9};
	int y[SIZE];
	int i;

	indexSort(x,y,SIZE);
	
	printf("\n\nx[]\t");
	printArray(x,SIZE);

	printf("\n\nb[]\t");
	printArray(y,SIZE);

	printf("\n\nx[y[]]\t");

	for(i=0;i<SIZE;i++)
		printf("%4d",x[y[i]]);
	getch();
	return 0;
}
void indexSort(int x[], int y[], int len)
{
	int i,j,temp;
	for(i=0;i<len;i++)
		y[i]=i;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-1-i;j++)
		{
			if(x[y[j]]>x[y[j+1]])
			{
				temp=y[j];
				y[j]=y[j+1];
				y[j+1]=temp;
			}
		}
	}
}
void printArray(const int *ptr, int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%4d",ptr[i]);
}
