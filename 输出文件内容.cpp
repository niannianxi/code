#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
   char a[20];
   gets(a);
   fp=fopen(a,"r");
   char c;
   if(fp==NULL)
   {
   		printf("�޷��򿪸��ļ�");
	   exit(-1); 
	} 
   while((c=fgetc(fp))!=EOF)
	   putchar(c);
	fclose(fp);
}
