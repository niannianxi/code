/*给定 N 个非 0 的个位数字，用其中任意 2 个数字都可以组合成 1 个 2 位的数字。
要求所有可能组合出来的 2 位数字的和。
例如给定 2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。*/
#include<stdio.h>
int main()
{
    int a[10];
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int sum=0;//题目要求求和,则只需用一个数据存储 
     for( i = 0; i < n; i++ )
      {        
          for( j = 0; j < n; j++ )
           {            if( i != j )
            {             
                   sum += a[i] * 10 +a[j];    //注意下标不同即可组合，代表的数不同      
              }       
               }    
               }     
               printf( "%d", sum );   
                return 0;
}
//要多想，找题目的破解之法 
