#include <stdio.h>
#include <stdlib.h>

int is_prime(int number);

int main(int argc, char *argv[])
{
  int i;
  for(i=0;i<1000;i++)
  {
   if(is_prime(i))
   {
    printf("%d",i);
   }
  }
  system("PAUSE");	
  return 0;
}

int is_prime(int number)
{
    int i;
    if(number==0 || number==1)
    {
     return 0;
    }
    if(number%2==0)
    {
     return number==2;
    }
    if(number%3==0)
    {
     return number==3;               
    }
    if(number%5==0)
    {
     return number==5;               
    }
    for(i=7;i*i<=number;i+=2)
    {
     if(number%i==0)
     return 0;
    }
    return 1;
}
