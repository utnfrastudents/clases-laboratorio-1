#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define ASC 0
#define DESC 1

void mostrarVectorInt(int vec[], int tam);
void ordenarVectorInt(int vec[], int tam, int criterio);
void swapInt(int* i, int* j);

int main()
{
    int vec[TAM] = {7, 8, 1, 3, 5};


    printf("Vector desordenado: ");
    mostrarVectorInt(vec, TAM);

    ordenarVectorInt(vec, TAM, ASC);
    printf("\nVector ordenado ascendente: ");
    mostrarVectorInt(vec, TAM);

    ordenarVectorInt(vec, TAM, DESC);
    printf("\nVector ordenado descendente: ");
    mostrarVectorInt(vec, TAM);

    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{
    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            printf("%d ", vec[i]);
        }
    }
}

void ordenarVectorInt(int vec[], int tam, int criterio)
{
    if(vec != NULL && tam > 0 && (criterio == 0 || criterio ==1))
    {
        for(int i=0; i < tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if((!criterio && (vec[i] > vec[j]))
                    || (criterio && (vec[i] < vec[j])))
                {
                    swapInt(&vec[i], &vec[j]);
                }
            }
        }
    }
}

void swapInt(int* i, int* j)
{
    int aux;

    aux = *i;
    *i = *j;
    *j = aux;
}
