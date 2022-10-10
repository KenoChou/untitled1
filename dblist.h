//
// Created by kenochou on 22-10-10.
//
#include <stdlib.h>
#include<stdio.h>
#define maxSize 30
#ifndef UNTITLED1_DBLIST_H
#define UNTITLED1_DBLIST_H
typedef int DataType;
typedef struct node{
    DataType data;
    int freq;
    struct node *rLink,*lLink;
}DblNode,*DblList;
void createListR(DblList* first,DataType A[],int m){
    first=(DblNode*) malloc(sizeof (DblNode));
    DblNode *s,*q,*r=first;
  for(int i=0;i<m;i++){
      s=(DblNode*) malloc(sizeof (DblNode));
      s->data=A[i];s->freq=0;
      q=r->rLink;s->lLink=r;q->lLink=s;
      r->rLink=s;s->rLink=q;r=s;
  }
}
void printList (DblList first ,int d){
    DblList p;
    p=(d==0)?first->lLink:first->rLink;
    while(p!=first) {
        printf("%d",p->data);
        p=(d==0)?p->lLink: p->rLink;
        if(p!=first)printf(" ");
    }
    printf("\n");
}
DblNode *Search(DblList first,DataType x,int d){
    DblNode *p = (d==0) ?  first->lLink:first->rLink;
    while (p!=first&&p->data!=x)
        p=(d==0)?p->lLink:p->rLink;
    return (p!=first)?p:NULL;

};
DblNode *Locate(DblList first,int i,int d){
  if(i<0) return NULL;
    if(i==0) return first;
DblNode *p=(d==0)?first->rLink:first->lLink;
for(int j=1;j<i;j++)
    if(p==first)break;
    else p=(d==0)? p->rLink:p->rLink;
    return (p!=first)?p:NULL;
};
int Insert(DblList* first,int i,DataType x,int d){
    DblNode *p = Locate(first,i-1,d);
    if(p==NULL) return 0;
    DblNode  *s =(DblNode*) malloc(sizeof (DblNode));
    s->data=x;
    if(d==0){
        s->lLink=p->rLink;p->lLink=s;
        s->lLink->rLink=s;s->rLink=p;

    }
    else{
        s->rLink=p->rLink;p->rLink=s;
        s->rLink->lLink=s;s->lLink=p;
    }
    return 1;
};
int Remove(DblList* first,int i,DataType* x,int d){
    DblNode  *p = Locate(first,i,d);
    if(p==NULL) return 0;
    p->rLink->lLink=p->lLink;
    p->lLink->rLink=p->rLink;
    x=p->data;free(p);
    return 1;
};
#endif //UNTITLED1_DBLIST_H
