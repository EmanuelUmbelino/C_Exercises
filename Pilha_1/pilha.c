#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct elemento
{
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct pilha
{
    Elemento *prim;
};

Pilha *piCria(void)
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p==NULL)
        exit(1);
    p->prim = NULL;
    return p;
}

void piPush(Pilha *p, int digito)
{
    Elemento *n = (Elemento*)malloc(sizeof(Elemento));
    if(n==NULL)
        exit(1);
    n->info = digito;
    n->prox = p->prim;
    p->prim = n;
}

int piEhVazia(Pilha *p)
{
    if(p->prim == NULL)
        return 1;
    return 0;
}

int piPop(Pilha *p)
{
    Elemento *t;
    float v;
    if(piEhVazia(p))
        exit(1);
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void piLibera(Pilha *p)
{
    Elemento *t, *q = p->prim;
    while (q!=NULL)
    {
        t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

