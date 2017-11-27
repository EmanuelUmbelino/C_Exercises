#include <stdio.h>
#include <stdlib.h>
#include "PilhaDeLivros.h"

struct elemento
{
    Livro *liv;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct pilhaDeLivros
{
    Elemento *prim;
};

PilhaDeLivros *piCria(void)
{
    PilhaDeLivros *p = (PilhaDeLivros*)malloc(sizeof(PilhaDeLivros));
    if (p==NULL)
        exit(1);
    p->prim = NULL;
    return p;
}

void piPush(PilhaDeLivros *p, Livro *liv)
{
    Elemento *n = (Elemento*)malloc(sizeof(Elemento));
    if(n==NULL)
        exit(1);
    n->liv = (Livro*)malloc(sizeof(Livro));
    if(n->liv==NULL)
        exit(1);
    n->liv = liv;
    n->prox = p->prim;
    p->prim = n;
}

int piVazia(PilhaDeLivros *p)
{
    if(p->prim == NULL)
        return 1;
    return 0;
}

Livro *piPop(PilhaDeLivros *p)
{
    Elemento *t;
    Livro *v;
    if(piVazia(p))
        exit(1);
    t = p->prim;
    v = t->liv;
    p->prim = t->prox;
    free(t);
    return v;
}

void piLibera(PilhaDeLivros *p)
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

