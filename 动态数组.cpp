#include"head.h"

int main()
{
	//int a=100;
	//int nums=[a];
	//#c语言中，声明（创建）数组的时候，中括号里面必须是一个定值，此处如果把int a换成const int a则程序可行 
	int a;
	printf("请输入数组的大小\n");
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
