#include<stdio.h>
long int fac(int n);//����������Ҫ�ӣ� 
int main(){
 int n;
 scanf("%d",&n);
 printf("��%d����Ϊ%d",n,fac(n));
} 
long int fac(int n){
	if(n==1||n==2)
	return 1;
	else
		return fac(n-1)+fac(n-2);//Ѱ�ҹ�ϵʽ 
}
