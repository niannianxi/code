#include<stdio.h>
void perfect(int x,int y)
{
	int i,j,sum,flag=0,p=0;
	for(i=x;i<=y;i++)
	{
		sum=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			sum+=j;
		}
		if(i==sum&&i!=1)
		{
			if(p==0)
			printf("%d",i);
			else printf(" %d",i);
			flag=1;
			p++;
		}
	}
	if(flag==0)
	printf("None\n");
	
 } 
 int main(){
 	int a,b;
 	scanf("%d %d",&a,&b);
 	perfect(a,b);
 }
