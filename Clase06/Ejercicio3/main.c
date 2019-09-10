#include <stdio.h>
#include <stdlib.h>

#define TAM 2

void clearBuffer(void);

int main()
{
    int legajos[TAM];
    int edades[TAM];
    char sexos[TAM];
    int notasP1[TAM];
    int notasP2[TAM];
    float promedios[TAM];

    for(int i=0; i < TAM; i++)
    {
        printf("\nIngreso de datos\n");
        printf("Legajo: ");
        scanf("%d", &legajos[i]);
        printf("Edad: ");
        scanf("%d", &edades[i]);
        printf("Sexo: ");
        clearBuffer();
        scanf("%c", &sexos[i]);
        printf("Parcial 1: ");
        scanf("%d", &notasP1[i]);
        printf("Parcial 2: ");
        scanf("%d", &notasP2[i]);

        promedios[i] = (float)(notasP1[i] + notasP2[i])/2;
    }

    printf("\nDatos ingresados");
    printf("\nLegajo    Edad    Sexo    Nota1   Nota2   Promedio\n");

    for(int i=0; i < TAM; i++)
    {
        printf("    %d       %d      %c       %d      %d      %.2f\n",
            legajos[i], edades[i], sexos[i], notasP1[i], notasP2[i], promedios[i]);
    }

    return 0;
}

void clearBuffer()
{
    char memoryBuffer = '\n';

    /**< Mientras que en el buffer no exista un Enter
    la funcion getchar toma sus valores */
    while (getchar() != memoryBuffer)
    {
        /**< No requiere implementacion */
    }
}
