#include<stdio.h>
void main(){
	int a[10];
	int *p,i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}

	for(p=a;p<(a+10);p++)
	printf("%d\t",*p);
}

