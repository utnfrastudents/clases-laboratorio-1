#include "alumno.h"

#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
}eComida;

typedef struct
{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;

void mostrarComida(eComida comidas);
void mostrarComidas(eComida comidas[], int tam);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);
#endif // COMIDA_H_INCLUDED
