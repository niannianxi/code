#include<stdio.h>
struct student
{
    char name[1000];
    double price;
}a[10];
int main()
{
    int n;
    int m=0;
	int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("\n");/*可能有些人不知道为啥呢要加这一步 ， 
		这是因为gets函数的问题，上一个输入n是回车键结束，如果不加这步
		，那么gets函数接收到的就是回车（\n），它就结束了，并没有把实际要输的字符串输入。
		以后出现需要输入字符串但是前面又出现了scanf不妨加这一步，
		就可以不用for循环输入，直接使用gets*/ 

        gets(a[i].name);
		scanf("%lf",&a[i].price);
    }
    double max=a[0].price;
	double min=a[0].price;
	int t=0;
    for(i=0;i<n;i++)
    {
        if(max<a[i].price)
        t=i;
    }
    for(i=0;i<n;i++)
    if(min>a[i].price)
    m=i;
    printf("%.2lf, %s\n",a[t].name,a[t].price);
    printf("%.2lf, %s\n",a[m].name,a[m].price);
   return 0;
}