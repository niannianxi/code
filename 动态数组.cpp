#include"head.h"

int main()
{
	//int a=100;
	//int nums=[a];
	//#c�����У������������������ʱ�����������������һ����ֵ���˴������int a����const int a�������� 
	int a;
	printf("����������Ĵ�С\n");
	scanf("%d",&a);
	int *nums=(int *)malloc(a*sizeof(int)); 
	for(int i=0;i<a;i++)
	{
		scanf("%d",nums+i);
	}
	for(int i=0;i<a;i++)
	{
		printf("%d",*(nums+i));
	}
	return 0;
}
