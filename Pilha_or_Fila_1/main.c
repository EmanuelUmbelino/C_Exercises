#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDeLivros.h"


void exibeOsXLivrosMaisVendidosDeUmAutor(No *lst,char *autor,int x)
{
    PilhaDeLivros *p = piCria();
    Livro *liv;
    int i;
    while(lst!=NULL)
    {
        liv = lst->info;
        lst = lst->prox;
        if(strcmp(liv->autor,autor)==0)
            piPush(p,liv);
    }
    if(piVazia(p))
    {
        printf("Nao ha livros do autor %s na lista",autor);
        return;
    }
    for(i = 0; i < x; i ++)
    {
        liv = piPop(p);
        printf("{%s,%s,%d} ",liv->autor,liv->titulo,liv->qtdVendida);
        if(piVazia(p))
            break;
    }
    piLibera(p);
}
No *criaLista(void)
{
    return NULL;
}

No *colocaLivro(No *no, char *autor, char *titulo, int qtdVendida)
{
    No *n = (No*)malloc(sizeof(No));
    n->info = (Livro*)malloc(sizeof(Livro));
    strcpy(n->info->autor,autor);
    strcpy(n->info->titulo,titulo);
    n->info->qtdVendida = qtdVendida;
    n->prox = no;
    return n;
}
No *libera(No *no)
{
    No *aux;
    while(no!=NULL)
    {
        aux = no;
        free(aux->info);
        no=no->prox;
        free(aux);
    }
}

int main()
{
    No *n = criaLista();
    n = colocaLivro(n,"vik","voz",700);
    n = colocaLivro(n,"leo","sal",620);
    n = colocaLivro(n,"ana","dias",600);
    n = colocaLivro(n,"leo","tres",550);
    n = colocaLivro(n,"vik","god",500);
    n = colocaLivro(n,"edu","luz",406);
    n = colocaLivro(n,"leo","rua",400);
    n = colocaLivro(n,"bia","gaia",380);
    n = colocaLivro(n,"leo","ceu",350);
    n = colocaLivro(n,"ana","dor",300);
    n = colocaLivro(n,"edu","mar",200);
    exibeOsXLivrosMaisVendidosDeUmAutor(n,"leo",4);
    libera(n);

    return 0;
}



