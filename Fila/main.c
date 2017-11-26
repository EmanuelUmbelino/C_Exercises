#include <stdio.h>
#include "fila.h"

void separa_filas(Fila *f, Fila *f_pares, Fila *f_impares)
{
    int v;
    while(!vazia(f))
    {
        v = retira(f);
        if(v%2==0)
            insere(f_pares,v);
        else
            insere(f_impares,v);
    }
}


int main()
{
    Fila *f, *f_pares, *f_impares;
    f = cria();f_pares = cria(); f_impares = cria();
    insere(f,1);
    insere(f,2);
    insere(f,3);
    insere(f,4);
    insere(f,4);
    insere(f,5);
    insere(f,1);
    separa_filas(f,f_pares,f_impares);
    imprime_fila(f);
    imprime_fila(f_pares);
    imprime_fila(f_impares);
    libera(f);libera(f_pares);libera(f_impares);

    return 0;
}




