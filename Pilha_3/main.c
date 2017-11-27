#include <stdio.h>
#include "pilha.h"

// funcao que imprime a pilha
void piImprime(Pilha *p)
{
    printf("\nPilha:");
    while(!piEhVazia(p))
    {
        printf("%d ",piPop(p));
    }
}

void retiraImpares(Pilha *p)
{
    Pilha *par = piCria();
    int aux;
    while(!piEhVazia(p))
    {
        aux = piPop(p);
        if(aux%2==0)
            piPush(par,aux);
    }
    while(!piEhVazia(par))
    {
        piPush(p,piPop(par));
    }
    
}

int main()
{
    Pilha *p = piCria();
    piPush(p,1);
    piPush(p,2);
    piPush(p,3);
    piPush(p,4);
    
    retiraImpares(p);
    piImprime(p);
    piLibera(p);

    return 0;
}



