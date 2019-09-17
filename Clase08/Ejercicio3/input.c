#include "input.h"

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero decimal.
 *
 * \param stringValue[] char Direccion de la cadena a evaluar.
 * \return int Si es un numero decimal retorna [0] si no [-1].
 *
 */
static int isNumber(char stringValue[]);

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero flontante.
 *
 * \param stringValue[] char Direccion de la cadena a evaluar.
 * \return int Si es un numero flotante retorna [0] si no [-1].
 *
 */
static int isFloat(char stringValue[]);

void input_clearBufferAfter()
{
    /**< Mientras que en el buffer no exista un Enter
    la funcion getchar toma sus valores. */
    while (getchar() != ENTER_CHARACTER)
    {
        /**< No requiere implementacion. */
    }
}

void input_clearScreen()
{
    /**< Para los sistemas basados en UNIX. */
    #if defined (__unix__) || defined (__APPLE__) || defined (__MACH__)
    {
        system("clear");
    }
    #else /**< Para los sistemas basados en WINDOWS. */
    {
        system("cls");
    }
    #endif
}

void input_pauseScreen(char message[])
{
    printf("%s", message);

    setbuf(stdin, NULL); /**< Limpieza de buffer previo. */

    getchar(); /**< Metodo para pausar la ejecucion del programa. */
}

int input_getNumberType(float number)
{
    int returnEvaluation; /**< Se almacena el indicador de tipo de numero. >*/
    float floorNumber; /**< Se almacena la parte entera de un numero. >*/

    floorNumber = floor(number);

    if (number - floorNumber != 0.0f)
    {
        returnEvaluation = 2; /**< Indica tipo de dato flotante. */
    }
    else
    {
        if (number == floorNumber || (float)number == 0)
        {
            returnEvaluation = 1; /**< Indica tipo de dato entero. */
        }
        else /**< No se puede determinar el tipo de numero. */
        {
            returnEvaluation = 0;
        }
    }

    return returnEvaluation;
}

int input_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int returnValue = -1; /**< Variable de retorno. >*/
    int counter = 0; /**< Variable contador de ciclos de solicitudes al usuario. >*/
    int numberIndicator = -1; /**< Variable para almacenar si la cadena ingresada es decimal. >*/
    int convertedNumber; /**< Variable para almacenar la cadena convertida a numero. >*/

    char stringNumber[STRING_AS_NUMBER_MAX]; /**< Variable para almacenar la cadena ingresada por teclado. >*/

    if(hiLimit >= lowLimit && lowLimit >= INT_MIN && hiLimit <= INT_MAX
        && input != NULL && message != NULL && eMessage != NULL)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s", eMessage);
                }
            }

            scanf("%s", stringNumber);

            numberIndicator = isNumber(stringNumber);
            if(!numberIndicator)
            {
                convertedNumber = atoi(stringNumber);
            }
        } while(numberIndicator ||
            (!numberIndicator && (convertedNumber < lowLimit || convertedNumber > hiLimit)));

        if(convertedNumber >= lowLimit && convertedNumber <= hiLimit)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit)
{
    int returnValue = -1; /**< Variable de retorno. >*/
    int counter = 0; /**< Variable contador de ciclos de solicitudes al usuario. >*/
    int numberIndicator = -1; /**< Variable para almacenar si la cadena ingresada es flotante. >*/

    float convertedNumber; /**< Variable para almacenar la cadena convertida a numero. >*/

    char stringNumber[STRING_AS_NUMBER_MAX]; /**< Variable para almacenar la cadena ingresada por teclado. >*/

    if(hiLimit >= lowLimit && lowLimit >= FLT_MIN && hiLimit <= FLT_MAX
        && input != NULL && message != NULL && eMessage != NULL)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s: ", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s: ", eMessage);
                }
            }

            scanf("%s", stringNumber);

            numberIndicator = isFloat(stringNumber);
            if(!numberIndicator)
            {
                convertedNumber = atof(stringNumber);
            }
        } while(numberIndicator ||
            (!numberIndicator && (convertedNumber < lowLimit || convertedNumber > hiLimit)));

        if(convertedNumber >= lowLimit && convertedNumber <= hiLimit)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    int returnValue = -1; /**< Variable de retorno. >*/
    int counter = 0; /**< Variable contador de ciclos de solicitudes al usuario. >*/

    char charValue; /**< Variable para almacenar el caracter ingresado por teclado. >*/

    if(input != NULL && message != NULL && eMessage != NULL
        && (int)hiLimit >= (int)lowLimit
        && isalpha(lowLimit) && isalpha(hiLimit))
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s: ", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s: ", eMessage);
                }
            }

            setbuf(stdin, NULL); /**< Limpieza de buffer previo. */
            scanf("%c", &charValue);
        } while((int)charValue < (int)lowLimit || (int)charValue > (int)hiLimit);

        if((int)charValue >= (int)lowLimit && (int)charValue <= (int)hiLimit)
        {
            *input = charValue;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int returnValue = -1; /**< Variable de retorno. >*/
    int counter = 0; /**< Variable contador de ciclos de solicitudes al usuario. >*/
    int sizeScan = 0; /**< Variable para almacenar el tamano de la cadena ingresada. >*/

    char auxMessage[STRING_MAX]; /**< Variable para almacenar la cadena ingresada por teclado. >*/

    if(input != NULL && message != NULL && eMessage != NULL
        && hiLimit >= lowLimit && hiLimit < STRING_MAX && lowLimit > 0)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s", eMessage);
                }
            }

            setbuf(stdin, NULL); /**< Limpieza de buffer previo. */
            if(scanf("%[^\n]s", auxMessage)) /**< Metodo para escanear la cadena completa con espacios */
            {
                sizeScan = strlen(auxMessage);
            }
            else
            {
                continue;
            }
        } while(sizeScan < lowLimit || sizeScan > hiLimit);

        if(sizeScan >= lowLimit && sizeScan <= hiLimit
            && sizeScan > 0 && hiLimit < STRING_MAX)
        {
            /**< Se controla el uso de memoria agregando el caracter terminador. */
            auxMessage[STRING_MAX-1] = EXIT_BUFFER;

            strcpy(input, auxMessage);

            returnValue = 0;
        }
    }

    return returnValue;
}

int input_concatStrings(char firstString[], char secondString[], int maxLenght)
{
    int returnValue = -1;

    if(firstString != NULL && secondString != NULL
        && (strlen(firstString) + strlen(secondString)) < maxLenght
        && maxLenght < STRING_MAX && maxLenght > 0)
    {
        strncat(firstString, secondString, maxLenght);

        /**< Se controla el uso de memoria agregando el caracter terminador. */
        firstString[maxLenght] = EXIT_BUFFER;

        returnValue = 0;
    }

    return returnValue;
}

char* input_stringToUppercase(char string[], int maxLength)
{
    char* auxString = string;
    int i = 0;

    if(string != NULL && maxLength < STRING_MAX && maxLength > 0)
    {
        while(i <= maxLength || auxString[i] == EXIT_BUFFER)
        {
            auxString[i] = toupper((char)auxString[i]);
            i++;
        }

        auxString[maxLength] = EXIT_BUFFER;
    }

    return auxString;
}

char* input_stringToLowercase(char string[], int maxLength)
{
    char* auxString = string;
    int i = 0;

    if(string != NULL && maxLength < STRING_MAX && maxLength > 0)
    {
        while(i <= maxLength || auxString[i] == EXIT_BUFFER)
        {
            auxString[i] = tolower((char)auxString[i]);
            i++;
        }

        auxString[maxLength] = EXIT_BUFFER;
    }

    return auxString;
}

void input_printNumberByType(char message[], float number)
{
    switch (input_getNumberType(number))
    {
        case 1:
            /**< Se imprime en consola el numero como entero */
            printf("%s %.0lf\n", message, number);
            break;
        case 2:
            /**< Se imprime en consola el numero como flotante con tres decimales */
            printf("%s %.3lf\n", message, number);
            break;
    }
}

static int isNumber(char stringValue[])
{
    int returnValue = -1;  /**< Variable de retorno. >*/
    int i = 0; /**< Variable contador de ciclos de cada caracter de la cadena. >*/

    char charAux; /**< Variable para almacenar el caracter actual del ciclo. >*/

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        charAux = stringValue[i];
        if(i == 0 && (charAux == '-' || charAux == '+'))
        {
            i = 1;
        }

        if((int)charAux >= (int)'0' && (int)charAux <= (int)'9')
        {
            returnValue = 0;
        }
        else
        {
            returnValue = -1;
            break;
        }
        i++;
    }

    return returnValue;
}

static int isFloat(char stringValue[])
{
    int returnValue = -1;  /**< Variable de retorno. >*/
    int i = 0; /**< Variable contador de ciclos de cada caracter de la cadena. >*/
    int pointerCounter = 0; /**< Variable para almacenar la cantidad de puntos de la cadena. >*/

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        if(i == 0 && ((int)stringValue[0] == (int)'-'
        || (int)stringValue[0] == (int)'+'))
        {
            i = 1;
        }

        if(stringValue[i] == '.')
        {
            pointerCounter++;
        }
        else
        {
            if((int)stringValue[i] >= (int)'0'
                && (int)stringValue[i] <= (int)'9' && pointerCounter <= 1)
            {
                returnValue = 0;
            }
            else
            {
                returnValue = -1;
                break;
            }
        }
        i++;
    }

    return returnValue;
}
