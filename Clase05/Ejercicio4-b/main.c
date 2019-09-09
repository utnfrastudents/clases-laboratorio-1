#include <stdio.h>
#include <stdlib.h>

static int buscarNumero(int vec[], int tam, int numero, int* posicion);

int main()
{
    int numeros[] = {23, 56, 43, 21, 67, 98, 45, 11, 62, 10};
    int esta;
    int posicion;

    esta = buscarNumero(numeros, 10, 10, &posicion);

    if(esta)
    {
        printf("Esta\n");
        printf("La posicion es: %d\n", posicion);
    }
    else
    {
        printf("No esta\n");
    }

    return 0;
}

static int buscarNumero(int vec[], int tam, int numero, int* posicion)
{
    int esta = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i] == numero)
            {
                esta = 1;
                *posicion=i;
                break;
            }
        }
    }

    return esta;
}
