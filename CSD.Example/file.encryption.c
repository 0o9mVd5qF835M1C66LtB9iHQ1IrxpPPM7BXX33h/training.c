#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LEN 80

int main(int argc, char **argv)
{
	char sourcefilename[MAX_FILE_NAME_LEN+1];
	char destinationfilename[L_tmpnam];
	int key, ch;
	FILE *filesource, *filedestination;
	if(argc!=2)
	{
		printf("sifrelenecek dosyanin ismini giriniz:\n");
		gets(sourcefilename);
		printf("anahtar degerini giriniz:\n");
		scanf("%d",&key);
	}
	else
	{
		strcpy(sourcefilename,argv[1]);
		key=atoi(argv[2]);
	}
	tmpnam(destinationfilename);
	filesource=fopen(sourcefilename,"rb");
	if(filesource==NULL)
	{
		fprintf(stderr,"%s dosyasi acilamiyor1!\n",sourcefilename);
		getch();
		exit(EXIT_FAILURE);
	}
	filedestination=fopen(destinationfilename,"wb");
	if(filedestination==NULL)
	{
		fprintf(stderr,"%s dosyasi acilamiyor2!\n",sourcefilename);
		getch();
		exit(EXIT_FAILURE);
	}
	srand(key);
	while((ch=fgetc(filesource))!=EOF)
		fputc(ch^rand(),filedestination);
	
	fclose(filesource);
	fclose(filedestination);

	remove(sourcefilename);
	rename(destinationfilename,sourcefilename);
	printf("successfull.\n");
	getch();
	return 0;
}	
