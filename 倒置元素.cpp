#include<stdio.h>
int main(){
  int a[10],i,j,t,n;
  for(i=0;i<10;i++){
  	scanf("%d",&a[i]);
  }
  printf("����ǰ����Ԫ�أ�");
  scanf("%d",&n);
  for(i=0;i<n;i++){
  	t=a[0];
  	for(j=1;j<10;j++){
  		a[j-1]=a[j];
		  
	  }
	  a[9]=t;
  } 
  for(i=0;i<10;i++)
  printf("%d\n",a[i]);
}
