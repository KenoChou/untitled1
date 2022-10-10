//
// Created by kenochou on 22-10-10.
//
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define initSize 30
#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
typedef int DataType;
typedef struct {
    DataType *data;
    int maxSize,n;
}SeqList;

void initList( SeqList* L ){
L->data=(DataType*) malloc(initSize*sizeof (DataType));
if(!L->data){printf("存储分配错误\n");exit(1);}
L->maxSize= initSize;L->n=0;
}
void clearList(SeqList* L){
    L->n=0;
}
int Length(SeqList* L){
    return L->n;
}
int Locate(SeqList*L,int i){
    if(i>=1&&i<=L->n) return i-1;
    else return -1;
}
int Search(SeqList* L,DataType x){
    for(int i=0;i<L->n;i++){
        if(L->data[i]==x)return i;
return -1;
    }
}
bool Insert (SeqList* L,int i,DataType* x){
    if(L->n==L->maxSize)return false;
    if(i<1||i>L->n+1) return false;
    for(int j=L->n;j>=i;j--) L->data[j]=L->data[j-1];
    L->data[i-1]=x;
    L->n++;
    return true;
};
int Remove(SeqList* L,int i,DataType* x){
    if(!L->n)return false;
    if(i<1||i>L->n)return false;
    x=L->data[i-1];
    for(int j=i;j<L->n;j++)L->data[j-1]=L->data[j];
    L->n--;
    return true;

}
void Merge(SeqList * LA,SeqList* LB)
{
    DataType x;
    int n = Length(LA),m= Length(LB),i,k;
    for(i=0;i<m;i++){
        x=LB->data[i];
        k= Search(LA,x);
        if(k==-1){
            Insert(LA,n,x);n++;
        }
    }

}
void Intersection(SeqList *LA,SeqList*LB){
    DataType x;
    int n= Length(LA),m= Length(LB),i,k;
    for(i=0;i<n;i++){
        x=LA->data[i];
        k= Search(LB,x);
        }
    };

#endif //UNTITLED1_LIST_H
