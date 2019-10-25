#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define TAM 5

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
    int isEmpty;
}eEmpleado;

eEmpleado* newEmpleado();
eEmpleado* newFullEmpleado(int id, char nombre[], float sueldo);
int inicializarEmpleados(eEmpleado vec[], int tam);
int mostrarEmpleado(eEmpleado* emp);

int main()
{
    int tam = 0;
    eEmpleado* emp2 = newFullEmpleado(1, "Pepe Argento", 55650.45);
    eEmpleado* emp3 = newFullEmpleado(2, "Mony Argento", 68907.65);
    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado)*(tam+1));
    eEmpleado* aux;

    if(inicializarEmpleados(lista, tam+1) == -1)
    {
        exit(EXIT_FAILURE);
    }

    *(lista + tam) = *emp2;

    if(!mostrarEmpleado(lista+tam))
    {
        printf("No se puede mostrar el Empleado.\n");
    }
    tam++;

    aux = (eEmpleado*)realloc(lista, sizeof(eEmpleado)*(tam+1));

    if(aux != NULL)
    {
        lista = aux;
        free(aux);
    }

    *(lista + tam) = *emp3;

    if(!mostrarEmpleado(lista+tam))
    {
        printf("No se puede mostrar el Empleado.\n");
    }

    free(lista);
    free(emp2);
    free(emp3);

    return 0;
}

eEmpleado* newEmpleado()
{
    eEmpleado* aux;

    aux = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(aux != NULL)
    {
        aux->id = 0;
        strcpy(aux->nombre, "");
        aux->sueldo = 0;
        aux->isEmpty = 1;
    }

    return aux;
}

eEmpleado* newFullEmpleado(int id, char nombre[], float sueldo)
{
    eEmpleado* aux;
    aux = newEmpleado();

    if(aux != NULL)
    {
        aux->id = id;
        strcpy(aux->nombre, nombre);
        aux->sueldo = sueldo;
        aux->isEmpty = 0;
    }

    return aux;
}

int inicializarEmpleados(eEmpleado vec[], int tam)
{
    int returnValue = -1;
    int i;

    if(vec != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            (vec+i)->isEmpty = 1;

            if((vec+i) == NULL) //Revisar
            {
                break;
            }
        }

        if(i == tam)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

int mostrarEmpleado(eEmpleado* emp)
{
    int returnValue = 0;

    if(emp != NULL && !emp->isEmpty)
    {
        printf("+=======+======================+============+\n");
        printf("|   ID  |        NOMBRE        |   SUELDO   |\n");
        printf("+=======+======================+============+\n");
        printf("| %5d | %20s | $ %5.2f |\n", emp->id, emp->nombre, emp->sueldo);
        printf("+-------+----------------------+------------+\n");

        returnValue = 1;
    }

    return returnValue;
}
