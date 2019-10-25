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
eEmpleado* newFullEmpleado(int id, char nombre[], float sueldo);
int mostrarEmpleado(eEmpleado* emp);

int main()
{
    eEmpleado* emp2 = newFullEmpleado(1, "Pepe Argento", 55600);

    if(!mostrarEmpleado(emp2))
    {
        printf("No se puede mostrar el Empleado.\n");
    }

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
