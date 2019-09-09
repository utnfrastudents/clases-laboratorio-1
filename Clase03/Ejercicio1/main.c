#include <stdio.h>
//#include <stdlib.h>
#include "utn.h"

int main()
{
    int a, b, c;
    int max;

    printf("Ingresar 3 enteros sepados por espacio: ");
    scanf("%d %d %d", &a, &b, &c);

    max = getMax(a, b, c);

    printf("El valor maximo entre %d, %d y %d es %d\n", a, b, c, max);

    return 0;
}

