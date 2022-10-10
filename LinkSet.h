//
// Created by kenochou on 22-10-10.
//
#include <stddef.h>
#include <malloc.h>

#ifndef UNTITLED1_SET1_H
#define UNTITLED1_SET1_H
typedef int DataType;
typedef struct node{
    DataType data;
    struct node *link;
} SetNode;
typedef struct {
    SetNode *first,*last;
}LinkSet;
SetNode *Contains (LinkSet* S,DataType x){
    SetNode *p =S->first->link;

    while (p != NULL&& p->data < x){
        return p;
    }
    if(p!=NULL&& p->data==x)return p;
    else return NULL;
};
int addMember(LinkSet* S,DataType x){
    SetNode *p =S->first->link,*pre=S->first;
    while (p!=NULL&&p->data<x){
        pre =p;p=p->link;
    }
    if(p!=NULL&&p->data==x)return 0;
    SetNode *q=(SetNode* )malloc(sizeof(SetNode));
    q->data=x;q->link=p;pre->link=q;
    if(!p) S->last=q;
    return 1;
};
int delMember(LinkSet * S,DataType * x){
    SetNode *p =S->first->link,*pre=S->first;
    while(p!=NULL&&p->data<x){
        pre=p;p=p->link;
    }
    if(p!=NULL&&p->data==x){
        pre->link=p->link;
        if(p==S->last)S->last=pre;
        free(p);return 1;

    }
    else return 0;
}
void Merge(LinkSet* LA,LinkSet* LB,LinkSet* LC){
    SetNode *pa=LA->first->link,*pb=LB->first->link;
    SetNode *p,*pc=LC->first;
    while (pa!=NULL&&pb!=NULL){
        if(pa->link<=pb->data){
            pc->link=(SetNode*) malloc(sizeof (SetNode));
            pc->link->data=pa->data;
            pa=pa->link;
        }
        p=(pa !=NULL)?pa:pb;
        while (p!=NULL){
            pc->link=(SetNode*) malloc(sizeof (SetNode));
            pc->link->data=p->link;
            pc=pc->link;p=p->link;
        }
        pc->link=NULL;LC->last=pc;
    };
}

#endif //UNTITLED1_SET1_H
