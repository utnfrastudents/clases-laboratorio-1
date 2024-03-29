#include "comidas.h"

int main()
{
    int legajo = 2000;
    int idAlmuerzo = 60000;
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
    sCarrera carreras[TAMC] = {
        {1000, "TUP"},
        {1001, "TUSI"},
        {1002, "LIC"}
    };
    sComida comidas[TAMCOM] = {
        {5000, "Bife", 250},
        {5001, "Fideos", 200},
        {5002, "Pizza", 190},
        {5003, "Arroz", 200},
        {5004, "Milanesa", 220}
    };
    sAlmuerzo almuerzos[TAMAL];

    inicializarAlumnos(alumnos, TAM);
    inicializarAlmuerzos(almuerzos, TAMAL);

    legajo += hardcodearAlumnos(alumnos, TAM, TAM - 1);
    idAlmuerzo += hardcodearAlmuerzos(almuerzos, TAMAL, TAMAL - 1);

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
            case 1: // Opcion elegida: Alta de Alumnos.
                if(altaAlumno(alumnos, TAM, legajo, carreras, TAMC))
                {
                    printf("Carga exitosa del alumno.\n");
                    legajo++;
                }
                break;
            case 2: // Opcion elegida: Modificar un Alumno.
                if(modificarAlumno(alumnos, TAM, carreras, TAMC))
                {
                    printf("Se ha actualiado la nota del alumno.\n");
                }
                break;
            case 3: // Opcion elegida: Dar de baja un Alumno.
                if(bajaAlumno(alumnos, TAM, carreras, TAMC))
                {
                    printf("Alumno borrado.\n");
                }
                break;
            case 4: // Opcion elegida: Mostrar lista de Alumnos.
                inputs_clearScreen();
                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                break;
            case 5: //Opcion elegida: Ordenar listado de Alumnos.
                do
                {
                    lifeCycle = menu_order(&optionOrderMenu, &optionOrderType);

                    if(optionOrderMenu == ORDER_MAX || optionOrderMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionOrderMenu)
                    {
                        case 1: // Opcion elegida: Ordenar por legajo.
                            if(ordenarAlumnosPorLegajo(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 2: // Opcion elegida: Ordenar por nombre.
                            if(ordenarAlumnosPorNombre(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 3: // Opcion elegida: Ordenar por sexo y por edad.
                            if(ordenarAlumnosPorSexoEdad(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 4: // Opcion elegida: Ordenar por promedio.
                            if(ordenarAlumnosPorPromedio(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 5: // Opcion elegida: Ordenar por fecha de ingreso.
                            if(ordenarAlumnosPorFechaIngreso(alumnos, TAM, optionOrderType))
                            {
                                inputs_clearScreen();
                                mostrarAlumnos(alumnos, TAM, carreras, TAMC);
                            }
                            break;
                        case 6: // Opcion elegida: Ordenar por Carrera y nombre.
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
            case 6: //Opcion elegida: Informes de Alumnos.
                do
                {
                    lifeCycle = menu_reports(&optionReportsMenu, &optionCarrera);

                    if(optionReportsMenu == REPORT_MAX || optionReportsMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionReportsMenu)
                    {
                        case 1: // Opcion elegida: Mostrar Alumno por Carrera.
                            inputs_clearScreen();
                            mostrarAlumnosPorCarrera(alumnos, TAM, carreras, TAMC, optionCarrera);
                            break;
                        case 2: // Opcion elegida: Mostrar Alumnos de cada Carrera.
                            inputs_clearScreen();
                            ordenarAlumnosPorCarreraNombre(alumnos, TAM, ASC);
                            mostrarAlumnosTodasLasCarreras(alumnos, TAM, carreras, TAMC);
                            break;
                        case 3: // Opcion elegida: Mostrar cantidad de Alumnos por Carrera.
                            inputs_clearScreen();
                            mostrarCantidadAlumnosPorCarrera(alumnos, TAM, carreras, TAMC);
                            break;
                        case 4: // Opcion elegida: Mostrar Carrera con mas inscriptos.
                            inputs_clearScreen();
                            mostrarCarreraConMasInscriptos(alumnos, TAM, carreras, TAMC);
                            break;
                        case 5: // Opcion elegida: Mostrar el mejor promedio por Carrera.
                            inputs_clearScreen();
                            mostrarMejorPromedioPorCarrera(alumnos, TAM, carreras, TAMC);
                            break;
                        case 6: // Opcion elegida: Mostrar Alumnos Varones.
                            inputs_clearScreen();
                            mostrarAlumnosVarones(alumnos, TAM, carreras, TAMC);
                            break;
                        case 7: // Opcion elegida: Mostrar mujeres por carrera.
                            inputs_clearScreen();
                            mostrarMujeresPorCarrera(alumnos, TAM, carreras, TAMC, optionCarrera);
                            break;
                        case 8:
                            inputs_clearScreen(); // Opcion elegida: Mostrar Alumnos mayores de 30 de licenciatura.
                            mostrarAlumnosMayoresDe30DeLicenciatura(alumnos, TAM, carreras, TAMC);
                            break;
                    }
                    inputs_pauseScreen("Presione la tecla Enter para continuar");
                } while (!lifeCycle);
                break;
            case 7: //Opcion elegida: Mostrar Carreras.
                inputs_clearScreen();
                mostrarCarreras(carreras, TAMC);
                break;
            case 8: //Opcion elegida: Mostrar Comidas.
                inputs_clearScreen();
                mostrarComidas(comidas, TAMCOM);
                break;
            case 9: //Opcion elegida: Mostrar Almuerzos.
                inputs_clearScreen();
                mostrarAlmuerzos(almuerzos, TAMAL, alumnos, TAM, comidas, TAMCOM);
                break;
            case 10: //Opcion elegida: Alta de Almuerzo.
                inputs_clearScreen();
                if(altaAlmuerzo(almuerzos, TAMAL, idAlmuerzo, alumnos, TAM, comidas, TAMCOM, carreras, TAMC))
                {
                    printf("Almuerzo cargado con exito.\n");
                    idAlmuerzo++;
                }
                break;
        }

        inputs_pauseScreen("Presione la tecla Enter para continuar");
    } while (!lifeCycle);

    return 0;
}
