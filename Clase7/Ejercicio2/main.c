#include "input.h"

#define TAM 21

void mostrarVectorChar(char vec[], int tam);

int main()
{
    char x[TAM] = "Juan Sebastian Veron";
    char l[10];
    int size;

    input_clearScreen();

    // Controlar la cantidad de caracteres a copiar
    strncpy(l, x, 9);
    l[9] = '\0';

    mostrarVectorChar(l, 9);
    printf("%s\n", l);

    size = strlen(x);
    printf("size %d\n", size);

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
