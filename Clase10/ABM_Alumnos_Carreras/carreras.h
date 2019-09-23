#ifndef CARRERAS_H_INCLUDED
#define CARRERAS_H_INCLUDED

#include "inputs.h"

#define NOM_CARRERA 5
#define TAMC 3

typedef struct
{
    int idCarrera;
    char descripcion[NOM_CARRERA];
} sCarrera;

void mostrarCarrera(sCarrera carrera);
void mostrarCarreras(sCarrera vec[], int tam);

#endif // CARRERAS_H_INCLUDED
