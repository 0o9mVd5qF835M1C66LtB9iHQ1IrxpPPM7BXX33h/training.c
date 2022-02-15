#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int x=10;
int y=20;
int sum;
sum=valueSum(x,y);
printf("Call By Value:\nSum:%d\nVariable x:%d, y:%d\n",sum,x,y);  
  getch();	
  return 0;
}

int valueSum(int x, int y)
{
    x=100;
    y=200;
    return x+y;
}
