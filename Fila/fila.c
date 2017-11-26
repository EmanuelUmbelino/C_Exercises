#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int v;
    struct lista *prox;
};typedef struct lista Lista;

struct fila
{
    Lista *ini;
    Lista *fim;
};

Fila *cria(void)
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void insere(Fila *f, int v)
{
    Lista *n = (Lista*)malloc(sizeof(Lista));
    n->v = v;
    n->prox = NULL;
    if(f->fim != NULL)
        f->fim->prox = n;
    else f->ini = n;
    f->fim = n;
}

int vazia(Fila *f)
{
    if(f->ini == NULL)
        return 1;
    return 0;
}

int retira(Fila *f)
{
    Lista *t;
    float v;
    if(vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }
    t = f->ini;
    v = t->v;
    f->ini = t->prox;
    if(f->ini == NULL)
        f->fim = NULL;
    free(t);
    return v;
}


void libera(Fila *f)
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

void imprime_fila(Fila *f)
{
    Lista *t;
    printf("\n");
    for (t=f->ini;t!=NULL;t=t->prox)
    {
        printf("%d  ",t->v);
    }
}
