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
		scanf("\n");/*������Щ�˲�֪��Ϊɶ��Ҫ����һ�� �� 
		������Ϊgets���������⣬��һ������n�ǻس�����������������ⲽ
		����ôgets�������յ��ľ��ǻس���\n�������ͽ����ˣ���û�а�ʵ��Ҫ����ַ������롣
		�Ժ������Ҫ�����ַ�������ǰ���ֳ�����scanf��������һ����
		�Ϳ��Բ���forѭ�����룬ֱ��ʹ��gets*/ 

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