#include<stdio.h>
#include <cstdlib>
int main(void)
{
	FILE *fp;
	char ch,file[20];
	printf("�������ļ���");
	gets(file);
	if((fp=fopen(file,"w"))==NULL)
	{
	   printf("���ܴ��ļ�");
	 
	}
	printf("���������ݣ�\n");
		while((ch=getchar())!='#')
			fputc(ch,fp);
			fclose(fp);
		 
}
