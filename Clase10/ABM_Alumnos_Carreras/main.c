#include "alumnos.h"

int main()
{
    int legajo = 2000;
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu >*/
    int optionMainMenu; /**< Opcion elegida por el usuario del menu principal >*/
//    int optionCreateMenu; /**< Opcion elegida por el usuario para el menu de alta >*/
    int optionUpdateMenu; /**< Opcion elegida por el usuario para el menu de modificacion >*/
//    int optionDeleteMenu; /**< Opcion elegida por el usuario para el menu de eliminacion >*/
//    int optionReportMenu; /**< Opcion elegida por el usuario para el menu de reportes >*/

    sAlumno alumnos[TAM];
    sCarrera carreras[TAMC] = {{1000, "TUP"}, {1001, "TUSI"}, {1002, "LIC"}};

    inicializarAlumnos(alumnos, TAM);

    legajo += hardcodearAlumnos(alumnos, TAM, 9);

    do
    {
        lifeCycle = menu_main(&optionMainMenu);

        if(optionMainMenu == MAIN_MAX || optionMainMenu == OPTION_ERROR)
        {
            inputs_pauseScreen("Presione la tecla Enter para salir del programa");
            break;
        }

        switch (optionMainMenu)
        {
            case 1: // Opcion elegida: Alta de Empleado
                if(altaAlumno(alumnos, TAM, legajo, carreras, TAMC))
                {
                    printf("Carga exitosa del alumno.\n");
                    legajo++;
                }
                break;
            case 2: // Opcion elegida: Modificar un Empleado
                if(modificarAlumno(alumnos, TAM, carreras, TAMC))
                {
                    printf("Se ha actualiado la nota del alumno.\n");
                }
                break;
            case 3:
                if(bajaAlumno(alumnos, TAM, carreras, TAMC))
                {
                    printf("Alumno borrado.\n");
                }
                break;
            case 4:
                inputs_clearScreen();
                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                break;
            case 7:
                mostrarCarreras(carreras, TAMC);
                break;
        }

        inputs_pauseScreen("Presione la tecla Enter para continuar");
    } while (!lifeCycle);

    return 0;
}

