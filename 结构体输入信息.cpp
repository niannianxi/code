#include<stdio.h>
#include<stdlib.h>
struct student
{
	long no;
	char name[20];
	char sex[20];
	int old;
}a[10];
int fprint()
{
	int i;
	FILE *fp;
	fp=fopen("f.c","w");
	if(fp==NULL)
	{
		printf("�򿪸��ļ�ʧ��"); 
		exit(-1);
	}
	printf("������ʮ��ͬѧ����Ϣ\n");
	printf("	 ѧ��		����	       �Ա�    ����\n");
	for(i=0;i<10;i++)
	{
	   scanf("\t%ld %s %s %d",&a[i].no,a[i].name,a[i].sex,&a[i].old);
	}
	fprintf(fp,"	 ѧ��		����	   �Ա�    ����\n");
	for(i=0;i<10;i++)
	fprintf(fp,"\t%08ld\t%s\t\t%s\t%6d\n",a[i].no,a[i].name,a[i].sex,a[i].old);
	fclose(fp);
	return 0;
}
int scan()
{
	FILE *fp;
	fp=fopen("f.c","r");
	if(fp==NULL)
	{
		printf("�򿪸��ļ�ʧ��");
		exit(-1);
	}
	int i;
	printf("	 ѧ��		����	       �Ա�    ����\n");
	for(i=0;i<10;i++)
	 fscanf(fp,"\t%ld %s %s %d",&a[i].no,a[i].name,a[i].sex,&a[i].old); 
	for(i=0;i<10;i++)
	printf("\t%08ld\t%s\t\t%s\t%d\n",a[i].no,a[i].name,a[i].sex,a[i].old);
}
int main()
{
	fprint();
	scan();
}

