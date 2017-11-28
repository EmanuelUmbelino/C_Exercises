#include <stdio.h>
#include "Retangulo.h"

float obtemArea(Retangulo *rect)
{
    return getBase(rect) * getAltura(rect);
}

int main()
{
    Retangulo *rect1 = criarRect(0,0,2,2), *rect2 = criarRect(5,-10,3,2);
    printf("\n%.2f",obtemArea(rect1));
    printf("\n%.2f",obtemArea(rect2));

    liberaRect(rect1);
    liberaRect(rect2);
    return 0;
}



