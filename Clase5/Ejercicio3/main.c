#include <stdio.h>
//#include <stdlib.h>
#define VECTOR 5

int main()
{
    int valores[VECTOR] = {0};
    int mayor, posicion;

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

    mayor = valores[0];

    for(int i=0; i < VECTOR; i++)
    {
        if(mayor < valores[i])
        {
            mayor = valores[i];
            posicion = i;
        }
    }

    printf("\nEl valor %d es el mayor ingresado en la posicion %d\n", mayor, posicion);

    return 0;
}
