#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
struct actor1
{
	int a;
	char name[20];
	int b;
	struct actor1 *next;
};
typedef struct actor1 LIST;
int main();
int menu();
void welcome();//��ʼҳ�� 
void end();//��ֹҳ�� 
void gotoxy(int x, int y);//����ƶ����� 
int signin();//�������뺯�� 
int menu();//���˵�
int rewrite();//�޸����� 
int add(LIST *h);//�������ﺯ��
int change(LIST *h);//�޸��������ݺ��� 
LIST *createlink(LIST *h);//��ȡ�ļ����� 
int del(LIST *h);//ɾ�����ﺯ�� 
int sort(LIST *h);//��������������ֵ���� 
void outlink(LIST *h);//������� 
int find(LIST *h);//��ѯ������Ϣ 
void enter(LIST *h);//���޸���Ϣ�����ļ� 
char a[]="niannianxi";
char b[]="fenghui";
int main()
{
	system("cls"); 
	welcome();
    system("cls");
    signin();
    LIST *h;
    h=createlink(h);
    while(1)//����ѭ�� 
	{
		switch(menu())
		{
			case 0:
				system("cls");
				rewrite();
				break;
		    case 1:
			    system("cls");
				add(h); 
				break;
			case 2:
				system("cls");
				change(h);
				break;
		    case 3:
				system("cls");
				del(h);
				break;
			case 4:
			   system("cls");
			   outlink(h);
			   break;
		    case 5:
			    system("cls");
			    sort(h);
			    break;
			case 6:
				system("cls");
				enter(h);
				break;
			case 7:
				system("cls");
				find(h);
				break;
			case 8:
			   system("cls");
			   end();
			   break; 
		}
	 } 
	return 0;
}
void welcome()//��½����  
{  
    system("color b4");  
    	system("cls");
		printf("*---------------------------------------------------------------------------------------------------------------------*"); 
		printf("\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t         ***********************  ��ӭ����ħ����ʦ���� >_<  *************************  \n"); 		
		printf("\n\n\n\n\n\n\n\n\n\n");
	    printf("*---------------------------------------------------------------------------------------------------------------------*");
		Sleep(3000);
}  
void gotoxy(int x, int y)//x,y�ֱ�����кţ��кţ���0��ʼ��
{
    COORD coord = {x, y};   
    /*COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ�䶨��Ϊ��

    typedef struct _COORD {

    SHORT X; // horizontal coordinate

    SHORT Y; // vertical coordinate
    } COORD;*/

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int signin()
{   

    char b1[20],b2[20];
	int j=2; 
			for(int i=0;i<3;i++)
  {
  	       system("cls");
		   printf("\n\n\n\n\n\t\t\t\t\t*--------------------------------------------*");
	       gotoxy(40,6);
       	   printf("| ��������Ķ���ͨ��֤��:                    |\n");
           printf("\t\t\t\t\t| ��������Ķ���ͨ������:                    |\n");
           printf("\t\t\t\t\t*--------------------------------------------*");
	       gotoxy(65,6);
	       scanf("%s",b1);
	       gotoxy(65,7);
           scanf("%s",b2);
           if(strcmp(a,b1)==0&&strcmp(b,b2)==0)
	{
		system("cls");
		printf("*-------------------------------------------------------------------------------------------------------------------*"); 
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("                               ��ϲ���½�ɹ�����ӭ����ר������Ķ�������");
		printf("\n\n\n\n\n\n\n\n\n\n");
	    printf("*-------------------------------------------------------------------------------------------------------------------*"); 
		Sleep(2000);
		system("cls");
		printf("��ȴ���ҳ����ת��..........");
		Sleep(3000);
		return menu();
	}
	else 
	{
		
		system("cls");	 
		if(j==0) 
		{
		printf("*-------------------------------------------------------------------------------------------------------------------*"); 
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("                             >_< ����������ʱ�޷����������Ժ�����Ŷ");
		printf("\n\n\n\n\n\n\n\n\n\n");
	    printf("*-------------------------------------------------------------------------------------------------------------------*"); 
		getch(); 
		exit(-1);
		}
		 
	  else
	  {
	printf("*-------------------------------------------------------------------------------------------------------------------*\n"); 
    printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t     ��Ŷ�����˺Ż������������Ŷ�����������룡\n");
	printf("\t\t\t     ע��Ŷ�������ڽ���%d�ο�����������Ļ����ˣ�\n",j--);
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("*-------------------------------------------------------------------------------------------------------------------*"); 
	Sleep(5000);
	  }		
	}
  }
} 
int menu()
{
	    system("color b4");
        int n;
        system("cls");
        gotoxy(25,6);
        printf("*------------------------------��ӭ����ר������Ķ�������-----------------------------*\n");
        gotoxy(20,10);
        printf("\t\t\t|-------------------------------------------------|\n");
        gotoxy(20,11);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,12);
        printf("\t\t\t|                  *ʹ��˵��                      |\n");
        gotoxy(20,13);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,14);
        printf("\t\t\t|-------------------------------------------------|\n");
        gotoxy(20,15);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,16);
        printf("\t\t\t|          0.�޸�����                             |\n");
        gotoxy(20,17);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,18);
        printf("\t\t\t|          1.�����Ϣ                             |\n");
        gotoxy(20,19);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,20);
        printf("\t\t\t|          2.�޸Ķ���������Ϣ                     |\n");
        gotoxy(20,21);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,22);
        printf("\t\t\t|          3.ɾ���㲻ϲ��������                   |\n");
        gotoxy(20,23);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,24);
        printf("\t\t\t|          4.������Ҫ����������������ֵ           |\n");
        gotoxy(20,25);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,26);
        printf("\t\t\t|          5.��������ֵ�����������ɰ�           |\n");
        gotoxy(20,27);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,28);
        printf("\t\t\t|          6.���޸ĵ�������Ϣ�����ļ�             |\n");
        gotoxy(20,29); 
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,30);
        printf("\t\t\t|          7.����Ż�������������ֵ               |\n");
        gotoxy(20,31);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,32);
		printf("\t\t\t|          8.�˳�                                 |\n"); 
		gotoxy(20,33); 
		printf("\t\t\t|-------------------------------------------------|\n");
        printf("\t\t\t   ��ѡ��0-8��");
        scanf("%d",&n);
    	if(n<0||n>8)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t-------------------------------------------------------");
	    gotoxy(40,6);
	    printf("|     �ܱ�Ǹ����ѡ�����Ų������ǵ�ѡ��Χ֮��>_<      |\n"); 
		printf("\t\t\t\t\t-------------------------------------------------------"); 
	}
}
int rewrite()
{
        printf("\n\n\n\n\n\n\t\t ");
        printf("*------------------------------�������������޸�-----------------------------*");
        printf("\n\n\t         *������ԭ���룺");
        printf("\n\t         *�����������룺");
        gotoxy(31,8);
        char b1[100],b2[100];
        scanf("%s",b1);
        gotoxy(31,9);
        scanf("%s",b2);
        if(strcmp(b1,b))
          {
            printf("\n\n\t       *ԭ�������������ȴ���������������롣");
            Sleep(5000);
			system("cls");
			rewrite();
			return 0;
         }
         else
          {
          	strcpy(b,b2);
          	printf("�����޸ĳɹ�");
          	signin();
          	return 0;
		  }
        return 0;
}//���ļ��ж�ȡ���ݴ������� 
LIST *createlink(LIST *h)
{
    h =(LIST*)malloc(sizeof(LIST));
    char Name[100];
    int c;
    int d;
    LIST *p;
    LIST *q;
    p=q=h; 
    FILE * r= fopen("cql.c","r");
    if(r==NULL)
    {
        printf("���ļ�ʧ��!");
        return NULL; 
    }
     
    while(fscanf(r,"%d %s %d",&c,Name,&d)!=EOF)
    {  
       q = (LIST*)malloc(sizeof(LIST));
       q->a=c;
       q->b=d;
       strcpy(q->name,Name);
       p->next=q;
       p=q;//p=p->next;
    }
    p->next=NULL;
    fclose(r); 
    return h;
}
int add(LIST *h)
{
	int n;
	LIST *p,*pre,*cur;
	printf("\n\n\n\n\n\t\t\t\t\t*------------------------������������ƽ̨------------------------*");
	printf("\n\t\t\t\t\t��ѡ���������������ţ�"); 
	printf("\n\t\t\t\t\t(��Ҫѡ���Ѿ����ڵ����Ŷ>_<)");
	printf("\n\n\n\n\n\t\t\t\t\t*----------------------------------------------------------------*");
	gotoxy(63,6);
	cur=(LIST *)malloc(sizeof(LIST));
	cur->next=NULL;
	scanf("%d",&cur->a);	
	if(h==NULL)
	{
		gotoxy(40,8);
		printf("��������Ҫ���ӵ�����������\n");
		printf("��������Ҫ���ӵ���������ֵ��\n");
		gotoxy(66,8);
		scanf("%s",cur->name);
		
		scanf("%d",&cur->b);
		h=cur;
		h->next=NULL;
		printf("�������ӳɹ�");
		system("pause");
		main(); 
		return 0;
	}
	p=h;
    { 
	    while((p->next!=NULL)&&(p->a!=cur->a)) 
	  {	
	      pre=p;
		  p=p->next;
      }
        if((p->a)==(cur->a))
      {
      	gotoxy(40,8);
	    printf("������Ѿ����ڣ���ȴ����������ѡ��Ŷ��");
	    Sleep(3000);
	    system("cls");
	    add(h);
	  }    
    }

     {
     	gotoxy(40,8);
		printf("��������Ҫ���ӵ�����������\n");
		gotoxy(40,9);
		printf("��������Ҫ���ӵ���������ֵ��\n");
		gotoxy(65,8);
		scanf("%s",cur->name);
		gotoxy(67,9);		
		scanf("%d",&cur->b);
    	p->next=cur;
    	cur->next=NULL;
    	gotoxy(40,10);
    	printf("������Ϣ��ӳɹ�");
		gotoxy(40,11);
		system("pause"); 
    }
  return 0;
} 
int change(LIST *h)
{
	int n,c,f,flag=1;
	char nam[50];
	printf("\n\n\n\n\n\t\t\t\t\t*------------------------���������޸�ƽ̨------------------------*");
	LIST *p;
	printf("\n\t\t\t\t\t��ѡ����Ҫ�޸��������ţ�"); 
	printf("\n\n\n\n\n\t\t\t\t\t*----------------------------------------------------------------s*");
    gotoxy(65,6);
	scanf("%d",&n);
//�����޸ĵ������
	if(h==NULL)
	{
		gotoxy(40,7);
		printf("\n\t\t\t\t\t��Ŷ���Ѿ������������ˣ��������������ٽ��в���\n\t\t\t\t\t");
		system("pause");
		add(h);
	}
	  p=h;
	    while(p!=NULL)
	  {
	     if(p->a==n)
	     {
	     	flag=0;
	     	gotoxy(40,7);
	     	printf("��������Ҫ�޸ĵ���Ϣѡ� ");
	     	gotoxy(40,8);
	     	printf("(1.���� 2.����ֵ)");
			 gotoxy(65,7); 
	     	scanf("%d",&n);
	     	switch(n) 
	     	{
	     	case 1:
	     		gotoxy(40,9);
	     		printf("��������Ҫ�޸ĵ�����:");  
                scanf("%s",nam);
				system("cls");  
                printf("�޸ĵ�����Ϊ��%s\n",nam);  
                strcpy(p->name,nam);
                printf("�޸����ֳɹ���\n");
			    system("pause");
                break; 
			case 2:
				gotoxy(40,9);
				 printf("��������Ҫ�޸ĵ�����ֵ��");  
                scanf("%d",&c); 
				system("cls"); 
                printf("�޸ĵ�����ֵΪ:%d\n",c);  
                p->b=c;
                printf("�޸�����ֵ�ɹ���\n");
				system("pause"); 
				break;
			default :
			    gotoxy(40,9);  
                printf("��������ȷ��ѡ��\n");
                gotoxy(40,10);
				system("pause"); 
                break;   
			}
			if(flag==0)	
			break;     	 
		 }
		 p=p->next;
	  }	 
	 if(flag)
	 {
	  gotoxy(40,9);
	  printf("�ܱ�Ǹ������ѡ�����Ų����ڣ�������ѡ��");
	  Sleep(1000);
	  system("cls");
	  change(h);
	 }
	   
}
int del(LIST *h)
{  
	int n;
	printf("\n\n\n\n\n\t\t\t\t\t*------------------------��������ɾ��ƽ̨------------------------*");
	printf("\n\t\t\t\t\t��ѡ����Ҫɾ������ķ�ʽ(1����������ɾ����2�����������ɾ��)��"); 
	printf("\n\n\n\n\n\t\t\t\t\t*----------------------------------------------------------------s*");
	gotoxy(103,6);
	scanf("%d",&n);
	if(n==1)
	{
	 	printf("\t\t\t\t\t����������ɾ�����������:\n\t\t\t\t\t(Ҫ���ڸö���������Ųſ�ɾ��Ŷ��)");
	  int target;
	  gotoxy(65,7); 
	  scanf("%d",&target);
	  LIST *pre,*p;
	 if(h==NULL)
 	{
		printf("\n\t\t\t\t\t��Ŷ���Ѿ������������ˣ��������������ٽ��в���\n\t\t\t\t\t");
		system("pause");
	    add(h);//�ص����Ӻ�����Ŀǰδд�� 
	}
	p=h;
	while((p->a!=target)&&(p->next!=NULL))
	{
		pre=p;
		p=p->next;
	}
	if(p->a==target)
	{
		if(p==h)
		h=p->next;
		else
		pre->next=p->next;
		free(p);
		printf("\n\t\t\t\t\t�ö������ﱻ�ɹ�ɾ��\n\t\t\t\t\t");
		system("pause");
	}
	else 
	{
	 printf("\n\t\t\t\t\t�����ڸ����Ŷ,����������Ŷ>_<\n\t\t\t\t\t");
	 system("pause");
	 system("cls");
    }
	}
	else
	{
		char Name[20];
		printf("\t\t\t\t\t����������ɾ������������:\n\t\t\t\t\t(Ҫ���ڸö����������ֲſ�ɾ��Ŷ��)");
		gotoxy(65,7);
		scanf("%s",Name);
		LIST *pre,*p;
	  if(h==NULL)
	 {
		printf("\n\t\t\t\t\t��Ŷ���Ѿ������������ˣ��������������ٽ��в���\n\t\t\t\t\t");
		//�ص����Ӻ�����Ŀǰδд�� 
		return 0; 
	 }
	p=h;
	while(strcmp(Name,p->name)!=0&&(p->next!=NULL))
	{
		pre=p;
		p=p->next;
	}
	if(strcmp(Name,p->name)==0)
	{
		if(p==h)
		h=p->next;
		else
		pre->next=p->next;
		free(p);
		printf("\n\t\t\t\t\t�ö������ﱻ�ɹ�ɾ��\n\t\t\t\t\t");
		system("pause");
	}
	else 
	{
	 printf("\n\t\t\t\t\t�����ڸ�����Ŷ,����������Ŷ>_<\n\t\t\t\t\t");
	 system("pause");
    }
	}
}
void outlink(LIST *h)
{
	
	printf("*---------------������Ҫ����----------------*\n"); 
    printf(" *���*           *����*         *����ֵ*\n");
    int i=0; 
    LIST *p=h->next;
    system("color b0");
   while(p)
   {
       //�������ڵ����ݵ���Ļ 
       printf("%4d\t\t   %s\t",p->a,p->name);
       if(strlen(p->name)<=4)
       printf("\t");
       printf("  %06d\n\n",p->b);
       p=p->next;         
   }  
   system("pause");   
}
int sort(LIST *h)
{
	system("color b9");
    LIST *p=h;
     int f=1;
     LIST *temp,*i,*j;//�ݴ�ڵ�
	  temp=(LIST *)malloc(sizeof(LIST));
	  temp->next=NULL;
   if(p==NULL)
   {
    printf("\n\t\t\t\t\t��Ŷ���Ѿ������������ˣ��������������ٽ��в���\n\t\t\t\t\t");
    add(h);
   } 
   for(i=p->next;i!=NULL;i=i->next)
     {
	   for(j=i->next;j!=NULL;j=j->next)
      {
      	if(i->b<j->b)
      	{
      		temp->b=i->b;
      		strcpy(temp->name,i->name);
      		i->b=j->b;
      		strcpy(i->name,j->name);
      		j->b=temp->b;
      		strcpy(j->name,temp->name);
		}
		if(j->next==NULL)
		 break;
	  }
	  i->a=f;
	  f++;
	}
	outlink(h);
}
 
void enter(LIST *h)//���޸���Ϣ�����ļ� 
{
	FILE *fp=fopen("cql.txt","w");
	LIST *p=h->next;
	if(fp==NULL)// �Կ�д�ķ�ʽ�򿪵�ǰĿ¼�µ�.txt  
    {  
        printf("���ܴ򿪴��ļ����밴������˳�\n");  
        exit(1);  
    }  
    while(p)
    {
    	fprintf(fp,"%d %s %d\n",p->a,p->name,p->b);
    	p=p->next;
	}
	printf("���������ѳɹ������棬�뷵���ļ��鿴\n"); 
	system("pause");
	fclose(fp); 
}
int find(LIST *h)
{
	int flag;
	int nu;
	char nam[50];
    system("color b1");  
    printf("1.����Ų�ѯ��\n");
    printf("2.��������ѯ��\n");
    printf("�������ѯ��ʽ��");
    scanf("%d",&flag); 
    if(flag==1){
        printf("�������������ţ�"); 
        scanf("%d",&nu);  
        //�ж�  
       LIST *q=h;  
        while(q!=NULL )  
        {  
            if(q->a==nu)  
            {  
			    printf("��ţ�%d\n",q->a);
                printf("������%s\n",q->name);  
                printf("����ֵ��%d\n",q->b);
                system("pause");   
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            {
			 printf("�����ﲻ����\n"); 
			 system("pause");
			} 
    }
	else
	{
        printf("�����������������");
        scanf("%s",nam);  
        LIST *q=h;  
        while(q!=NULL )  
        {  
            if(strcmp(q->name,nam)==0)  
            {  
                printf("��ţ�%d\n",q->a);
                printf("������%s\n",q->name);  
                printf("����ֵ��%d\n",q->b);  
				system("pause");    
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            {
			 printf("�����ﲻ����\n");
			 system("pause"); 
			} 
    }
} 
void end()
{
    system("cls");
    gotoxy(30,6);
    puts("---------------------------------------------------------------");
    gotoxy(30,12);
    puts("---*-----��л����ʹ�ã���������������ζ��������ʹ��-----*---");
    gotoxy(30,18);
    puts("---------------------------------------------------------------");
    getch();
    system("cls"); 
    exit(1);
} 



    
 

