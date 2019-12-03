#include<stdio.h>
int main()
{
    int n,m,i,t=0;//定义t为0，如果没定义，可能最小值最大值有可能就在a[0],如果if语句里不交换会出现乱码，不知道t在哪 
	int a[10];
    scanf("%d",&n);   
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int max,min;
    max=a[0],min=a[0];
    for(i=0;i<n;i++){
        if(max<a[i]){
            max=a[i]; 
            t=i;   
        }    
    } 
	m=a[n-1]; 
    a[t]=a[n-1];
    a[n-1]=max;
   for(i=0;i<n;i++){
    if(min>=a[i]){
        min=a[i];
        t=i;
        }}
        m=a[0];
        a[0]=min;
        a[t]=m;
        
     for(i=0;i<n;i++)
     printf("%d ",a[i]);
}
