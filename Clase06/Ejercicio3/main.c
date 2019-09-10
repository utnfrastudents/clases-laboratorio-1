#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarAlumno(int leg, int edad, char sex, int nP1, int nP2, float prom);
void mostrarAlumnos(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam);
void clearBuffer(void);

int main()
{
    int legajos[TAM] = {1234, 1122, 2233, 3344, 4455};
    int edades[TAM] = {22, 33, 44, 55, 66};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasP1[TAM] = {8, 2, 9, 8, 5};
    int notasP2[TAM] = {2, 5, 8, 7, 4};
    float promedios[TAM] = {3.0, 5.6, 7.8, 8.7, 5.2};

//    for(int i=0; i < TAM; i++)
//    {
//        printf("\nIngreso de datos\n");
//        printf("Legajo: ");
//        scanf("%d", &legajos[i]);
//        printf("Edad: ");
//        scanf("%d", &edades[i]);
//        printf("Sexo: ");
//        clearBuffer();
//        scanf("%c", &sexos[i]);
//        printf("Parcial 1: ");
//        scanf("%d", &notasP1[i]);
//        printf("Parcial 2: ");
//        scanf("%d", &notasP2[i]);
//
//        promedios[i] = (float)(notasP1[i] + notasP2[i])/2;
//    }

    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM);

    return 0;
}

void mostrarAlumno(int leg, int edad, char sex, int nP1, int nP2, float prom)
{
    printf("    %d       %d      %c       %d      %d      %.2f\n",
        leg, edad, sex, nP1, nP2, prom);
}

void mostrarAlumnos(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam)
{
    if(leg!=NULL && edad!=NULL && sex!=NULL && nP1!=NULL && nP2!=NULL && prom!=NULL && tam>0)
    {
        printf("\nDatos ingresados");
        printf("\nLegajo    Edad    Sexo    Nota1   Nota2   Promedio\n");

        for(int i=0; i < tam; i++)
        {
            mostrarAlumno(leg[i], edad[i], sex[i], nP1[i], nP2[i], prom[i]);
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
