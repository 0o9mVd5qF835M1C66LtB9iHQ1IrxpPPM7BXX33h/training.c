#include <stdio.h>

void writeASCII(int index)
{
	printf("%c",index);
	(index==0)?
		printf("completed.")
		:
		writeASCII(--index); 
}
/*16 bit number (4 byte integer)*/
void writeBinary(int number,int byteParts)
{
	int devicious=number%2;
	if(number==1)
	{
		printf("%d",devicious);
	}
	else
	{
		printf("%d",devicious);
		
		if(byteParts==1)
			printf(".");
		if(byteParts==0)
			byteParts=4;
		writeBinary(number/2,--byteParts);
	}
}

void main(void)
{
writeBinary(1024,4);
printf("\nPress a key to terminate this program.");
getch();
return 0;
}

