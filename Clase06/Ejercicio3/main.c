#include <stdio.h>
#include <stdlib.h>

#define TAM 2

void mostrarAlumnos(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam);
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

    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam)
{
    if(leg!=NULL && edad!=NULL && sex!=NULL && nP1!=NULL && nP2!=NULL && prom!=NULL && tam>0)
    {
        printf("\nDatos ingresados");
        printf("\nLegajo    Edad    Sexo    Nota1   Nota2   Promedio\n");

        for(int i=0; i < tam; i++)
        {
            printf("    %d       %d      %c       %d      %d      %.2f\n",
                leg[i], edad[i], sex[i], nP1[i], nP2[i], prom[i]);
        }
    }
}

void clearBuffer()
{
    char memoryBuffer = '\n';

    while (getchar() != memoryBuffer)
    {
        /**< No requiere implementacion */
    }
}
