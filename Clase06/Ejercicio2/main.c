#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVector(int vec[], int tam);

int main()
{
    int vec[TAM] = {7, 8, 1, 3, 5};
    int aux;

    printf("Vector desordenado: ");
    mostrarVector(vec, TAM);

    for(int i=0; i < TAM-1; i++)
    {
        for(int j = i+1; j < TAM; j++)
        {
            if(vec[i] > vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    printf("\nVector ordenado: ");
    mostrarVector(vec, TAM);

    return 0;
}

void mostrarVector(int vec[], int tam)
{
    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            printf("%d ", vec[i]);
        }
    }
}
