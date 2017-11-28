#include <stdio.h>
#include <stdlib.h>
#include "Quadrado.h"

typedef struct no No;
struct no
{
    Quadrado *info;
    No *prox;
};

No *criaLst(void)
{
    return NULL;
}

No *addNo(No *lst, float x, float y, float lado, char *nome)
{
    No *novo = (No*)malloc(sizeof(No));
    novo->info = quaCria(x,y,lado,nome);
    novo->prox = lst;
    return novo;
}

void liberaLst(No *lst)
{
    No *aux;
    while(lst!=NULL)
    {
        aux = lst->prox;
        quaLibera(lst->info);
        free(lst);
        lst = aux;
    }
}

int noPrimeiroQuadrante(Quadrado *q)
{
    if(quaObtemXdeVSD(q) >= 0 && quaObtemYdeVSD(q) >= 0 && 
        quaObtemYdeVSD(q) - quaObtemLado(q) >= 0 && 
        quaObtemXdeVSD(q) - quaObtemLado(q) >= 0)
        return 1;
    return 0;
}

int contaPrimeiroQuadrante(No *lst)
{
    if(lst == NULL)
        return 0;
    return noPrimeiroQuadrante(lst->info) + contaPrimeiroQuadrante(lst->prox);
}

int main()
{
    No *lst = criaLst();
    lst = addNo(lst,5,0,5,"A");
    lst = addNo(lst,-2,0,15,"B");
    lst = addNo(lst,5,5,5,"C");
    lst = addNo(lst,15,15,5,"D");
    lst = addNo(lst,0,-2,5,"E");
    printf("%d",contaPrimeiroQuadrante(lst));
    liberaLst(lst);
    return 0;
}



