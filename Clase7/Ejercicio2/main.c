#include "input.h"

#define TAM 20

void mostrarVectorChar(char vec[], int tam);

int main()
{
    char x[TAM] = "Juan";
    char l[TAM];

    input_clearScreen();

    strncpy(l, x, TAM);

    mostrarVectorChar(l, TAM);
    printf("%s\n", l);

    return 0;
}

void mostrarVectorChar(char vec[], int tam)
{
    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            printf("%c ", vec[i]);
        }
        printf("\n");
    }
}
