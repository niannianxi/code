#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 100 //栈初始化的存储空间 
#define STACKINCREMENT 10 //栈溢出后增加空间（每次增加10个） 

typedef char ElemType;
typedef struct
{ 
	ElemType *base;//栈顶 
	ElemType *top;//栈底 
	int stackSize;//栈当前可使用的最大容量 
}sqStack;

void InitStack(sqStack *s) //栈的初始化 
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if( !s->base )
	{
		exit(0);
		s->top = s->base + s->stackSize; //最开始，栈顶就是栈底
		s->stackSize = s->stackSize + STACKINCREMENT;
	}
	
	s->top= s->base; //最开始，栈顶就是栈底
	s->stackSize = STACK_INIT_SIZE;//容量赋值为100
}

void Push(sqStack *s, ElemType e) //入栈 
{
	if( s->top - s->base >= s->stackSize )//入栈前先进行判断是否存储空间已满 
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if( !s->base )
		{
			exit(0);
		}
		s->top = s->base + s->stackSize; //最开始，栈顶就是栈底
		s->stackSize = s->stackSize + STACKINCREMENT;
	}	
		*(s->top) = e;
		s->top++;
	
}		
void Pop(sqStack *s, ElemType *e) //出栈 
{
	if( s->top == s->base ){
		return;
	}
	
	*e = *--(s->top);
}
	
void DestoryStack(sqStack *s) //销毁栈 
{
	int i,len;
	len = s->stackSize;
	for(i=0;i<len;i++){
		free(s->base);
		s->base++;
	}
	s->base=s->top=NULL;
	s->stackSize=0;
}

int StackLen(sqStack s) //求栈的长度 
{
	return (s.top - s.base);//中间隔了多少元素差
	
}

int main()
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;
	
	InitStack(&s);
	
	printf("请输入二进制数，输入#表示结束！\n");
	scanf("%c", &c);
	
	while( c != '#')
	{
		Push(&s, c);
		scanf("%c", &c);
	}
	
	getchar();//把'\n'从缓冲区去掉 
	
	len = StackLen(s);
	printf("栈的当前容量是： %d\n",len);
	
	for( i=0; i < len ; i++)
	{
		Pop(&s, &c);
		sum = sum + (c-48) *pow(2, i);
	}
	
	printf("转化为十进制数是: %d",sum);
	return 0;
}

