#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "alumno.h"
#include "carrera.h"
#include "informes.h"
#include "comidas.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMAL 20

int menu();


int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM]= {{5000, "Bife", 250},
        {5001, "Fideos", 200},
        {5002, "Pizza", 190},
        {5003, "Arroz", 200},
        {5004, "Milanesa", 220}
    };
    eAlumno lista[TAM];
    eAlmuerzo almuerzos[TAMAL];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);
    inicializarAlmuerzos( almuerzos, TAMAL);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);
    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMAL, 10);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM, carreras, TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;

        case 5:
            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            mostrarInformes(lista, TAM, carreras, TAMC);
            break;

        case 7:
            mostrarCarreras(carreras, TAMC);
            break;

        case 8:
            mostrarComidas(comidas, TAMCOM);
            break;

        case 9:
            mostrarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM);
            break;

        case 10:
            if(altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, comidas, TAMCOM, lista, TAM, carreras, TAMC))
            {
                idAlmuerzo++;
            }
            break;


        case 11:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar Carreras\n");
    printf("8-Mostrar Comidas\n");
    printf("9-Mostrar Almuerzos\n");
    printf("10-Alta Almuerzo\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



