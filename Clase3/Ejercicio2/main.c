#include <stdio.h>
//#include <stdlib.h>
#include "utn.h"

int main()
{
    int valor;

    valor = getInt200_500();

    printf("El valor ingresado es: %d\n", valor);
    return 0;
}
