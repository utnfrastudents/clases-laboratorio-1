#include <stdio.h>
#include "utn.h"

int getMax(int a, int b, int c)
{
    int max = a;

    if(b > a)
    {
        max = b;
    }

    if(c > a && c > b)
    {
        max = c;
    }

    return max;
}

int getInt200_500()
{
    int value;

    do
    {
        printf("Ingresar un numero entre 200 y 500: ");
        scanf("%d", &value);
    }while(value > 500 || value < 200);

    return value;
}
