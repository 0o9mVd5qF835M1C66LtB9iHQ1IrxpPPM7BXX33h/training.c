#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

int main(void)
{
	int x[SIZE];
	int i,k;
	srand(time(0));
	printf("array content\n");
	for(k=0;k<SIZE;++k)
	{
		x[k]=rand()%20;
		printf("%d",x[k]);
	}
	printf("\n");
	printf("unique values\n");
	for(i=0;i<SIZE;++i)
	{
		int counter=0;
		for(k=0;k<SIZE;++k)
		{
			if(x[k]==x[i])
			{
				counter++;
				if(counter==2)
					break;
			}
			
		}
		if(counter==1)
			printf("%d",x[i]);
	}
	getch();
	return 0;
}
