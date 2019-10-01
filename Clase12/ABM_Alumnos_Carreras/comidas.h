#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

#include "alumnos.h"

#define TAMCOM 5
#define TAMAL 15
#define NOMBRE_COMIDA 20

typedef struct
{
    int id;
    char descripcion[NOMBRE_COMIDA];
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

void inicializarAlmuerzos(sAlmuerzo almuerzos[], int len);
int hardcodearAlmuerzos(sAlmuerzo almuerzos[], int len, int cantidad);
int buscarAlmuerzoLibre(sAlmuerzo almuerzos[], int len);
int buscarComidaPorId(sComida vec[], int len, int id);
int buscarAlmuerzoPorId(sAlmuerzo almuerzos[], int len, int id);
int altaAlmuerzo(sAlmuerzo almuerzos[], int lenAlmuerzos,
    int id, sAlumno alumnos[], int lenAlumnos, sComida comidas[],
    int lenComidas, sCarrera carreras[], int lenCarreras);
void mostrarComida(sComida comida);
void mostrarComidas(sComida comidas[], int len);
void mostrarAlmuerzo(sAlmuerzo almuerzo, sAlumno alumno, sComida comida);
void mostrarAlmuerzos(sAlmuerzo almuerzos[], int lenAlmuerzos,
    sAlumno alumnos[], int lenAlumnos, sComida comidas[], int lenComidas);

#endif // COMIDAS_H_INCLUDED
