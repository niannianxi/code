#include<stdio.h>
#include <cstdlib>
int main(void)
{
	FILE *fp;
	char ch,file[20];
	printf("请输入文件名");
	gets(file);
	if((fp=fopen(file,"w"))==NULL)
	{
	   printf("不能打开文件");
	 
	}
	printf("请输入数据：\n");
		while((ch=getchar())!='#')
			fputc(ch,fp);
			fclose(fp);
		 
}
