#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
    int isEmpty;
}eEmpleado;

eEmpleado* newEmpleado();
int mostrarEmpleado(eEmpleado* emp);

int main()
{
    eEmpleado* emp2 = newEmpleado();

    if(!mostrarEmpleado(emp2))
    {
        printf("No se puede mostrar el Empleado.\n");
    }

    return 0;
}

eEmpleado* newEmpleado()
{
    eEmpleado* aux;

    aux = (eEmpleado*) malloc(sizeof(eEmpleado));

    if(aux != NULL)
    {
        aux->id = 0;
        strcpy(aux->nombre, "");
        aux->sueldo = 0;
        aux->isEmpty = 1;
    }

    return aux;
}

int mostrarEmpleado(eEmpleado* emp)
{
    int returnValue = 0;

    if(emp != NULL && !emp->isEmpty)
    {
        printf("| %5d | %20s | %5.2f |\n", emp->id, emp->nombre, emp->sueldo);
        returnValue = 1;
    }

    return returnValue;
}
