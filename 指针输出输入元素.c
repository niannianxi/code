#include<stdio.h>
int main(){
	int a[10],*p,i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	p=a;
	for(i=0;i<10;i++)
	printf("%d\t",*(p+i));//���ÿ���������� ��p++��ʾָ����һ����Ż����������͵ĵ�ַ��*��p++)���ʾȡ����һ���� 
} 

