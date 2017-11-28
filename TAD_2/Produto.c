#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produto.h"

struct prod
{
    char nome[15];
    int qtd;
    float preco;
};

Produto *criaProduto(char *nome, int qtd, float preco)
{
    Produto *p = (Produto*)malloc(sizeof(Produto));
    strcpy(p->nome,nome);
    p->qtd = qtd;
    p->preco = preco;
    return p;
}

void imprimeProduto(Produto *p)
{
    printf("\nNome: %s \nQtd em estoque: %d \t Preco: R$%.2f",
        p->nome,p->qtd,p->preco);
}

int estoqueVazio(Produto *p)
{
    if(p->qtd==0)
        return 1;
    return 0;
}

void liberaProduto(Produto *p)
{
    free(p);
}