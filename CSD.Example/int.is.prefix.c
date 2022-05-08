#include<stdio.h>

int isPrefix(const char *target, const char *prefix);

int main(void)
{
	char x[]="Mr. Smith";
	if(isPrefix(x,"Mr.")==1)
		printf("%s-->Men\n",x);
	else if(isPrefix(x,"Mrs.")==1)
		printf("%s-->Women\n",x);
	else
		printf("%s--> unknown\n",x);
	getch();
	return 0;
}
int isPrefix(const char *target, const char *prefix)
{
	for(;*prefix==*target;prefix++,target++)
		if(*prefix=='\0')
			break;
	return *prefix=='\0';
}
