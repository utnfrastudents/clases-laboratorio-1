#include "input.h"

#define TAM 20
#define ALUMNOS 2

typedef struct
{
    int dia;
    int mes;
    int ano;
} sFecha;

typedef struct
{
    int legajo;
    char nombre[TAM];
    int edad;
    char sexo;
    int notaParcial1;
    int notaParcial2;
    float promedio;
    sFecha fechaIngreso;
} sAlumno;

int cargarAlumnos(sAlumno vec[], int tam);
void mostrarAlumno(sAlumno alumno);
void mostrarAlumnos(sAlumno vec[], int tam);
void ordenarAlumnosPorLegajo(sAlumno vec[], int tam);
void ordenarAlumnosPorNombre(sAlumno vec[], int tam);
void swapAlumnos(sAlumno alumno1, sAlumno alumno2);
int comparaFecha(sFecha fecha1, sFecha fecha2);

int main()
{
    input_clearScreen();

    sAlumno alumnos[ALUMNOS];
    sAlumno clase1[5] = {
        {1234, "Juan", 20, 'm', 4, 6, 5, {16, 9, 2019}},
        {1111, "Juana", 19, 'f', 7, 4, 5, {20, 9, 2019}},
        {5555, "Ariel", 20, 'm', 8, 6, 7, {12, 9, 2019}},
        {2222, "Alicia", 21, 'f', 9, 6, 7, {9, 9, 2019}},
        {1166, "Nahuel", 30, 'm', 2, 4, 3, {4, 9, 2019}}
    };

    mostrarAlumnos(clase1, 5);

    if(!cargarAlumnos(alumnos, ALUMNOS))
    {
        mostrarAlumnos(alumnos, ALUMNOS);
    }

    input_pauseScreen("Presionar Enter para salir del programa...");

    return 0;
}

int cargarAlumnos(sAlumno vec[], int tam)
{
    int returnValue = -1;
    sAlumno alumnoAux;

    if(tam > 0 && tam <= TAM)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!input_getInt(&alumnoAux.legajo, "Ingrese el legajo: ", "Intente nuevamente: ", 1000, 9999)
                && !input_getString(alumnoAux.nombre, "Ingrese el nombre: ", "Intente nuevamente: ", 1, TAM)
                && !input_getInt(&alumnoAux.edad, "Ingrese la edad: ", "Intente nuevamente: ", 0, 150)
                && !input_getChar(&alumnoAux.sexo, "Ingrese el sexo [f] o [m]: ", "Intente nuevamente: ", 'a', 'z')
                && !input_getInt(&alumnoAux.notaParcial1, "Ingrese primer parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                && !input_getInt(&alumnoAux.notaParcial2, "Ingrese segundo parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                && scanf("%d/%d/%d", &alumnoAux.fechaIngreso.dia, &alumnoAux.fechaIngreso.mes, &alumnoAux.fechaIngreso.ano) == 3)
            {
                vec[i] = alumnoAux;
                printf("Carga exitosa del alumno.\n");
                returnValue = 0;
            }
        }
    }

    return returnValue;
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
    printf("Legajo    Nombre     Edad     Sexo    Parcial[1]     Parcial[2]    Promedio    FechaIngreso\n");
    for(int i = 0; i < tam; i++)
    {
        mostrarAlumno(vec[i]);
    }
}

void ordenarAlumnosPorLegajo(sAlumno vec[], int tam)
{
    //sAlumno alumnoAux;

    if(vec != NULL && tam > 0 && tam < ALUMNOS)
    {

    }
}

void ordenarAlumnosPorNombre(sAlumno vec[], int tam)
{

}

void swapAlumnos(sAlumno alumno1, sAlumno alumno2)
{
    sAlumno alumnoAux = alumno1;
    alumno1 = alumno2;
    alumno2 = alumnoAux;
}

int comparaFecha(sFecha fecha1, sFecha fecha2)
{
    int returnValue;

    if(fecha1.ano == fecha2.ano
        && fecha1.mes == fecha2.mes
        && fecha1.ano == fecha2.ano)
    {
        returnValue = 0;
    }
    else
    {

    }

    return returnValue;
}
