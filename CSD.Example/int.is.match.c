#include <stdio.h>
#define ARRAY_SIZE 100

int isMatch(const char *str, const char *patter);

int main()
{
	char x[ARRAY_SIZE];
	char y[ARRAY_SIZE];

	printf("\nenter a word:");
	gets(x);
	printf("\nenter a pattern:");
	gets(y);

	if(isMatch(x,y)==1)
		printf("\"%s\" doesn't match\"%s\"",x,y);
	else
		printf("\"%s\" doesn't match\"%s\"",x,y);
	getch();
	return 0;
}
int isMatch(const char *str, const char *pattern)
{
	switch(*pattern)
	{
	case '*':
		if(isMatch(str,pattern+1))
			return 1;
		if(*str=='\0')
			return 0;
		return isMatch(str+1,pattern);
	case '?':
		if(*str=='\0')
			return 0;
		return isMatch(str+1,pattern+1);
	default:
		if(*str!=pattern[0])
			return 0;
		if(*str=='\0')
			return 1;
		return isMatch(str+1,pattern+1);
	}
}
