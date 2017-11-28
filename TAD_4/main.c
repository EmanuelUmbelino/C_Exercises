#include <stdio.h>
#include <stdlib.h>
#include "Fracao.h"

Fracao *pegarMaior(Fracao **v, int n)
{
    Fracao *maior = v[0];int i;
    for (i = 1; i < n; i++)
    {
        if(comparaFrac(maior,v[i])==-1)
            maior = v[i];
    }
    return maior;
}
int input(char *txt)
{
    int i;
    printf("\n%s",txt);
    scanf("%d",&i);
    return i;
}
Fracao **criarVetor(int n)
{
    int i,num,den,s;
    Fracao **v = (Fracao**)malloc(n*sizeof(Fracao*));
    for(i=0;i<n;i++)
    {
        num = input("Numerador: ");
        den = input("Denominador: ");
        s = input("Sinal (1 = positivo, -1 = negativo): "); 
        v[i] = criarFrac(num,den,s); 
    }
    return v;
}
void liberarVetor(Fracao **v,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        liberaFrac(v[i]);
    }
}
int main()
{
    int n = 5;
    Fracao **v = criarVetor(n);
    Fracao *maior = pegarMaior(v, n);
    imprimirFracao(maior);
    
    liberarVetor(v,n);
    return 0;
}



