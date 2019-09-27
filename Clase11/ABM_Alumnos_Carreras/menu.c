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
    printf("    7 - Mostrar Carreras\n");
    printf("    8 - Salir\n");
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
    printf("    1 - Modificar la Nota 1\n");
    printf("    2 - Modificar la Nota 2\n");
    printf("    3 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ",
        "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, UPDATE_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_order(int* optionMenu, int* optionOrder)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf("=======================================================\n");
    printf("              ORDENAR LISTADO DE ALUMNOS\n");
    printf("=======================================================\n");
    printf("    1 - Ordenar por Legajo\n");
    printf("    2 - Ordenar por Nombre\n");
    printf("    3 - Ordenar por Sexo y por Edad\n");
    printf("    4 - Ordenar por Promedio\n");
    printf("    5 - Ordenar por Fecha de Ingreso\n");
    printf("    6 - Ordenar por Carrera y por Nombre\n");
    printf("    7 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!inputs_getInt(optionMenu, "Elija una opcion del menu: ",
            "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, ORDER_MAX))
    {
        if(*optionMenu == ORDER_MAX
            || !inputs_getInt(optionOrder, "Elija orden [1] ascendente o [2] desdendente: ",
            "Opcion incorrecta, ingrese nuevamente: ", ASC, DESC))
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

int menu_reports(int* optionMenu, int* optionReport)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf("=======================================================\n");
    printf("                      INFORMES\n");
    printf("=======================================================\n");
    printf("    1 - Mostrar Alumnos de una Carrera\n");
    printf("    2 - Mostrar Alumnos por Carrera\n");
    printf("    3 - Mostrar Cantidad de alumnos por Carrera\n");
    printf("    4 - Mostrar La Carrera con mas inscriptos\n");
    printf("    5 - Mostrar Mejor Promedio por Carrera\n");
    printf("    6 - Mostrar Alumnos Varones\n");
    printf("    7 - Mostrar Mujeres de Alguna Carrera\n");
    printf("    8 - Mostrar Alumnos mayores a 30 de Licenciatura\n");
    printf("    9 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!inputs_getInt(optionMenu, "Elija una opcion del menu: ",
        "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, REPORT_MAX))
    {
        if(*optionMenu == REPORT_MAX
            || !inputs_getInt(optionReport, "Coloque el numero de la carrera: ",
            "Opcion incorrecta, ingrese nuevamente: ", 1000, 1002))
        {
            returnValue = 0;
        }
    }

    return returnValue;
}
