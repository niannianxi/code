#include<stdio.h>
int max(int x,int b);//函数声明
  int min(int a,int b);//函数声明
  int add(int a,int b);//函数声明 
  int process(int x,int y,int(*fun)(int x,int y));//函数声明
   
int  main()
{
  
  
 
   int a,b;
   printf(" enter a and b:");
   scanf("%d %d",&a,&b);
   
   printf("max = %d\n",process(a,b,max));
   
   printf("min = %d\n",process(a,b,min));
   
   printf("sum = %d\n",process(a,b,add));
   
}
int max(int x,int y)//函数定义
{
	int z;
	if(x>y)
	z=x;
	else z=y;
	return z;
 } 

 int min(int x,int y)//函数定义
{
	int z;
	if(x<y)
	z=x;
	else z=y;
	return z;
 } 
 int add(int x,int y)
 {
 	return x+y;
 }
 int process(int x,int y,int(*fun)(int x,int y))
 
 {
 	int result;
 	result=(*fun)(x,y);
 	return result;
 }


 
