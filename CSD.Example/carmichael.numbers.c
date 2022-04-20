#include <stdio.h>
#include <string.h>

typedef enum {FALSE, TRUE} typebool;

typebool is_prime(long int number);
typebool is_composite (long int number);
typebool is_carmichael(long int number);

long int gcd(long int x, long int y);
long int fermat_formula(long int x, long int y);

int main()
{
	long int i;
	printf("enter a number : ");
	scanf("%ld", &i);
	if(is_prime(i))
		printf("%ld is a prime number.\n");
	else
		printf("%ld is a composite number.\n");
	if(is_carmichael(i))
		printf("%ld is a carmichael number.\n",i);
	else
		printf("%ld is not a carmichael number.\n",i);
	getch();
	return 0;
}

typebool is_prime(long int number)
{
	long int i;
	if(number==0 || number==1)
		return FALSE;
	if(number%2==0)
		return number==2;
	if(number%3==0)
		return number==3;
	if(number%5==0)
		return number==5;
	for(i=7;i*i<=number;i+=2)
		if(number%i==0)
			return FALSE;
	return TRUE;
}

typebool is_carmichael(long int number)
{
	long int i;
	
	if(is_prime(number)||number==0)
		return FALSE;

	for(i=2;i<number;i++)
	{
		if(gcd(i,number)!=1)
			continue;
		if(fermat_formula(i,number)!=1)
			return FALSE;
	}
	return TRUE;
}

long int gcd(long int x, long int y)
{
	if(y!=0)
		return gcd(y,x%y);
	return x;
}

long int fermat_formula(long int x, long int y)
{
	long int remainder=1;
	long int i;

	if(y==1)
		return 0;
	for(i=0;i<y-1;i++)
	{
		remainder=remainder*x%y;
		if(remainder==0)
			return 0;
	}
	return remainder;
}
