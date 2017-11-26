#include <stdio.h>
#include "pilha.h"

void somaGrandesNumeros()
{
    Pilha *p1 = piCria(), *p2 = piCria(), *r1 = piCria();
    int aux;
    printf("\nDigite cada algarismo do primeiro numero (termina com numero negativo):\n");
    while(1)
    {
        scanf("%d",&aux);
        if(aux<0)
            break;
        piPush(p1,aux);
    }
    printf("\nDigite cada algarismo do segundo numero (termina com numero negativo):\n");
    while(1)
    {
        scanf("%d",&aux);
        if(aux<0)
            break;
        piPush(p2,aux);
    }

    while(!piEhVazia(p1) || !piEhVazia(p1))
    {

    }

    piLibera(p1);piLibera(p2);piLibera(r1);
}

int main()
{
    return 0;
}
