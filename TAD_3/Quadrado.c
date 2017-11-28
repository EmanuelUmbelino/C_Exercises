#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Quadrado.h"

struct quadrado
{
    float x,y,lado;
    char nome[21];
};

Quadrado *quaCria(float x, float y, float lado, char *nome)
{
    Quadrado *q = (Quadrado*)malloc(sizeof(Quadrado));
    q->x = x; q->y = y;q->lado = lado;
    strcpy(q->nome,nome);
    return q;
}

float quaObtemXdeVSD(Quadrado *q)
{
    return q->x;
}

float quaObtemYdeVSD(Quadrado *q)
{
    return q->y;
}

float quaObtemLado(Quadrado *q)
{
    return q->lado;
}

char *quaObtemNome(Quadrado *q)
{
    return q->nome;
}

void quaLibera(Quadrado *q)
{
    free(q);
}