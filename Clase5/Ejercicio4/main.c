#include <stdio.h>
#include <stdlib.h>

static int buscarNumero(int vec[], int tam, int numero);

int main()
{
    int numeros[] = {23, 56, 43, 21, 67, 98, 45, 11, 62, 10};
    int esta;

    esta = buscarNumero(numeros, 10, 100);

    if(esta)
    {
        printf("Esta\n");
    }
    else
    {
        printf("No esta\n");
    }

    return 0;
}

static int buscarNumero(int vec[], int tam, int numero)
{
    int esta = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i] == numero)
            {
                esta = 1;
                break;
            }
        }
    }

    return esta;
}

