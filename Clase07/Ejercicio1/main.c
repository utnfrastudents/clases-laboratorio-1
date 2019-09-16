#include "input.h"

#define TAM 5
#define ASC 0
#define DESC 1
#define ORDER 1
#define NO_ORDER 0

void mostrarAlumno(int leg, int edad, char sex, int nP1, int nP2, float prom);
void mostrarAlumnos(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam);
void ordenarAlumnosPorLegajoGenero(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam, int criterioLegajo, int criterioGenero);
void swapInt(int* i, int* j);
void swapChar(char* i, char* j);
void swapFloat(float* i, float* j);

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

    ordenarAlumnosPorLegajoGenero(legajos, edades, sexos, notasP1, notasP2, promedios, TAM, ASC, DESC);

    printf("[Alumnos ordenados de forma ascendente y por genero]\n");
    mostrarAlumnos(legajos, edades, sexos, notasP1, notasP2, promedios, TAM);

    ordenarAlumnosPorLegajoGenero(legajos, edades, sexos, notasP1, notasP2, promedios, TAM, DESC, DESC);

    printf("[Alumnos ordenados de forma descendente y por genero]\n");
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

void ordenarAlumnosPorLegajoGenero(int leg[], int edad[], char sex[], int nP1[], int nP2[], float prom[], int tam, int criterioLegajo, int criterioGenero)
{
    int swap = NO_ORDER;

    if(leg!=NULL && edad!=NULL && sex!=NULL && nP1!=NULL && nP2!=NULL && prom!=NULL
        && tam>0 && (criterioLegajo==ASC || criterioLegajo==DESC) && (criterioGenero==ASC || criterioGenero==DESC))
    {
        for(int i=0; i < tam-1; i++)
        {
            for(int j = i+1; j < tam; j++)
            {
                if((!criterioGenero && (sex[i] > sex[j]))
                    || (criterioGenero && (sex[i] < sex[j])))
                {
                    swap = ORDER;
                }
                else
                {
                    if(sex[i] == sex[j]
                        && ((!criterioLegajo && (leg[i] > leg[j]))
                        || (criterioLegajo && (leg[i] < leg[j]))))
                    {
                        swap = ORDER;
                    }
                }

                if(swap == ORDER)
                {
                    swapInt(&leg[i], &leg[j]);
                    swapInt(&edad[i], &edad[j]);
                    swapChar(&sex[i], &sex[j]);
                    swapInt(&nP1[i], &nP1[j]);
                    swapInt(&nP2[i], &nP2[j]);
                    swapFloat(&prom[i], &prom[j]);
                }

                swap = NO_ORDER;
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
