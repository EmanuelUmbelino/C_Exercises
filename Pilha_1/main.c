#include <stdio.h>
#include "pilha.h"

// funcao que imprime o grande numero da pilha
void piImprime(Pilha *p)
{
    printf("\nResultado da soma:");
    while(!piEhVazia(p))
    {
        printf("%d",piPop(p));
    }
}
void somaGrandesNumeros()
{
    Pilha *p1 = piCria(), *p2 = piCria(), *r1 = piCria();
    int aux, aux1, aux2;
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
    aux = 0;
    while(!piEhVazia(p1) || !piEhVazia(p2))
    {
        aux = aux1;
        aux1 = piPop(p1);
        aux2 = piPop(p2);
        aux += aux1 + aux2;
        aux1 = aux / 10;
        if(aux < 10)
            piPush(r1,aux);
        else
            piPush(r1,aux%10);
    }
    if(aux1!=0)
        piPush(r1,aux1);
    printf("\nResultado da soma:");
    while(!piEhVazia(r1))
    {
        printf("%d",piPop(r1));
    }

    piLibera(p1);piLibera(p2);piLibera(r1);
}

int main()
{
    somaGrandesNumeros();
    return 0;
}
