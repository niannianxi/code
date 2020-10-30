#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 100 //ջ��ʼ���Ĵ洢�ռ� 
#define STACKINCREMENT 10 //ջ��������ӿռ䣨ÿ������10���� 

typedef char ElemType;
typedef struct
{ 
	ElemType *base;//ջ�� 
	ElemType *top;//ջ�� 
	int stackSize;//ջ��ǰ��ʹ�õ�������� 
}sqStack;

void InitStack(sqStack *s) //ջ�ĳ�ʼ�� 
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if( !s->base )
	{
		exit(0);
		s->top = s->base + s->stackSize; //�ʼ��ջ������ջ��
		s->stackSize = s->stackSize + STACKINCREMENT;
	}
	
	s->top= s->base; //�ʼ��ջ������ջ��
	s->stackSize = STACK_INIT_SIZE;//������ֵΪ100
}

void Push(sqStack *s, ElemType e) //��ջ 
{
	if( s->top - s->base >= s->stackSize )//��ջǰ�Ƚ����ж��Ƿ�洢�ռ����� 
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if( !s->base )
		{
			exit(0);
		}
		s->top = s->base + s->stackSize; //�ʼ��ջ������ջ��
		s->stackSize = s->stackSize + STACKINCREMENT;
	}	
		*(s->top) = e;
		s->top++;
	
}		
void Pop(sqStack *s, ElemType *e) //��ջ 
{
	if( s->top == s->base ){
		return;
	}
	
	*e = *--(s->top);
}
	
void DestoryStack(sqStack *s) //����ջ 
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

int StackLen(sqStack s) //��ջ�ĳ��� 
{
	return (s.top - s.base);//�м���˶���Ԫ�ز�
	
}

int main()
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;
	
	InitStack(&s);
	
	printf("�������������������#��ʾ������\n");
	scanf("%c", &c);
	
	while( c != '#')
	{
		Push(&s, c);
		scanf("%c", &c);
	}
	
	getchar();//��'\n'�ӻ�����ȥ�� 
	
	len = StackLen(s);
	printf("ջ�ĵ�ǰ�����ǣ� %d\n",len);
	
	for( i=0; i < len ; i++)
	{
		Pop(&s, &c);
		sum = sum + (c-48) *pow(2, i);
	}
	
	printf("ת��Ϊʮ��������: %d",sum);
	return 0;
}

