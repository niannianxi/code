#include<stdio.h> 
#include<math.h> 
#include<stdlib.h> 
#include<conio.h> 
#include<malloc.h> 
#include<string.h> 
#define MAXSIZE 100 
#define MAXMU 25 
typedef struct 
{ 
int i,j; 
int v; 
}Triple; 
typedef struct 
{ int rpos[MAXMU+1]; 
Triple data[MAXSIZE+1]; 
int mu,nu,tu; 
}TSMatrix; 
TSMatrix A,B,C; 
void creat(TSMatrix *T) 
{ 
int row,num,k; 
do 
{ 



printf(" 请输入稀疏矩阵行数: "); 
scanf("%d", &T->mu); 
if (T->mu<0 || T->mu>MAXMU) 
printf("\n 行数超出定义范围,请重新输入!\n"); 
} while (T->mu<0 || T->mu>MAXMU); 
do 
{ 
printf(" 请输入稀疏矩阵列数: "); 
scanf("%d", &T->nu); 
if (T->nu<0 || T->nu>MAXMU) 
printf("\n 列数超出定义范围,请重新输入!\n"); 
} while (T->nu<0 || T->nu>MAXMU); 
do 
{ 
printf(" 请输入稀疏矩阵的非零元素个数: "); 
scanf("%d", &T->tu); 
if (T->tu>MAXSIZE || (T->tu>T->mu*T->nu)) 
printf("\n 非零元素个数超出定义范围,请重新输入!\n"); 
} while (T->tu>MAXSIZE || (T->tu>T->mu*T->nu)); 


for (k=1; k<=T->tu; k++) 
{ 
do 
{ 
printf(" 请输入第%d个非零元素的行数row:", k); 
scanf("%d", &T->data[k].i); 
if (!T->data[k].i || T->data[k].i>T->mu) 
printf("\n 输入有误，请重新输入!\n"); 
} while ((!T->data[k].i || T->data[k].i>T->mu)); 
do 
{ 
printf(" 请输入第%d个非零元素的列数col:", k); 
scanf("%d", &T->data[k].j); 
if (!T->data[k].j || T->data[k].j>T->nu) 
printf("\n 输入有误，请重新输入!\n"); 
} while ((!T->data[k].j || T->data[k].j>T->nu)); 
do 
{ 
printf(" 请输入第%d个非零元素的值value:", k); 
scanf("%d", &T->data[k].v); 
if (T->data[k].v==0) 
printf("\n 输入有误，请重新输入!\n"); 
} while (T->data[k].v==0); 

} 
for(row=1,num=1;row<=T->mu;row++) 
{ 
T->rpos[row]=num; 
while(T->data[num].i==row) 
num++; 
} 
return; 
} 

void print(TSMatrix A) 
{ 
int q,n,k,a=0; 


printf("\n\n稀疏矩阵为：\n"); 

for(n=1;n<=A.mu;n++) 
{ 
for(k=1;k<=A.nu;k++) 
{ 
for(q=1;q<=A.tu;q++) 
if(A.data[q].i==n && A.data[q].j==k) 
{ 
printf("\t%-3d",A.data[q].v);break; 
} 
if(q>A.tu) 
printf("\t%-3d",a); 
} 
printf("\n"); 
} 

} 

void add(TSMatrix A,TSMatrix B) 
{ 

int n,k; 
if(A.mu!=B.mu || A.nu!=B.nu) 
{ 
printf("\n 不满足矩阵相加条件!"); 
printf("\n 需满足两矩阵的行数、列数均对应相等方可进行加法运算！！"); 
} 
else 
{ 
for(n=1;n<=A.tu;n++) 
for(k=1;k<=B.tu;k++) 
if(A.data[n].i==B.data[k].i && A.data[n].j==B.data[k].j) 
{ 
A.data[n].v+=B.data[k].v; 
B.data[k].v=0; 
} 
for(k=1;k<=B.tu;k++) 
if(B.data[k].v!=0) 
{ 
A.data[A.tu+1].i=B.data[k].i; 
A.data[A.tu+1].j=B.data[k].j; 
A.data[A.tu+1].v=B.data[k].v; 
A.tu++; 
} 
print(A); 
} 
} 




char menu() 
{ 
char n;


printf(" 1:矩阵相加 \n"); 
printf(" 2:矩阵转置 \n"); 
printf(" 3:退出 \n"); 
printf(" 输入序号进行操作 \n"); 
n=getchar(); 

return n; 
} 

void zhuanzhi(TSMatrix A) 
{ 
int p,q,m; 
TSMatrix B; 
B.mu=A.nu; 
B.nu=A.mu; 
B.tu=A.tu; 
if(B.tu) 
{ 
m=1; 
for(p=1;p<=A.mu;p++) 
for(q=1;q<=A.nu;q++) 
{ 
B.data[m].i=A.data[m].j; 
B.data[m].j=A.data[m].i; 
B.data[m].v=A.data[m].v; 
++m; 
} 
} 
print(B); 
} 




int main()
{
switch(menu()) 
{case '1':creat(&A); 
creat(&B);
print(A); 
print(B); 
add(A,B); 
getch(); 
break; 
case '2':creat(&A); 
print(A); 
zhuanzhi(A); 
getch(); 
break; 
case '3': 


exit(0); 
} 
return 0;
}