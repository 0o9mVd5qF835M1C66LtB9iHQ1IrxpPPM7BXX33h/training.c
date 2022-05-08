#include <stdio.h>

#define SIZE 10

void indexSort(int x[], int y[], int len);
void printArray(const int x[], int len);

int main()
{
	int x[SIZE]={20,10,40,80,70,90,60,50,30,00};
	int y[SIZE];
	int i;

	indexSort(x,y,SIZE);
	printf("\n\nx[]\t");
	printArray(x,SIZE);
	
	printf("\n\ny[]\t");
	printArray(y,SIZE);

	printf("\nx[y[]]\t");

	for(i=0;i<SIZE;i++)
		printf("%4d",x[y[i]]);
	getch();
	return 0;
}
void indexSort(int x[],int y[],int len)	/*sıralama fonksiyonunun tanımlanması*/	
{
	int i,j,index,temp;
	for(i=0;i<len;i++) 
		y[i]=i;							/*indis numaralarının y dizisine atanması.*/
	for(i=0;i<len;i++)
	{
		index=i;
		for(j=i;j<len;j++)
		{
			if(x[y[j]]<x[y[index]])
				index=j;
			temp=y[index];
			y[index]=y[i];
			y[i]=temp;
		}
	}
}
void printArray(const int x[], int len)
{
	int i;
	for(i=0;i<len;i++)
		printf("%4d",x[i]);
}
