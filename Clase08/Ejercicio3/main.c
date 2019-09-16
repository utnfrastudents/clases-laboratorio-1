#include "input.h"

#define TAM 20

typedef struct
{
    int legajo;
    char nombre[TAM];
    int edad;
    char sexo;
    int notaParcial1;
    int notaParcial2;
    float promedio;
} sAlumno;

int main()
{
    input_clearScreen();

    sAlumno alumno1;

    printf("Tamano del alumno: %d\n", (int)sizeof(alumno1));

    printf("Ingrese el legajo: ");
    scanf("%d", &alumno1.legajo);
    printf("El legajo ingresado es: %d\n", alumno1.legajo);

    input_pauseScreen("Presionar Enter para salir del programa...");

    return 0;
}
