#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha
{
    int *v;
    int n;
};

Pilha *piCria(void)
{
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if (pi==NULL)
        exit(1);
    pi->n=0;
    return pi;
}

void piPush(Pilha *pi, int ninf)
{
    int i, *nova = (int*)malloc(pi->n*sizeof(int));
    if(nova == NULL)
        exit(1);
    for(i = 0; i < pi->n; i++)
    {
        nova[i] = pi->v[i];
    }
    nova[pi->n] = ninf;
    free(pi->v);
    pi->v = nova;
    pi->n++;
}

int piEhVazia(Pilha *pi)
{
    if(pi->n == 0)
        return 1;
    return 0;
}

int piPop(Pilha *pi)
{
    int v;
    if(piEhVazia(pi))
        exit(1);
    pi->n--;
    v = pi->v[pi->n];
    return v;
}

void piLibera(Pilha *pi)
{
    free(pi->v);
    free(pi);
}

