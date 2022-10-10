//
// Created by kenochou on 22-10-10.
//
#include<stdlib.h>
#include <stdio.h>
#include<math.h>
#include <stdbool.h>

#ifndef UNTITLED1_POLYNOMIAL_H
#define UNTITLED1_POLYNOMIAL_H
typedef  struct  node{
    double coef;
    int exp;
    struct  node *link;
}Term,*Polynomial;
void Input(Polynomial Pl,double C[],int E[],int n){
    Polynomial newTerm,p,pre;int i;
    for(i=0;i<n;i++){
        p=Pl->link;pre=Pl;
        while (p!=NULL&&p->exp>E[i]){
            pre=p;p=p->link;
        }
if(p!=NULL&&p->exp>E[i]){
    printf("已有与指数%d相等的项，输入作废\n",E[i]);
}else{
    newTerm=(Term*) malloc(sizeof (Term));
    newTerm->coef=C[i];newTerm->exp=E[i];
    newTerm->link=p;pre->link=newTerm;
}
    }
}
void prinyPoly(Polynomial PL){
    Polynomial p=PL->link;
    printf("the polynomial is:\n");
    bool h=1;
    while (p!=NULL){
        if(h==1){
        if(p->coef<0)printf("-");
        h=0;
    }else{
            if(p->coef>0)printf("+");
            else printf("-");
        }
        if(p->exp==0|| fabs(p->coef)!=1)
            printf("%g,", fabs(p->coef));
        switch (p->exp) {
            case 0:
                break;
            case 1:
                printf("X");
                break;
            default:
                printf("X^%d",p->exp);

        }
        p=p->link;
    }
    printf("\n");
}
void AddPolynomial(Polynomial A,Polynomial B,Polynomial C){
    Term *pa,*pb,*p,*pc,*s;double temp;
    pc=C;
    pa=A->link;pb=B->link;
    while (pa!=NULL&&pb!=NULL)
        if(pa->exp==pb->exp){
            temp=pa->coef+pb->coef;
            if(fabs(temp)>0.001){
                s=(Term*) malloc(sizeof (Term));
                pc->link=s;pc=pc->link;
                pc->coef=temp;pc->exp=pa->exp;
            }
            pa=pa->link;pb->link;
        }else{
            s=(Term*) malloc(sizeof (Term));
            if(pa->exp<pb->exp){
                pc->link=s;pc=pc->link;
                pc->coef=pa->coef;pc->exp=pa->exp;
                pa=pa->link;
            }
            else{
                pc->link=s;pc=pc->link;
                pc->coef=pb->coef;pc->exp=pb->exp;
                pb=pb->link;
            }
        }
    p=(pa!=NULL)?pa:pb;
    while (p!=NULL){
        pc->link=(Term*) malloc(sizeof (Term));
        pc=pc->link;pc->coef=p->coef;pc->exp=p->exp;
        p=p->link;
    }
    pc->link=NULL;
}
void MultPolynomial(Polynomial A,Polynomial B,Polynomial C  ){
    Term *pa,*pb,*t,pr,*p,*q;int k;
    pa=A->link;t=C;
    while (pa!=NULL){
        pb =B->link;
        while (pb!=NULL&&p->exp>k){
            k=pa->exp+pb->exp;
            pr=*t;p=pr.link;
        }
        if(p==NULL||p->exp<k){
            q=(Term*) malloc(sizeof (Term));
            q->coef=pa->coef*pb->coef;
            pr.link=q;q->link=p;
        }
        else{
            p->coef+=pa->coef*pb->coef;
            if(fabs(p->coef)<0.001){
                pr.link=p->link;free(p);
            }
            pb=pb->link;
        }
        pa=pa->link;t=t->link;
    }
}
#endif //UNTITLED1_POLYNOMIAL_H
