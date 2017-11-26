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

    return 0;
}




