#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

#include "alumnos.h"

#define TAMCOM 5
#define TAMAL 10

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
void inicializarAlmuerzos(sAlmuerzo almuerzos[], int len);
int hardcodearAlmuerzos(sAlmuerzo almuerzos[], int len, int cantidad);
int buscarAlmuerzoLibre(sAlmuerzo almuerzos[], int len);
int buscarAlmuerzoPorId(sAlmuerzo almuerzos[], int len, int id);
int altaAlmuerzo(sAlmuerzo almuerzos[], int lenAlmuerzos,
    int id, sAlumno alumnos[], int lenAlumnos, sComida comidas[],
    int lenComidas, sDate fecha);

#endif // COMIDAS_H_INCLUDED
