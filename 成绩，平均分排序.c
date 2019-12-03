#include<stdio.h>
void main(){
	int a[5][3];
	double ave[5],t;
	int i,j,k,m,sum;
	for(i=0;i<5;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<5;i++){
		sum=0;
	
		for(j=0;j<3;j++){
			sum+=a[i][j];
		}
		ave[i]=1.0*sum/3;
	}	
	for(i=0;i<4;i++){
	for(j=1+i;j<5;j++)
	{
	if(ave[i]<ave[j])
	{//也可采用保存下标方法，减少交换次数 
		for(k=0;k<3;k++){
			m=a[i][k];
			a[i][k]=a[j][k];
			a[j][k]=m;   
		}
		t=ave[i];
		ave[i]=ave[j];
		ave[j]=t;
	}
	}}
	for(i=0;i<5;i++)
		printf("%8d%8d%8d%.8lf\n",a[i][0],a[i][1],a[i][2],ave[i]);
}
