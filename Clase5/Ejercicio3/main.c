#include <stdio.h>
//#include <stdlib.h>
#define VECTOR 5

static void mostrarVectorInt(int vec[] /* int *vec */, int tam);

static int obtenerMayor(int vec[], int tam, int* posicion);

static void cargarVectorEnteros(int vec[], int tam);

int main()
{
    int valores[VECTOR] = {0};
    int mayor, posicion;

    cargarVectorEnteros(valores, VECTOR);

    mostrarVectorInt(valores, VECTOR);

    mayor = obtenerMayor(valores, VECTOR, &posicion);

    printf("\nEl valor %d es el mayor ingresado en la posicion %d\n", mayor, posicion);

    return 0;
}

static void mostrarVectorInt(int vec[] /* int *vec */, int tam)
{
    if(vec != NULL && tam > 0)
    {
        printf("Valores ingresados: ");

        for(int i=0; i < tam; i++)
        {
            printf("%d ", vec[i]);
        }
    }
}

static int obtenerMayor(int vec[], int tam, int* posicion)
{
    int maximo;

    if(vec != NULL && tam > 0)
    {
        maximo = vec[0];

        for(int i=0; i < tam; i++)
        {
            if(maximo < vec[i])
            {
                maximo = vec[i];
                *posicion = i;
            }
        }
    }

    return maximo;
}

static void cargarVectorEnteros(int vec[], int tam)
{
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            printf("Ingrese un entero a la posicion %d: ", i);
            scanf("%d", &vec[i]);
        }
    }
}
