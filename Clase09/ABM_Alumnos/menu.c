#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf("=======================================================\n");
    printf("                MENU DE ALUMNOS\n");
    printf("=======================================================\n");
    printf("    1 - Alta de Alumno\n");
    printf("    2 - Modificar Alumno\n");
    printf("    3 - Baja de Alumno\n");
    printf("    4 - Listar Alumnos\n");
    printf("    5 - Ordenar Alumnos\n");
    printf("    6 - Informes Alumnos\n");
    printf("    7 - Salir\n");
    printf("=======================================================\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ",
        "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_update(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf("=======================================================\n");
    printf("                MODIFICAR ALUMNO\n");
    printf("=======================================================\n");
    printf("    1 - Modificar el Nombre\n");
    printf("    2 - Modificar el Sexo\n");
    printf("    3 - Modificar la Nota 1\n");
    printf("    4 - Modificar la Nota 2\n");
    printf("    5 - Modificar la Fecha de Ingreso\n");
    printf("    6 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ",
        "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, UPDATE_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}
