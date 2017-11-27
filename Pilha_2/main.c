#include <stdio.h>
#include "pilha.h"

// funcao que imprime a pilha
void piImprime(Pilha *p)
{
    printf("\nPilha:");
    while(!piEhVazia(p))
    {
        printf("%d",piPop(p));
    }
}

int main()
{
    Pilha *p = piCria();
    piPush(p,1);
    piPush(p,2);
    piPush(p,3);
    piPush(p,4);
    
    piPop(p);
    piImprime(p);
    piLibera(p);

    return 0;
}



