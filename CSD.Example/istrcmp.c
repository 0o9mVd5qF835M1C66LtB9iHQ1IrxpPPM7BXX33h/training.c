#include <stdio.h>

#define ARRAY_SIZE 100

int iStrCmp(const char *str1, const char *str2)
{
	while(*str1==*str2)
	{
		if(*str1=='\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1-*str2;
}

int main()
{
	char s1[ARRAY_SIZE];
	char s2[ARRAY_SIZE];
	int cmpResult;
	printf("birinci yaziyi girin:");
	gets(s1);
	printf("ikinci yaziyi girin:");
	gets(s2);
	cmpResult=iStrCmp(s1,s2);
	if(cmpResult>0)
		printf("(%s)>(%s)\n",s1,s2);
	else if(cmpResult<0)
		printf("(%s)<(%s)\n",s1,s2);
	else
		printf("(%s)=(%s)\n",s1,s2);
	getch();
	return 0;
}
