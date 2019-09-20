#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    input_clearScreen();

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

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_create(int* option)
{
    int returnValue = -1;

    input_clearScreen();

    printf("=======================================================\n");
    printf("                ALTA DE EMPLEADO\n");
    printf("=======================================================\n");
    printf("    1 - Ingresar el Nombre\n");
    printf("    2 - Ingresar el Apellido\n");
    printf("    3 - Ingresar el salario\n");
    printf("    4 - Ingresar el Sector\n");
    printf("    5 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, CREATE_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_update(int* option)
{
    int returnValue = -1;

    input_clearScreen();

    printf("=======================================================\n");
    printf("                MODIFICAR EMPLEADO\n");
    printf("=======================================================\n");
    printf("    1 - Modificar el Nombre\n");
    printf("    2 - Modificar el Apellido\n");
    printf("    3 - Modificar el salario\n");
    printf("    4 - Modificar el Sector\n");
    printf("    5 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, UPDATE_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_delete(int* option)
{
    int returnValue = -1;

    input_clearScreen();

    printf("=======================================================\n");
    printf("                BAJA DE EMPLEADO\n");
    printf("=======================================================\n");
    printf("    1 - Ingresar el ID del Empleado a dar de baja\n");
    printf("    2 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, DELETE_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_printReports(int* option)
{
    int returnValue = -1;

    input_clearScreen();

    printf("=======================================================\n");
    printf("                INFORMES DE EMPLEADO\n");
    printf("=======================================================\n");
    printf("    1 - Listado ordenado de Empleados\n");
    printf("    2 - Total y promedio de salarios de Empleados\n");
    printf("    3 - Empleados que superan el salario promedio\n");
    printf("    4 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, REPORT_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}
