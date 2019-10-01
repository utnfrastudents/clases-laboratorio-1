#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "comida.h"

void mostrarComida(eComida comidas)
{

    printf("  %d      %10s    %f\n", comidas.id, comidas.descripcion, comidas.precio);

}

void mostrarComidas(eComida comidas[], int tam)
{
    int i;
    printf(" Id   Descripcion   Precio\n\n");
    for(i = 0; i < tam; i++)
    {
        mostrarComida(comidas[i]);
    }
    printf("\n");
}

int cargarDescComida(int id, eComida comidas[], int tam, char desc[])
{
    int i;
    int todoOk = 0;

    for(i = 0; i < tam; i++){
        if( id == comidas[i].id){
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

