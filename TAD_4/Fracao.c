#include <stdio.h>
#include <stdlib.h>
#include "Fracao.h"

struct frac 
{
    int numerador, denominador, sinal;
};

Fracao *criarFrac(int numerador, int denominador, int sinal)
{
    Fracao *frac = (Fracao*)malloc(sizeof(Fracao));
    frac->numerador = numerador;
    frac->denominador = denominador;
    frac->sinal = sinal;
    return frac;
}

void imprimirFracao(Fracao *frac)
{
    if(frac->sinal>0)
        printf("+%d/%d",frac->numerador,frac->denominador);
    else
        printf("-%d/%d",frac->numerador,frac->denominador);
}
//Recebe 2 fracoes e retorna 1 se a primeira eh maior, -1 se eh menor e 0 se sao iguais
int comparaFrac(Fracao *f1, Fracao *f2)
{
    float n1 = f1->sinal * (f1->numerador/f1->denominador);
    float n2 = f2->sinal * (f2->numerador/f2->denominador);
    if(n1>n2)
        return 1;
    else if(n1<n2)
        return -1;
    else
        return 0;
}

void liberaFrac(Fracao *frac)
{
    free(rect);
}