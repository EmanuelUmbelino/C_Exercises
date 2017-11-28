#include <stdio.h>
#include <stdlib.h>
#include "Retangulo.h"

struct rect 
{
    float x, y, base, altura;
};

Retangulo *criarRect(float x, float y, float base, float altura)
{
    Retangulo *rect = (Retangulo*)malloc(sizeof(Retangulo));
    rect.x = x;
    rect.y = y;
    rect.base = base;
    rect.altura = altura;
    return rect;
}

float getX(Retangulo *rect)
{
    return rect.x;
}

float getY(Retangulo *rect)
{
    return rect.y;
}

float getBase(Retangulo *rect)
{
    return rect.base;
}

float getAltura(Retangulo *rect)
{
    return rect.altura;
}

void liberaRect(Retangulo *rect)
{
    free(rect);
}