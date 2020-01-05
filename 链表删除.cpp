#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int Data;
    ListNode *Next;
}ListNode;

ListNode *readlist();

ListNode *deletem(ListNode *l,int m);

void printlist(ListNode *l){
    ListNode *p=l;

    while(p){
        printf("%d ",p->Data);
        p=p->Next; 
    } 
    printf("\n");
}

int main()
{
    int m;
    ListNode *l=readlist();

    scanf("%d",&m);
    l=deletem(l,m);
    printlist(l);

    return 0;
}

ListNode *readlist(){
    int in;
    ListNode *h,*p,*q;

    /*����ͷ�ڵ�*/
    scanf("%d",&in);
    h=(ListNode *)malloc(sizeof(ListNode));
    h->Data=in;
    h->Next=NULL;
    p=h;

    /*��������*/
    scanf("%d",&in);
    while(in!=-1){
        q=(ListNode *)malloc(sizeof(ListNode));
        q->Data=in;
        q->Next=NULL;
        p->Next=q;
        p=q;
        scanf("%d",&in);
    } 
    p->Next=NULL;

    return h;
}

ListNode *deletem(ListNode *l,int m){
    ListNode *h,*p,*q;
    h=l;

    /*�ȱ�֤ͷ�ڵ㲻��m*/
    while(h->Data==m){
        p=h->Next;
        free(h);
        h=p;
    } 

    /*ɾ�����������Ľڵ�*/
    p=h;
    q=p->Next;
    while(q){
        if(q->Data==m){
            p->Next=q->Next;
            free(q);
            q=p->Next;
            continue;
        }
        else{
            p=q;
            q=q->Next;
        }
    }

    return h; 
}
