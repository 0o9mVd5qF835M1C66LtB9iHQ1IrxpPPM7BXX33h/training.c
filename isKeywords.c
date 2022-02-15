#include<stdio.h>
#include<stdlib.h>

int isKeyword(const char *str);
void main()
{
	int result=0;
	const char *pstr=malloc(sizeof(char));
	printf("Test edilecek kelimeyi giriniz:");
	gets(pstr);
	puts(pstr);
	result=isKeyword(pstr);
	getch();
}
int isKeyword(const char *str)
{
	int i=0;
	char *pKeywords[32]={"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","continue","for","signed","void","do","if","static","while","default","goto","sizeof","volatile","const","float","short","unsigned"};
	while(!(*pKeywords[i]=='\0'))
	{
		if(*str==*pKeywords[i])
			printf("true.\n");
		else
			printf("false.\n");
		i++;
	}
	return 0;
}
