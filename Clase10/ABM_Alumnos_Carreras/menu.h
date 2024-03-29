#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "inputs.h"

#define OPTION_MIN 1 /**< Opcion minima en comun de cada menu >*/
#define MAIN_MAX 8 /**< Opcion maxima del menu principal >*/
#define CREATE_MAX 5 /**< Opcion maxima de menu de creacion de Empleado >*/
#define UPDATE_MAX 3 /**< Opcion maxima de menu para modificar un Empleado >*/
#define DELETE_MAX 2 /**< Opcion maxima de menu para dar de baja un Empleado >*/
#define REPORT_MAX 4 /**< Opcion maxima de menu para mostrar informes de Empleados */
#define ORDER_MAX 7
#define OPTION_ERROR -1 /**< Opcion de retorno de error de cada menu >*/
#define ASC 1
#define DESC 2

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario ingrese la opcion elegida
 *
 * \param option int* Opcion elegida del menu
 * \return int Retorna la opcion elegida en el menu
 *
 */
int menu_main(int* option);

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario modifique la carga de un Empleado
 *
 * \param option int* Opcion elegida del menu
 * \return int Retorna la opcion elegida en el menu
 *
 */
int menu_update(int* option);

int menu_order(int* optionMenu, int* optionOrder);

#endif // MENU_H_INCLUDED
