#include <stdio.h>

#define MAX 100000

int get_sumf(int val)
{
	int sum=1;
	int i;
	for(i=2;i<=val/2;++i)
		if(val%i==0)
			sum+=i;
	return sum;
}

int main()
{
	int i,j;
	for(i=2;i<MAX;++i)
	{
		int val=get_sumf(i);
		for(j=0;j<i;++j)
		{
			if(val==j && get_sumf(j)==i)
				printf("%d %d\n",i,j);
		}
	}
	getch();
	return 0;
}
