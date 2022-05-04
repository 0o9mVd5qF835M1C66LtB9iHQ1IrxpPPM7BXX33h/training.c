#include <stdio.h>
#include <ctype.h>
 
int is_id(const char *str)
{
   char ch;
 
   if ((ch = *str++) == '\0')
      return 0;      /* bos yazi */
 
   if (!(isalpha(ch) || ch == '_'))
      return 0;
 
   while ((ch = *str++) != '\0')
      if (!(isalnum(ch) || ch == '_'))
         return 0;
   return 1;
}

void main(void)
{
	int i=is_id("name");
	if(i==1)
		printf("result:successfully:%d",i);
	getch();
}
