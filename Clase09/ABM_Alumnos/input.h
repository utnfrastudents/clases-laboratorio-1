#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define ENTER_CHARACTER '\n' /**< Caracter de tecla enter por teclado. >*/
#define EXIT_BUFFER '\0' /**< Valor de terminacion de cadena de caracteres. >*/
#define STRING_AS_NUMBER_MAX 64 /**< Buffer de entrada maximo para cadenas numericas. >*/
#define STRING_MAX 256 /**< Se define la maxima cantidad de caracteres. >*/

/** \brief Funcion que limpia el buffer de entrada a posterior del ingreso por teclado.
 *
 * \param void No requiere parametros.
 * \return void No retorna valores.
 *
 */
void input_clearBufferAfter(void);

/** \brief Funcion que limpia la pantalla de la consola en los diferentes SO.
 *
 * \param void No requiere paramteros.
 * \return void No retorna valores.
 *
 */
void input_clearScreen(void);

/** \brief Funcion que interrumpe la ejecucion del programa
 *      hasta que se presiona la tecla Enter.
 *
 * \param message[] char Es el mensaje a ser mostrado.
 * \return void No retorna valores.
 *
 */
void input_pauseScreen(char message[]);

/** \brief Solicita un numero flotante al usuario e indica su tipo.
 *
 * \param number float Numero con o sin decimales a evaluar.
 * \return int
 *      Si devuelve [0] no puede reconocer el tipo.
 *      Si devuelve [1] el numero es de tipo entero.
 *      Si devuelve [2] el numero es de tipo flotante.
 *
 */
int input_getNumberType(float number);

/** \brief Solicita un numero al usuario y lo valida.
 *
 * \param input* int Se carga el numero ingresado.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Limite inferior a validar.
 * \param hiLimit int Limite superior a validar.
 * \return int Si obtuvo el numero [0] si no [-1].
 *
 */
int input_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/** \brief Solicita un numero flotante al usuario y lo valida.
 *
 * \param input* float Se carga el numero flotante ingresado.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit float Limite inferior a validar.
 * \param hiLimit float Limite superior a validar.
 * \return int Si obtuvo el numero [0] si no [-1].
 *
 */
int input_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit);


/** \brief Solicita un caracter al usuario y lo valida.
 *
 * \param input char* Se carga el caracter ingresado.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit char Limite inferior a validar.
 * \param hiLimit char Limite superior a validar.
 * \return int Si obtuvo el caracter [0] si no [-1].
 *
 */
int input_getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit);

/** \brief Solicita una cadena de caracteres al usuario y la valida.
 *
 * \param input char* Se carga el string ingresado.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Longitud mínima de la cadena.
 * \param hiLimit int Longitud máxima de la cadena.
 * \return int Si obtuvo la cadena [0] si no [-1].
 *
 */
int input_getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/** \brief Valida la concatenacion de dos cadenas
 *      controlando el longitud de la primer cadena por parametro.
 *
 * \param firstString[] char Primer cadena a concatenarse.
 * \param secondString[] char Segunda cadena a concatenarse.
 * \param maxLenght int Longitud maxima para controlar la concatenacion.
 * \return void Si pudo realizar la concatenacion retorna [0] si no [-1].
 *
 */
int input_concatStrings(char firstString[], char secondString[], int maxLenght);

/** \brief Devuelve la cadena de caracteres en mayusculas.
 * 
 *  \param string[] char Cadena de caracteres a pasar a mayusculas.
 *  \param maxLength int Longitud maxima a pasar a mayusculas.
 *  \return char* Puntero a cadena de caracteres pasada a mayusculas.
 * 
 */
char* input_stringToUppercase(char string[], int maxLength);

/** \brief Devuelve la cadena de caracteres en minusculas.
 * 
 *  \param string[] char Cadena de caracteres a pasar a minusculas.
 *  \param maxLength int Longitud maxima a pasar a minusculas.
 *  \return char* Puntero a cadena de caracteres pasada a minusculas.
 * 
 */
char* input_stringToLowercase(char string[], int maxLength);

/** \brief Funcion que imprime un numero en pantalla segun su tipo.
 *
 * \param message[] char Mensaje a imprimir antes del numero.
 * \param number float Numero con o sin decimales a imprimir.
 * \return void No retorna valores.
 *
 */
void input_printNumberByType(char message[], float number);

#endif // INPUT_H_INCLUDED
