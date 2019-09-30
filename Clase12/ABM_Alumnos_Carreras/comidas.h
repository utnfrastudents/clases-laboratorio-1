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

#endif // COMIDAS_H_INCLUDED
