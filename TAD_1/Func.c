#include "Func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario
{
    char *nome;
    int ano;
};

Func *func_cria(char *nome, int ano)
{
    Func *f = (Func*)malloc(sizeof(Func));
    f->nome = (char*)malloc(strlen(nome)*sizeof(char));
    strcpy(f->nome,nome);
    f->ano = ano;
    return f;
}

char *func_getNome(Func *f)
{
    return f->nome;
}

int func_getAno(Func *f)
{
    return f->ano;
}