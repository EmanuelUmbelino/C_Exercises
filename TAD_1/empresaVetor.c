#include "Func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int comp_func(const void* p1, const void* p2)
{
    Func **f1 = (Func**)p1;
    Func **f2 = (Func**)p2;
    
    if(strcmp(func_getNome(*f1),func_getNome(*f2))<0)
        return -1;
    else if(strcmp(func_getNome(*f1),func_getNome(*f2))>0)
        return 1;
    else if(func_getAno(*f1) < func_getAno(*f2))
        return -1;
    else if(func_getAno(*f1) > func_getAno(*f2))
        return 1;
    return 0;
}

Func **montaVetor(int n, char **nomes, int *anos)
{
    Func **v = (Func**)malloc(n*sizeof(Func*));
    int i;
    for(i = 0; i<n;i++)
    {
        v[i] = func_cria(nomes[i], anos[i]);
    }
    return v;
}

void listaVetor(int n, Func **v)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nNome: %s\t\t Ano: %d",func_getNome(v[i]),func_getAno(v[i]));
    }
}

void ordenaVetor(int n, Func **v)
{
    qsort(v,n,sizeof(Func*),comp_func);
}

Func *buscaVetor(int n, Func **v, char *nome)
{
    int i,c;
    Func *r = NULL;
    for(i = 0; i < n; i++)
    {
        c = strcmp(nome,func_getNome(v[i]));
        if(c==0)
            r=v[i];
        else if(c<0)
            break;
    }
    return r;
}


int main()
{
    char *nomes[] = {"Diana Maria", "Beatrice Dante", "Ada Eva", "Diana Maria",
            "Beatrice Dante", "Helena Troia", "Diana Maria", "Beatrice Dante"};
    int anos[] = {2002,2010,2010,2006,2009,2005,2000,2005};
    char nome[51];
    Func *f;
    Func **v = montaVetor(8,nomes,anos);
    printf("Lista Funcionarios:\n");
    listaVetor(8,v);
    printf("\n\nLista Funcionarios Ordenados:\n");
    ordenaVetor(8,v);
    listaVetor(8,v);
    printf("\n\nEntre nome: ");
    scanf("%50[^\n]",nome);
    f = buscaVetor(8,v,nome);
    printf("\nFuncionario mais recente com este nome foi admitido em %d",func_getAno(f));
    
    return 0;
}

