#include "FilaDeEventos.h"
#include <stdio.h>
#include <stdlib.h>

struct lista
{
    Evento *ev;
    struct lista *prox;
};typedef struct lista Lista;

struct filaDeEventos
{
    Lista *ini;
    Lista *fim;
};

FilaDeEventos *fiCria(void)
{
    FilaDeEventos *f = (FilaDeEventos*)malloc(sizeof(FilaDeEventos));
    if(f == NULL)
        exit(1);
    f->ini = f->fim = NULL;
    return f;
}

void fiInsere(FilaDeEventos *f, Evento *ev)
{
    Lista *n = (Lista*)malloc(sizeof(Lista));
    if(n == NULL)
        exit(1);
    n->ev = (Evento*)malloc(sizeof(Evento));
    if(n->ev == NULL)
        exit(1);
    n->ev = ev;
    n->prox = NULL;
    if(f->fim != NULL)
        f->fim->prox = n;
    else f->ini = n;
    f->fim = n;
}

int fiVazia(FilaDeEventos *f)
{
    if(f->ini == NULL)
        return 1;
    return 0;
}

Evento *fiRetira(FilaDeEventos *f)
{
    Lista *t;
    Evento *ev;
    if(fiVazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }
    t = f->ini;
    ev = t->ev;
    f->ini = t->prox;
    if(f->ini == NULL)
        f->fim = NULL;
    free(t);
    return ev;
}


void fiLibera(FilaDeEventos *f)
{
    Lista *q = f->ini;
    while (q!=NULL)
    {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}
