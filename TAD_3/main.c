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

char *buscaBinaria(Quadrado **q, int n, float x, float y)
{
    int ini = 0, fim = n-1;
    while(ini <= fim)
    {
        int meio = (ini+fim)/2;
        if (x < quaObtemXdeVSD(q[meio]))
            fim = meio-1;
        else if (x > quaObtemXdeVSD(q[meio]))
            ini = meio+1;
        else
        {
            if (y < quaObtemYdeVSD(q[meio]))
                fim = meio-1;
            else if (y > quaObtemYdeVSD(q[meio]))
                ini = meio+1;
            else
                return quaObtemNome(q[meio]);
        }
    }
    return NULL;
}

int main()
{
    No *lst = criaLst();
    lst = addNo(lst,5,0,5,"A");
    lst = addNo(lst,-2,0,15,"B");
    lst = addNo(lst,5,5,5,"C");
    lst = addNo(lst,15,15,5,"D");
    lst = addNo(lst,0,-2,5,"E");
    printf("%d estao no 1o quadrante",contaPrimeiroQuadrante(lst));
    liberaLst(lst);
    
    int i, n = 5;
    Quadrado *v[n];
    v[0] = quaCria(-2,0,15,"B");
    v[1] = quaCria(0,-2,5,"E");
    v[2] = quaCria(5,0,5,"A");
    v[3] = quaCria(5,5,5,"C");
    v[4] = quaCria(15,15,5,"D");
    printf("\nO carinha da busca: ");
    printf(buscaBinaria(v, n, 5, 5));
    for(i = 0; i < n; i++)
        quaLibera(v[i]);
    return 0;
}