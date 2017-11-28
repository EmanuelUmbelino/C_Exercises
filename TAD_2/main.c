#include <stdio.h>
#include "Produto.h"

void imprimirAviso(Produto *p)
{
    imprimeProduto(p);
    if(estoqueVazio(p))
        printf("\nESTOQUE VAZIO!");
}

int main()
{
    Produto *p = criaProduto("Capim", 15, 359.9);
    imprimirAviso(p);
    liberaProduto(p);
    p = criaProduto("Vida", 30000, 0);
    imprimirAviso(p);
    liberaProduto(p);
    p = criaProduto("Dinheiro", 0, 100000);
    imprimirAviso(p);
    liberaProduto(p);
    return 0;
}