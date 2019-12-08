
#include <stdio.h>

#include <math.h>

int isprime(int x);

int main()

{

	int n,k;

	scanf("%d %d",&n,&k);

	int sum=0;

	for(int j=n;j>=2;j--)

	{

		if(isprime(j))//如果是素数

		{

			sum+=j;//素数求和

	        if(k==1)

			{

			  printf("%d=",j);//关键点k最后减到1时要输出等号而不是加号，要有想法哦 

	                    break;

			}

			if(j==2)//判断到j=2,循环没有退出，2是最后一个数

			{

			   printf("%d=",j);

		    }else

			{

		    	printf("%d+",j);

			}

			k--;

		}	

	}

	printf("%d",sum);

	return 0;

}

int isprime(int x)//判断是否是素数

{

	int flag=1;

	for(int i=2;i<=sqrt(x);i++)

	{

		if(x%i==0&&x!=2)

		{

			flag=0;

			break;

		}

	}

	return flag;

}

