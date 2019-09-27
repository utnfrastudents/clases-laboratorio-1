#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <string.h>
#include <ctype.h>
#include <float.h>
#include "structs.h"

#define STRING_AS_NUMBER_MAX 64 /**< Buffer de entrada maximo para cadenas numericas. >*/
#define STRING_MAX 256 /**< Se define la maxima cantidad de caracteres. >*/
#define EXIT_BUFFER '\0' /**< Valor de terminacion de cadena de caracteres. >*/

/** \brief Funcion de intercambio de numeros enteros.
 * 
 * \param i int* Direccion de memoria del primer numero.
 * \param j int* Direccion de memoria del segundo numero.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapInt(int* i, int* j);

/** \brief Funcion de intercambio de numeros flotantes.
 * 
 * \param i float* Direccion de memoria del primer numero.
 * \param j float* Direccion de memoria del segundo numero.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapFloat(float* i, float* j);

/** \brief Funcion de intercambio de caracteres.
 * 
 * \param i char* Direccion de memoria del primer caracter.
 * \param j char* Direccion de memoria del segundo caracter.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapChar(char* i, char* j);

/** \brief Funcion de intercambio de cadenas de caracteres.
 * 
 * \param string1[] char Primer cadena de caracteres.
 * \param strin2[] char Segunda cadena de caracteres.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapString(char string1[], char string2[]);

/** \brief Valida la concatenacion de dos cadenas
 *      controlando el longitud de la primer cadena por parametro.
 *
 * \param firstString[] char Primer cadena a concatenarse.
 * \param secondString[] char Segunda cadena a concatenarse.
 * \param maxLenght int Longitud maxima para controlar la concatenacion.
 * \return Si pudo realizar la concatenacion retorna [0] si no [-1].
 *
 */
int arrays_concatStrings(char firstString[], char secondString[], int maxLenght);

/** \brief Devuelve la cadena de caracteres en mayusculas.
 * 
 *  \param string[] char Cadena de caracteres a pasar a mayusculas.
 *  \param maxLength int Longitud de la cadena de caracteres.
 *  \return Direccion de memoria de cadena de caracteres pasada a mayusculas.
 * 
 */
char* arrays_stringToUppercase(char string[], int maxLength);

/** \brief Devuelve la cadena de caracteres en minusculas.
 * 
 *  \param string[] char Cadena de caracteres a pasar a minusculas.
 *  \param maxLength int Longitud de la cadena de caracteres.
 *  \return Direccion de memoria de cadena de caracteres pasada a minusculas.
 * 
 */
char* arrays_stringToLowercase(char string[], int maxLength);

/** \brief Devuelve la cadena de caracteres en formato Camel Case.
 * 
 * \param string[] char Cadena de caracteres sin formatear.
 * \param maxLength int Longitud de la cadena de caracteres.
 * \return Direccion de memoria de la cadena formateada en Camel Case. 
 * 
 */
char* arrays_stringToCamelCase(char string[], int maxLength);

#endif // ARRAYS_H_INCLUDED
