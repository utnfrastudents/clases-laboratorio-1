#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

#include "carreras.h"

#define ALUMNOS 2
#define ALUMNO_VACIO 1
#define ALUMNO_CARGADO 0
#define TAM 10
#define NOMBRE 50

typedef struct
{
    int legajo;
    char nombre[NOMBRE];
    int edad;
    char sexo;
    int notaParcial1;
    int notaParcial2;
    float promedio;
    sDate fechaIngreso;
    int idCarrera;
    int isEmpty;
} sAlumno;

void inicializarAlumnos(sAlumno vec[], int tam);
int buscarAlumnoLibre(sAlumno vec[], int tam);
int buscarAlumnoPorLegajo(sAlumno vec[], int tam, int legajo);
int altaAlumno(sAlumno vec[], int tam, int legajo, sCarrera carreras[], int tam_carreras);
int bajaAlumno(sAlumno vec[], int tam, sCarrera carreras[], int tam_carreras);
int modificarAlumno(sAlumno vec[], int tam, sCarrera carreras[], int tam_carreras);
int ordenarAlumnosPorLegajo(sAlumno vec[], int tam, int criterio);
int ordenarAlumnosPorNombre(sAlumno vec[], int tam, int criterio);
int ordenarAlumnosPorSexoEdad(sAlumno vec[], int tam, int criterioEdad);
int ordenarAlumnosPorPromedio(sAlumno vec[], int tam, int criterio);
int ordenarAlumnosPorFechaIngreso(sAlumno vec[], int tam, int criterio);
int ordenarAlumnosPorCarreraNombre(sAlumno vec[], int tam, int criterioNombre);
void mostrarAlumno(sAlumno alumno, sCarrera vec[], int tam);
void mostrarAlumnos(sAlumno vec[], int tam, sCarrera carreras[], int tam_carreras);
int hardcodearAlumnos(sAlumno vec[], int tam, int cantidad);

#endif // ALUMNOS_H_INCLUDED
