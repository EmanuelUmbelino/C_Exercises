#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDeEventos.h"

FilaDeEventos *extraiEventosDeUmProdutor(PilhaDeEventos *p, char *prod)
{
    PilhaDeEventos *aux = piCria();
    FilaDeEventos *fi = fiCria();
    Evento *ev;
    while(!piVazia(p))
    {
        ev = piPop(p);
        if(strcmp(ev->produtor,prod)==0)
        {
            fiInsere(fi,ev);
        }
        else
            piPush(aux,ev);
    }
    while(!piVazia(aux))
    {
        piPush(p,piPop(aux));
    }
    piLibera(aux);
    return fi;
}
void imprimeEventosProdutor(FilaDeEventos *f)
{
    Evento *ev;
    while(!fiVazia(f))
    {
        ev = fiRetira(f);
        printf("\nEvento: %s  Por: %s  No dia:%d/%d/%d",ev->nomeEvento,ev->produtor,ev->dt.dia,ev->dt.mes,ev->dt.ano);
    }
}
void imprimeEventos(PilhaDeEventos *p)
{
    Evento *ev;
    while(!piVazia(p))
    {
        ev = piPop(p);
        printf("\nEvento: %s  Por: %s  No dia:%d/%d/%d",ev->nomeEvento,ev->produtor,ev->dt.dia,ev->dt.mes,ev->dt.ano);
    }
}
Evento *criaEvento(char *nome,char *produtor, int dia, int mes, int ano)
{
    Evento *ev = (Evento*)malloc(sizeof(Evento));
    strcpy(ev->nomeEvento,nome);
    strcpy(ev->produtor,produtor);
    ev->dt.dia = dia;
    ev->dt.mes = mes;
    ev->dt.ano = ano;
    return ev;
}

int main()
{
    PilhaDeEventos *p = piCria();
    FilaDeEventos *f;
    piPush(p,criaEvento("A","Neo",1,1,2000));
    piPush(p,criaEvento("B","Neo",1,1,2002));
    piPush(p,criaEvento("C","Claudim",1,1,2004));
    piPush(p,criaEvento("D","Disne",1,1,2005));
    piPush(p,criaEvento("E","Neo",1,1,2009));
    f = extraiEventosDeUmProdutor(p, "Neo");
    
    imprimeEventosProdutor(f);
    printf("\n");
    imprimeEventos(p);
    
    piLibera(p);
    fiLibera(f);

    return 0;
}



