#include <stdio.h>

void writeASCII(int index)
{
	printf("%c",index);
	(index==0)?
		printf("completed.")
		:
		writeASCII(--index); 
}

void main(void)
{
writeASCII(256);
printf("\nPress a key to terminate this program.");
getch();
return 0;
}

