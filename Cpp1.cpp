/*7-3 查找书籍 (25分)

给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。
输入格式:
输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。
输出格式:
在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。
输入样例:
3
Programming in C                  注意书名有空格
21.5
Programming in VB
18.5
Programming in Delphi
25.0
输出样例:
25.00, Programming in Delphi
18.50, Programming in VB*/
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
