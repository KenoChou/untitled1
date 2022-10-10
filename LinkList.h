//
// Created by kenochou on 22-10-10.
//
#include<stdio.h>
#include<stdlib.h>
#ifndef UNTITLED1_LINKLIST_H
#define UNTITLED1_LINKLIST_H
typedef int DataType;
typedef struct node{
    DataType data;
    struct node *link;
}LinkNode,LinkList;;
int Remove(LinkNode* first,int i,DataType* x){
    LinkNode *q,*p;int k;
    if(i<=1){q=first;first=first->link;}
    else{
        p=first;k=1;
        while (p==NULL&&k<i-1){
            p=p->link;k++;
        }
        if(p==NULL||p->link==NULL){
            printf("无效的删除的位置!\n");return 0;
        }
        q=p->link;

    }
    x=q->data;free(q);
    return 1;
}
void initList(LinkList* first){
    first=(LinkNode* ) malloc(sizeof(LinkNode));
    if(!first){ printf("存储分配错误\n");
        exit(1);}
    first->link=NULL;
};
void clearList(LinkList* first){
    LinkNode *q;
    while (first->link!=NULL){
        q= first->link;
        first->link=q->link;
        free(q);
    }
};
int Length(LinkList* first){
    LinkNode *p =first->link;int count =0;
    while(p!=NULL){
        p=p->link;count++;
    }
    return  count;
};
LinkNode  *Search(LinkNode* first,DataType x){
    LinkNode *p =first->link;
    while (p!=NULL&& p->data!=x)p=p->link;
    return p;
};
LinkNode *Locate(LinkNode* first,int i){
    if(i<0)return  NULL;
    LinkNode  *p=first;int k=0;
    while(p!=NULL&&k<i){
        p=p->link;k++;
    }
    return p;
};
int Insert(LinkList* first,int i,DataType x){
    LinkNode *p=Locate(first,i-1);
if(p==NULL)return 0;
    LinkNode *s=(LinkNode*) malloc(sizeof (LinkNode));
    if(s==NULL){
        printf("存储分配方式！\n");
        exit(1);}
        s->data=x;
        s->link=p->link;p->link=s;
    return 1;
    };
void printList(LinkNode *first){
    if(first==NULL) return;
    printf("%d\n",first->data);
    printList(first->link);
}
void creatListRear(LinkList* last ,DataType endTag){
    DataType val; scanf("%d",&val);
    if(val==endTag) last =NULL;
    else {
        last = (LinkNode*) malloc(sizeof (LinkList));
        if(! last ){ printf("存储分配错误\n");
            exit(1);}
 last -> data =val;
        creatListRear(last->link,endTag);
    }
};
void creatListFront(LinkList* first,DataType endTag){
    DataType val;
    scanf("%d",&val);
    if(val==endTag)return;
    LinkNode *s =(LinkNode*)malloc(sizeof (LinkList));
    if(!s){ printf("存储分配错误\n");
        exit(1);}
    s->data=val;
    s->link=first->link;first->link=s;
    creatListFront(first,endTag);
}
void printList_iter(LinkNode *first){
    while (first ->link != NULL){
        printf("%d",first->link->data);
        first=first->data;
    }
    printf("\n");
}
#endif //UNTITLED1_LINKLIST_H
