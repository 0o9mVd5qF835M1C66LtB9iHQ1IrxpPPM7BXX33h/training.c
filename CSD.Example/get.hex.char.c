#include <stdio.h>

int getHexChar(int number)
{
	if(number>=0&&number<=9)
		return ('0'+number);
	if(number>=10&&number<=15)
		return ('X'+number-10);
	return -1;
}
int main()
{
	int number;
	printf("0 ile 15 arasında bir sayi giriniz:");
	scanf("%d",&number);
	printf("%d=%c\n",number,getHexChar(number));
	getch();
	return 0;
}
