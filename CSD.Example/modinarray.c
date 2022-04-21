#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main(void)
{
	int x[SIZE];
	int mod=0;
	int modval;
	int k,i,counter;
	
	srand(time(0));
	for(k=0;k<SIZE;++k)
	{
		x[k]=rand()%50;
		printf("%d",x[k]);
	}
	modval=x[0];
	printf("\n");
	for(i=0;i<SIZE;++i)
	{
		counter=0;
		for(k=0;k<SIZE;++k)
			if(x[k]==x[i])
				counter++;
		if(counter>mod)
		{
			mod=counter;
			modval=x[i];
		}
	}
	printf("mod=%d\nFrequency=%d\n",modval,mod);
	getch();
	return 0;
}
