#include<stdio.h>
long number(int n);
int main() 
{
	int n;
	scanf("%d",&n);
	printf("����%d��̨����%ld�ַ�ʽ",n,number(n));
}
long number(int n)
{
	if(n==2||n==1)
	return n;
	else 
		return  number(n-1)+number(n-2);
}
