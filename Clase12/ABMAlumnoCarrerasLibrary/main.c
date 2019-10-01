#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carrera.h"
#include "alumno.h"
#include "comida.h"
#define TAM 10
#define TAMC 3
#define TAMCOM 5

int menu();
int menuInformes();
void mostrarInformes(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC);
int main()
{
    int legajo = 20000;
    eCarrera carreras[TAMC] = {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};
    eComida comidas[TAMCOM] = {{5000, "Bife", 250}, {5001, "Fideos", 200}, {5002, "Pizza", 190}, {5003, "Arroz", 200}, {5003, "Milanesa", 300}};
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);

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

        case 8: mostrarComidas(comidas, TAMCOM);
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
    printf("8-Mostrar Comidas\n\n");
    printf("9- \n\n");
    printf("10-\n\n");
    printf("11-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    printf("*****Informes*****\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de Alumnos por Carrera\n");
    printf("4-Mostrar la Carrera con mas inscriptos\n");
    printf("5-Mostrar Mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna Carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("9-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;

}
void mostrarInformes(eAlumno alumnos[], int tam, eCarrera carreras[], int tamC){


    char salir = 'n';

    do
    {
        switch( menuInformes())
        {
            case 1:
                    mostrarAlumnosCarreraSeleccionada(alumnos, tam, carreras, tamC);
                    break;

            case 2:
                    mostrarAlumnosDeTodasLasCarreras(alumnos, tam, carreras, tamC);
                    break;

        case 3:
              printf("Informe 3\n");
            break;

        case 4:
             printf("Informe 4\n");
            break;

        case 5:

              printf("Informe 5\n");
            break;

        case 6:
             printf("Informe 6\n");
            break;
        case 7:
              printf("Informe 7\n");
            break;
         case 8:
              printf("Informe 8\n");
            break;


        case 9:
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
}
