//
// Created by kenochou on 22-10-10.
//
#include <stdlib.h>
#include <stdio.h>
#ifndef UNTITLED1_CIRCLIST_H
#define UNTITLED1_CIRCLIST_H
typedef int DataType;
typedef struct node{
    DataType data;
    struct node *link;
}CircNode,*CircList;
void createCircList(CircList* first,DataType A[],int n){
    first =(CircNode* ) malloc(sizeof (CircNode));
    CircNode *r =first,*s;
    for(int i=0;i<n;i++){
        s= (CircNode*) malloc(sizeof (CircNode));
        s->data=A[i];s->link=r->link;
        r->link=s;r=s;
    }
}
int Insert(CircNode* first,int i,DataType x){
    if(i<1)return  0;
    CircNode *p=first,*q;int  k=0;
    while (p->link!=first&&k<i-1){
        p=p->link;k++;
    }
    q=(CircNode*) malloc(sizeof(CircNode) );
    q->data=x;q->link;p->link=q;
    return 1;
}
int Remove(CircNode *first ,int i,DataType* x){
    if(i<1) return 0;
    CircNode *p =first,*q;int k=0;
    while(p->link==first&&k<i-1){
        p=p->link;k++;
    }
    if(p->link==first)return 0;
    q=p->link;
    p->link=q->link;
    x=q->data;free(q);
    return 1;
}
#endif //UNTITLED1_CIRCLIST_H
