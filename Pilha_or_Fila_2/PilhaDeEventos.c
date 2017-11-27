#include <stdio.h>
#include <stdlib.h>
#include "PilhaDeEventos.h"

struct elemento
{
    Evento *ev;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct pilhaDeEventos
{
    Elemento *prim;
};

PilhaDeEventos *piCria(void)
{
    PilhaDeEventos *p = (PilhaDeEventos*)malloc(sizeof(PilhaDeEventos));
    if (p==NULL)
        exit(1);
    p->prim = NULL;
    return p;
}

void piPush(PilhaDeEventos *p, Evento *ev)
{
    Elemento *n = (Elemento*)malloc(sizeof(Elemento));
    if(n==NULL)
        exit(1);
    n->ev = (Evento*)malloc(sizeof(Evento));
    if(n->ev==NULL)
        exit(1);
    n->ev = ev;
    n->prox = p->prim;
    p->prim = n;
}

int piVazia(PilhaDeEventos *p)
{
    if(p->prim == NULL)
        return 1;
    return 0;
}


Evento *piPop(PilhaDeEventos *p)
{
    Elemento *t;
    Evento *v;
    if(piVazia(p))
        exit(1);
    t = p->prim;
    v = t->ev;
    p->prim = t->prox;
    free(t);
    return v;
}

void piLibera(PilhaDeEventos *p)
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

