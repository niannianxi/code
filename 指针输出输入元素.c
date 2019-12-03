#include<stdio.h>
int main(){
	int a[10],*p,i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	p=a;
	for(i=0;i<10;i++)
	printf("%d\t",*(p+i));//输出每个整型数据 ，p++表示指向下一个存放基本整数类型的地址，*（p++)则表示取出下一个数 
} 

