#include "menu.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu >*/
    int optionMainMenu; /**< Opcion elegida por el usuario del menu principal >*/
//    int optionCreateMenu; /**< Opcion elegida por el usuario para el menu de alta >*/
    int optionUpdateMenu; /**< Opcion elegida por el usuario para el menu de modificacion >*/
//    int optionDeleteMenu; /**< Opcion elegida por el usuario para el menu de eliminacion >*/
//    int optionReportMenu; /**< Opcion elegida por el usuario para el menu de reportes >*/

    sAlumno alumnos[TAM] = {
        {1234, "Juan", 20, 'm', 4, 6, 5, {16, 9, 2019}, 0},
        {1111, "Juana", 19, 'f', 7, 4, 5, {20, 9, 2019}, 0},
        {5555, "Ariel", 20, 'm', 8, 6, 7, {12, 9, 2019}, 0},
        {2222, "Alicia", 21, 'f', 9, 6, 7, {9, 9, 2019}, 0},
        {1166, "Nahuel", 30, 'm', 2, 4, 3, {4, 9, 2019}, 0}
    };

//    inicializarAlumnos(alumnos, TAM);

    do
    {
        lifeCycle = menu_main(&optionMainMenu);

        if(optionMainMenu == MAIN_MAX || optionMainMenu == OPTION_ERROR)
        {
            input_pauseScreen("Presione la tecla Enter para salir del programa");
            break;
        }

        switch (optionMainMenu)
        {
            case 1: // Opcion elegida: Alta de Empleado
                if(altaAlumno(alumnos, TAM))
                {
                    printf("Carga exitosa del alumno.\n");
                }
                break;
            case 2: // Opcion elegida: Modificar un Empleado
                do
                {
                    lifeCycle = menu_update(&optionUpdateMenu);

                    if(optionUpdateMenu == UPDATE_MAX || optionUpdateMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionUpdateMenu)
                    {
                        case 1: // Opcion elegida: Ingreso del Nombre
                            /* code */
                            break;
                    }

                    input_pauseScreen("Presione la tecla Enter para continuar");
                } while (!lifeCycle);
                break;
            case 3:
                if(bajaAlumno(alumnos, TAM))
                {
                    printf("Alumno borrado.\n");
                }
                break;
            case 4:
                mostrarAlumnos(alumnos, TAM);
                break;
        }

        input_pauseScreen("Presione la tecla Enter para continuar");
    } while (!lifeCycle);

    return 0;
}

