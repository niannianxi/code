#include<stdio.h>
#include<stdlib.h>
int main(){
  FILE *fp;
  int b=678910;
  fp=fopen("123","a");
  if(fp==NULL)
  {
	printf("���ļ�ʧ��");
		exit(-1);
  }
  fprintf(fp,"%d",b);
  fclose(fp);
}