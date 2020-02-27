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
void welcome();//开始页面 
void end();//终止页面 
void gotoxy(int x, int y);//光标移动函数 
int signin();//登入密码函数 
int menu();//主菜单
int rewrite();//修改密码 
int add(LIST *h);//增加人物函数
int change(LIST *h);//修改人物数据函数 
LIST *createlink(LIST *h);//读取文件函数 
int del(LIST *h);//删除人物函数 
int sort(LIST *h);//排序函数（按人气值排序） 
void outlink(LIST *h);//输出人物 
int find(LIST *h);//查询人物信息 
void enter(LIST *h);//将修改信息存入文件 
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
    while(1)//无限循环 
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
void welcome()//登陆界面  
{  
    system("color b4");  
    	system("cls");
		printf("*---------------------------------------------------------------------------------------------------------------------*"); 
		printf("\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t         ***********************  欢迎来到魔道祖师动漫 >_<  *************************  \n"); 		
		printf("\n\n\n\n\n\n\n\n\n\n");
	    printf("*---------------------------------------------------------------------------------------------------------------------*");
		Sleep(3000);
}  
void gotoxy(int x, int y)//x,y分别代表列号，行号，以0开始计
{
    COORD coord = {x, y};   
    /*COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：

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
       	   printf("| 请输入你的动漫通行证号:                    |\n");
           printf("\t\t\t\t\t| 请输入你的动漫通行密码:                    |\n");
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
		printf("                               恭喜你登陆成功，欢迎来到专属于你的动漫世界");
		printf("\n\n\n\n\n\n\n\n\n\n");
	    printf("*-------------------------------------------------------------------------------------------------------------------*"); 
		Sleep(2000);
		system("cls");
		printf("请等待，页面跳转中..........");
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
		printf("                             >_< 动漫世界暂时无法开启，请稍候再来哦");
		printf("\n\n\n\n\n\n\n\n\n\n");
	    printf("*-------------------------------------------------------------------------------------------------------------------*"); 
		getch(); 
		exit(-1);
		}
		 
	  else
	  {
	printf("*-------------------------------------------------------------------------------------------------------------------*\n"); 
    printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t     啊哦，该账号或密码输入错误哦，请重新输入！\n");
	printf("\t\t\t     注意哦，你现在仅有%d次开启动漫世界的机会了！\n",j--);
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
        printf("*------------------------------欢迎来到专属于你的动漫世界-----------------------------*\n");
        gotoxy(20,10);
        printf("\t\t\t|-------------------------------------------------|\n");
        gotoxy(20,11);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,12);
        printf("\t\t\t|                  *使用说明                      |\n");
        gotoxy(20,13);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,14);
        printf("\t\t\t|-------------------------------------------------|\n");
        gotoxy(20,15);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,16);
        printf("\t\t\t|          0.修改密码                             |\n");
        gotoxy(20,17);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,18);
        printf("\t\t\t|          1.添加信息                             |\n");
        gotoxy(20,19);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,20);
        printf("\t\t\t|          2.修改动漫人物信息                     |\n");
        gotoxy(20,21);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,22);
        printf("\t\t\t|          3.删除你不喜欢的人物                   |\n");
        gotoxy(20,23);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,24);
        printf("\t\t\t|          4.动漫主要人物姓名及其人气值           |\n");
        gotoxy(20,25);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,26);
        printf("\t\t\t|          5.按照人气值排序重新生成榜单           |\n");
        gotoxy(20,27);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,28);
        printf("\t\t\t|          6.将修改的人物信息存入文件             |\n");
        gotoxy(20,29); 
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,30);
        printf("\t\t\t|          7.按序号或姓名查找人气值               |\n");
        gotoxy(20,31);
        printf("\t\t\t|                                                 |\n");
        gotoxy(20,32);
		printf("\t\t\t|          8.退出                                 |\n"); 
		gotoxy(20,33); 
		printf("\t\t\t|-------------------------------------------------|\n");
        printf("\t\t\t   请选择0-8：");
        scanf("%d",&n);
    	if(n<0||n>8)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t-------------------------------------------------------");
	    gotoxy(40,6);
	    printf("|     很抱歉你所选择的序号不在我们的选择范围之内>_<      |\n"); 
		printf("\t\t\t\t\t-------------------------------------------------------"); 
	}
}
int rewrite()
{
        printf("\n\n\n\n\n\n\t\t ");
        printf("*------------------------------动漫世界密码修改-----------------------------*");
        printf("\n\n\t         *请输入原密码：");
        printf("\n\t         *请输入新密码：");
        gotoxy(31,8);
        char b1[100],b2[100];
        scanf("%s",b1);
        gotoxy(31,9);
        scanf("%s",b2);
        if(strcmp(b1,b))
          {
            printf("\n\n\t       *原密码输入错误！请等待·五秒后重新输入。");
            Sleep(5000);
			system("cls");
			rewrite();
			return 0;
         }
         else
          {
          	strcpy(b,b2);
          	printf("密码修改成功");
          	signin();
          	return 0;
		  }
        return 0;
}//从文件中读取数据存入链表 
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
        printf("打开文件失败!");
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
	printf("\n\n\n\n\n\t\t\t\t\t*------------------------动漫人物增加平台------------------------*");
	printf("\n\t\t\t\t\t请选择你增加人物的序号："); 
	printf("\n\t\t\t\t\t(不要选择已经存在的序号哦>_<)");
	printf("\n\n\n\n\n\t\t\t\t\t*----------------------------------------------------------------*");
	gotoxy(63,6);
	cur=(LIST *)malloc(sizeof(LIST));
	cur->next=NULL;
	scanf("%d",&cur->a);	
	if(h==NULL)
	{
		gotoxy(40,8);
		printf("请输入你要增加的人物姓名：\n");
		printf("请输入你要增加的人物人气值：\n");
		gotoxy(66,8);
		scanf("%s",cur->name);
		
		scanf("%d",&cur->b);
		h=cur;
		h->next=NULL;
		printf("人物增加成功");
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
	    printf("该序号已经存在，请等待三秒后重新选择哦！");
	    Sleep(3000);
	    system("cls");
	    add(h);
	  }    
    }

     {
     	gotoxy(40,8);
		printf("请输入你要增加的人物姓名：\n");
		gotoxy(40,9);
		printf("请输入你要增加的人物人气值：\n");
		gotoxy(65,8);
		scanf("%s",cur->name);
		gotoxy(67,9);		
		scanf("%d",&cur->b);
    	p->next=cur;
    	cur->next=NULL;
    	gotoxy(40,10);
    	printf("人物信息添加成功");
		gotoxy(40,11);
		system("pause"); 
    }
  return 0;
} 
int change(LIST *h)
{
	int n,c,f,flag=1;
	char nam[50];
	printf("\n\n\n\n\n\t\t\t\t\t*------------------------动漫人物修改平台------------------------*");
	LIST *p;
	printf("\n\t\t\t\t\t请选择你要修改人物的序号："); 
	printf("\n\n\n\n\n\t\t\t\t\t*----------------------------------------------------------------s*");
    gotoxy(65,6);
	scanf("%d",&n);
//假设修改的是序号
	if(h==NULL)
	{
		gotoxy(40,7);
		printf("\n\t\t\t\t\t啊哦，已经不存在人物了，请你添加人物后再进行操作\n\t\t\t\t\t");
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
	     	printf("请输入您要修改的信息选项： ");
	     	gotoxy(40,8);
	     	printf("(1.姓名 2.人气值)");
			 gotoxy(65,7); 
	     	scanf("%d",&n);
	     	switch(n) 
	     	{
	     	case 1:
	     		gotoxy(40,9);
	     		printf("请输入您要修改的名字:");  
                scanf("%s",nam);
				system("cls");  
                printf("修改的名字为：%s\n",nam);  
                strcpy(p->name,nam);
                printf("修改名字成功！\n");
			    system("pause");
                break; 
			case 2:
				gotoxy(40,9);
				 printf("请输入您要修改的人气值：");  
                scanf("%d",&c); 
				system("cls"); 
                printf("修改的人气值为:%d\n",c);  
                p->b=c;
                printf("修改人气值成功！\n");
				system("pause"); 
				break;
			default :
			    gotoxy(40,9);  
                printf("请输入正确的选项\n");
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
	  printf("很抱歉，你所选择的序号不存在，请重新选择");
	  Sleep(1000);
	  system("cls");
	  change(h);
	 }
	   
}
int del(LIST *h)
{  
	int n;
	printf("\n\n\n\n\n\t\t\t\t\t*------------------------动漫人物删除平台------------------------*");
	printf("\n\t\t\t\t\t请选择你要删除人物的方式(1代表根据序号删除，2代表根据名字删除)："); 
	printf("\n\n\n\n\n\t\t\t\t\t*----------------------------------------------------------------s*");
	gotoxy(103,6);
	scanf("%d",&n);
	if(n==1)
	{
	 	printf("\t\t\t\t\t请输入你想删除的人物序号:\n\t\t\t\t\t(要存在该动漫人物序号才可删除哦！)");
	  int target;
	  gotoxy(65,7); 
	  scanf("%d",&target);
	  LIST *pre,*p;
	 if(h==NULL)
 	{
		printf("\n\t\t\t\t\t啊哦，已经不存在人物了，请你添加人物后再进行操作\n\t\t\t\t\t");
		system("pause");
	    add(h);//回到增加函数（目前未写） 
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
		printf("\n\t\t\t\t\t该动漫人物被成功删除\n\t\t\t\t\t");
		system("pause");
	}
	else 
	{
	 printf("\n\t\t\t\t\t不存在该序号哦,请重新输入哦>_<\n\t\t\t\t\t");
	 system("pause");
	 system("cls");
    }
	}
	else
	{
		char Name[20];
		printf("\t\t\t\t\t请输入你想删除的人物名字:\n\t\t\t\t\t(要存在该动漫人物名字才可删除哦！)");
		gotoxy(65,7);
		scanf("%s",Name);
		LIST *pre,*p;
	  if(h==NULL)
	 {
		printf("\n\t\t\t\t\t啊哦，已经不存在人物了，请你添加人物后再进行操作\n\t\t\t\t\t");
		//回到增加函数（目前未写） 
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
		printf("\n\t\t\t\t\t该动漫人物被成功删除\n\t\t\t\t\t");
		system("pause");
	}
	else 
	{
	 printf("\n\t\t\t\t\t不存在该名字哦,请重新输入哦>_<\n\t\t\t\t\t");
	 system("pause");
    }
	}
}
void outlink(LIST *h)
{
	
	printf("*---------------动漫主要人物----------------*\n"); 
    printf(" *序号*           *姓名*         *人气值*\n");
    int i=0; 
    LIST *p=h->next;
    system("color b0");
   while(p)
   {
       //输出链表节点数据到屏幕 
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
     LIST *temp,*i,*j;//暂存节点
	  temp=(LIST *)malloc(sizeof(LIST));
	  temp->next=NULL;
   if(p==NULL)
   {
    printf("\n\t\t\t\t\t啊哦，已经不存在人物了，请你添加人物后再进行操作\n\t\t\t\t\t");
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
 
void enter(LIST *h)//将修改信息存入文件 
{
	FILE *fp=fopen("cql.txt","w");
	LIST *p=h->next;
	if(fp==NULL)// 以可写的方式打开当前目录下的.txt  
    {  
        printf("不能打开此文件，请按任意键退出\n");  
        exit(1);  
    }  
    while(p)
    {
    	fprintf(fp,"%d %s %d\n",p->a,p->name,p->b);
    	p=p->next;
	}
	printf("动漫人物已成功被保存，请返回文件查看\n"); 
	system("pause");
	fclose(fp); 
}
int find(LIST *h)
{
	int flag;
	int nu;
	char nam[50];
    system("color b1");  
    printf("1.按序号查询：\n");
    printf("2.按姓名查询：\n");
    printf("请输入查询方式：");
    scanf("%d",&flag); 
    if(flag==1){
        printf("请输入该人物序号："); 
        scanf("%d",&nu);  
        //判断  
       LIST *q=h;  
        while(q!=NULL )  
        {  
            if(q->a==nu)  
            {  
			    printf("序号：%d\n",q->a);
                printf("姓名：%s\n",q->name);  
                printf("人气值：%d\n",q->b);
                system("pause");   
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            {
			 printf("该人物不存在\n"); 
			 system("pause");
			} 
    }
	else
	{
        printf("请输入该人物姓名：");
        scanf("%s",nam);  
        LIST *q=h;  
        while(q!=NULL )  
        {  
            if(strcmp(q->name,nam)==0)  
            {  
                printf("序号：%d\n",q->a);
                printf("姓名：%s\n",q->name);  
                printf("人气值：%d\n",q->b);  
				system("pause");    
                break;  
            }  
             q=q->next;  
        }  
        if(q==NULL)  
            {
			 printf("该人物不存在\n");
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
    puts("---*-----感谢您的使用！按任意键结束本次动漫世界的使用-----*---");
    gotoxy(30,18);
    puts("---------------------------------------------------------------");
    getch();
    system("cls"); 
    exit(1);
} 



    
 

