#include "alumno.h"

sAlumno newAlumno(int legajo, char nombre[TAM], int edad, char sexo,
    int notaParcial1, int notaParcial2, sFecha fechaIngreso);

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
            if(vec[i].legajo == legajo
                && vec[i].isEmpty == ALUMNO_CARGADO)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int altaAlumno(sAlumno vec[], int tam)
{
    int returnValue = 0;
    sAlumno alumnoAux;
    int indiceAlumno;
    int legajoExistente;

    if(vec != NULL && tam > 0)
    {
        indiceAlumno = buscarAlumnoLibre(vec, tam);

        if(indiceAlumno != -1)
        {
            if(!input_getInt(&alumnoAux.legajo, "Ingrese el legajo: ", "Intente nuevamente: ", 1000, 9999))
            {
                legajoExistente = buscarAlumnoPorLegajo(vec, tam, alumnoAux.legajo);
                if(legajoExistente != -1)
                {
                    printf("El legajo ya se encuentra registrado.\n");
                    mostrarAlumno(vec[legajoExistente]);
                }
                else
                {
                    if(!input_getString(alumnoAux.nombre, "Ingrese el nombre: ", "Intente nuevamente: ", 1, NOMBRE)
                        && !input_getInt(&alumnoAux.edad, "Ingrese la edad: ", "Intente nuevamente: ", 0, 150)
                        && !input_getChar(&alumnoAux.sexo, "Ingrese el sexo [f] o [m]: ", "Intente nuevamente: ", 'a', 'z')
                        && !input_getInt(&alumnoAux.notaParcial1, "Ingrese primer parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                        && !input_getInt(&alumnoAux.notaParcial2, "Ingrese segundo parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                        && scanf("%d/%d/%d", &alumnoAux.fechaIngreso.dia, &alumnoAux.fechaIngreso.mes, &alumnoAux.fechaIngreso.ano) == 3)
                    {
                        vec[indiceAlumno] = newAlumno(alumnoAux.legajo, alumnoAux.nombre, alumnoAux.edad,
                            alumnoAux.sexo, alumnoAux.notaParcial1, alumnoAux.notaParcial2, alumnoAux.fechaIngreso);
                        returnValue = 1;
                    }
                }
            }
        }
        else
        {
            printf("Sistema de alumnos completo.\n");
        }
    }

    return returnValue;
}

void mostrarAlumno(sAlumno alumno)
{
    printf("%d     %20s      %3d     %c      %2d     %2d     %.2f   %02d/%02d/%4d\n",
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

sAlumno newAlumno(int legajo, char nombre[NOMBRE], int edad, char sexo,
    int notaParcial1, int notaParcial2, sFecha fechaIngreso)
{
    sAlumno alumnoAux;

    alumnoAux.legajo = legajo;
    strncpy(alumnoAux.nombre, nombre, NOMBRE);
    alumnoAux.edad = edad;
    alumnoAux.sexo = sexo;
    alumnoAux.notaParcial1 = notaParcial1;
    alumnoAux.notaParcial2 = notaParcial2;
    alumnoAux.fechaIngreso = fechaIngreso;
    alumnoAux.promedio = (float)(notaParcial1 + notaParcial2)/2;
    alumnoAux.isEmpty = ALUMNO_CARGADO;

    return alumnoAux;
}
