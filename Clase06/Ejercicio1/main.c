#include <stdio.h>
#include <stdlib.h>

void mostrarVector(char vec[], int tam);

int main()
{
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    char stringEjemplo[] = {'a', 'e', 'i', '\0', 'u'};

    mostrarVector(vocales, sizeof(vocales));
    printf("\n%s", stringEjemplo);
    return 0;
}

void mostrarVector(char vec[], int tam)
{
    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            printf("%c ", vec[i]);
        }
    }
}
