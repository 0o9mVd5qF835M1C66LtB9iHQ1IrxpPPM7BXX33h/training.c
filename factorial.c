#include <stdio.h>

long factorial(int n,long fact)
{
	fact*=n;
	if(n==1)
		printf("Result:%ld\n",fact);
		return fact;
	else
		return factorial(--n,fact);
}

void main()
{
	long result=factorial(5,1);
	printf("%ld",result);
	system("PAUSE");
}
