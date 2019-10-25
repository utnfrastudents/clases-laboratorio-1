#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
    int estado;
}eEmpleado;

eEmpleado* newEmpleado();

int main()
{
    eEmpleado* emp2 = newEmpleado();

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
        aux->estado = 0;
    }

    return aux;
}
