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
