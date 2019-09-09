#include <stdio.h>
//#include <stdlib.h>
#define VECTOR 5

int main()
{
    int valores[VECTOR] = {0};
    int acumulador = 0;

    for(int i=0; i < VECTOR; i++)
    {
        printf("Ingrese un entero a la posicion %d: ", i);
        scanf("%d", &valores[i]);
    }

    printf("Valores ingresados:\n");

    for(int i=0; i < VECTOR; i++)
    {
        printf("%d ", valores[i]);
    }

    for(int i=0; i < VECTOR; i++)
    {
        acumulador += valores[i];
    }

    printf("\nLa suma de los enteros ingresados es %d\n", acumulador);

    return 0;
}
