#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"


void mostrarCarreras(eCarrera carreras[], int tam)
{
    int i;
    printf(" Id   Descripcion\n\n");
    for(i=0; i < tam; i++){
        mostrarCarrera( carreras[i]);
    }
    printf("\n");
}

void mostrarCarrera(eCarrera carrera){

    printf("  %d      %10s\n", carrera.id, carrera.descripcion);

}

int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[])
{
    int i;
    int todoOk = 0;

    for(i=0; i < tam; i++){
        if( id == carreras[i].id){
            strcpy(desc, carreras[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

