#include<stdio.h>
long int fac(int n);//函数声明后要加； 
int main(){
 int n;
 scanf("%d",&n);
 printf("第%d个数为%d",n,fac(n));
} 
long int fac(int n){
	if(n==1||n==2)
	return 1;
	else
		return fac(n-1)+fac(n-2);//寻找关系式 
}
