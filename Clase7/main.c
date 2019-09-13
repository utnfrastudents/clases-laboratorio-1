#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define ASC 0
#define DESC 1

void mostrarAlumno(int leg, int edad, char sex, int nP1, int nP2, float prom);
void mostrarAlumnos(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam);
void ordenarAlumnosPorLegajo(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam, int criterio);
void swapInt(int* i, int* j);
void swapChar(char* i, char* j);
void swapFloat(float* i, float* j);
void clearBuffer(void);

int main()
{
    int legajos[TAM] = {6677, 1122, 5566, 3344, 4455};
    int edades[TAM] = {77, 88, 44, 55, 22};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasP1[TAM] = {8, 2, 9, 8, 5};
    int notasP2[TAM] = {2, 5, 8, 7, 4};
    float promedios[TAM] = {3.0, 5.6, 7.8, 8.7, 5.2};

    printf("[Alumnos desordenados]\n");
    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM);

    ordenarAlumnosPorLegajo(legajos, edades, sexos, notasP1, notasP2, promedios, TAM, ASC);

    printf("[Alumnos ordenados de forma ascendente]\n");
    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM);

    ordenarAlumnosPorLegajo(legajos, edades, sexos, notasP1, notasP2, promedios, TAM, DESC);

    printf("[Alumnos ordenados de forma descendente]\n");
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

        printf("\n");
    }
}

void ordenarAlumnosPorLegajo(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam, int criterio)
{
    if(leg!=NULL && edad!=NULL && sex!=NULL && nP1!=NULL && nP2!=NULL && prom!=NULL
        && tam>0 && (criterio==ASC || criterio==DESC))
    {
        for(int i=0; i < tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if((!criterio && (leg[i] > leg[j]))
                    || (criterio && (leg[i] < leg[j])))
                {
                    swapInt(&leg[i], &leg[j]);
                    swapInt(&edad[i], &edad[j]);
                    swapChar(&sex[i], &sex[j]);
                    swapInt(&nP1[i], &nP1[j]);
                    swapInt(&nP2[i], &nP2[j]);
                    swapFloat(&prom[i], &prom[j]);
                }

                if((!criterio && (sex[i] > sex[j]))
                    || (criterio && (sex[i] < sex[j])))
                {
                    swapInt(&leg[i], &leg[j]);
                    swapInt(&edad[i], &edad[j]);
                    swapChar(&sex[i], &sex[j]);
                    swapInt(&nP1[i], &nP1[j]);
                    swapInt(&nP2[i], &nP2[j]);
                    swapFloat(&prom[i], &prom[j]);
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

void swapChar(char* i, char* j)
{
    char aux;

    aux = *i;
    *i = *j;
    *j = aux;
}

void swapFloat(float* i, float* j)
{
    float aux;

    aux = *i;
    *i = *j;
    *j = aux;
}

void clearBuffer()
{
    char memoryBuffer = '\n';

    while (getchar() != memoryBuffer)
    {
        /**< No requiere implementacion */
    }
}
