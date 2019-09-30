#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

#include "alumnos.h"

#define TAMCOM 5

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
} sComida;

typedef struct
{
    int id;
    int idAlumno;
    int idComida;
    sDate fecha;
    int isEmpty;
} sAlmuerzo;

void mostrarComida(sComida comida);
void mostrarComidas(sComida comidas[], int len);

#endif // COMIDAS_H_INCLUDED
