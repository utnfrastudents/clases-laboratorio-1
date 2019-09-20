#include "alumno.h"

void inicializarAlumnos(sAlumno vec[], int tam)
{
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = ALUMNO_VACIO;
        }
    }
}

int buscarAlumnoLibre(sAlumno vec[], int tam)
{
    int indice = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == ALUMNO_VACIO)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int buscarAlumnoPorLegajo(sAlumno vec[], int tam, int legajo)
{
    int indice = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(vec[i].legajo == legajo)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

void mostrarAlumno(sAlumno alumno)
{
    alumno.promedio = (float)(alumno.notaParcial1 + alumno.notaParcial2)/2;

    printf("%d     %10s      %3d     %c      %2d     %2d     %.2f   %02d/%02d/%04d\n",
        alumno.legajo, alumno.nombre, alumno.edad, alumno.sexo,
        alumno.notaParcial1, alumno.notaParcial2, alumno.promedio,
        alumno.fechaIngreso.dia, alumno.fechaIngreso.mes, alumno.fechaIngreso.ano);
}

void mostrarAlumnos(sAlumno vec[], int tam)
{
    int flag = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == ALUMNO_CARGADO)
            {
                mostrarAlumno(vec[i]);
                flag = 1;
            }
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos que mostrar.\n");
    }
}
