#include<stdio.h>
#include<stdlib.h>
struct student
{
	long no;
	char name[20];
	char addr[30];
	struct student *next;
};
typedef struct student LIST;

LIST* create()
{
	LIST *h,*prev,*cur;
	int i,n;
	h=NULL;
	printf("������ڵ����");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(LIST *)malloc(sizeof(LIST));//��̬���ٽڵ�ռ�
		cur->next=NULL;
		if(h==NULL)
			h=cur;
		else
			prev->next=cur;
		scanf("%d %s %s",&cur->no,cur->name,cur->addr);
		prev=cur;
	}
	return h;
}
int print(LIST *h)
{
	LIST *p=h;
	while(p!=NULL)
	{
		printf("%d %s %s\n",p->no,p->name,p->addr);
		p=p->next;
	}
	return 0;	
}
int main()
{
	LIST *h;
	h=create();
	printf("ѧ�� ���� ��ַ");
	print(h);
	return 0;
}
