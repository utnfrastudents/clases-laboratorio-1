#include "alumnos.h"

int main()
{
    int legajo = 2000;
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu >*/
    int optionMainMenu; /**< Opcion elegida por el usuario del menu principal >*/
//    int optionCreateMenu; /**< Opcion elegida por el usuario para el menu de alta >*/
//    int optionUpdateMenu; /**< Opcion elegida por el usuario para el menu de modificacion >*/
//    int optionDeleteMenu; /**< Opcion elegida por el usuario para el menu de eliminacion >*/
//    int optionReportMenu; /**< Opcion elegida por el usuario para el menu de reportes >*/
    int optionOrderMenu;
    int optionOrderType;
    int optionReportsMenu;
    int optionCarrera;

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
            case 3: // Opcion elegida: Dar de baja un Empleado
                if(bajaAlumno(alumnos, TAM, carreras, TAMC))
                {
                    printf("Alumno borrado.\n");
                }
                break;
            case 4: // Opcion elegida: Mostrar lista de Empleados
                inputs_clearScreen();
                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                break;
            case 5: //Opcion elegida: Ordenar listado de Empleados
                do
                {
                    lifeCycle = menu_order(&optionOrderMenu, &optionOrderType);

                    if(optionOrderMenu == ORDER_MAX || optionOrderMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionOrderMenu)
                    {
                        case 1: // Opcion elegida: Ordenar por legajo
                            if(ordenarAlumnosPorLegajo(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 2: // Opcion elegida: Ordenar por nombre
                            if(ordenarAlumnosPorNombre(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 3: // Opcion elegida: Ordenar por sexo y por edad
                            if(ordenarAlumnosPorSexoEdad(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 4: // Opcion elegida: Ordenar por promedio
                            if(ordenarAlumnosPorPromedio(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 5: // Opcion elegida: Ordenar por fecha de ingreso
                            if(ordenarAlumnosPorFechaIngreso(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 6: // Opcion elegida: Ordenar por carrera y nombre
                            if(ordenarAlumnosPorCarreraNombre(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                    }

                    inputs_pauseScreen("Presione la tecla Enter para continuar");
                } while (!lifeCycle);
                break;
            case 6:
                do
                {
                    lifeCycle = menu_reports(&optionReportsMenu, &optionCarrera);

                    if(optionReportsMenu == REPORT_MAX || optionReportsMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionReportsMenu)
                    {
                        case 1: // Opcion elegida: Mostrar alumno por carrera
                            inputs_clearScreen();
                            mostrarAlumnosPorCarrera(alumnos, TAM, carreras, TAMC, optionCarrera);
                            break;
                        case 2: // Opcion elegida: Mostrar alumnos de cada carrera
                            inputs_clearScreen();
                            ordenarAlumnosPorCarreraNombre(alumnos, TAM, ASC);
                            mostrarAlumnosTodasLasCarreras(alumnos, TAM, carreras, TAMC);
                            break;
                        case 3:
                            inputs_clearScreen();
                            mostrarCantidadAlumnosPorCarrera(alumnos, TAM, carreras, TAMC);
                            break;
                    }

                    inputs_pauseScreen("Presione la tecla Enter para continuar");
                } while (!lifeCycle);
                break;
            case 7:
                mostrarCarreras(carreras, TAMC);
                break;
        }

        inputs_pauseScreen("Presione la tecla Enter para continuar");
    } while (!lifeCycle);

    return 0;
}
