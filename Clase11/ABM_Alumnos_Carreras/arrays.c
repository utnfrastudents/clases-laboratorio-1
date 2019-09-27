#include "arrays.h"

int arrays_swapInt(int* i, int* j)
{
    int returnValue = -1;
    int aux1;
    int aux2;

    aux1 = *i;
    aux2 = *j;
    *i = *j;
    *j = aux1;

    if(*i == aux2 && *j == aux1)
    {
        returnValue = 0;
    }

    return returnValue;
}

int arrays_swapFloat(float* i, float* j)
{
    int returnValue = -1;
    float aux1;
    float aux2;

    aux1 = *i;
    aux2 = *j;
    *i = *j;
    *j = aux1;

    if(*i == aux2 && *j == aux1)
    {
        returnValue = 0;
    }

    return returnValue;
}

int arrays_swapChar(char* i, char* j)
{
    int returnValue = -1;
    char aux1;
    char aux2;

    aux1 = *i;
    aux2 = *j;
    *i = *j;
    *j = aux1;

    if(*i == aux2 && *j == aux1)
    {
        returnValue = 0;
    }

    return returnValue;
}

int arrays_swapString(char string1[], char string2[])
{
    int returnValue = -1;
    char aux1[STRING_MAX];
    char aux2[STRING_MAX];

    if(string1 != NULL && string2 != NULL)
    {
        strcpy(aux1, string1);
        strcpy(aux2, string2);
        strcpy(string1, string2);
        strcpy(string2, aux1);

        if(!strcmp(string1, aux2) && !strcmp(string2, aux1))
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

int arrays_concatStrings(char firstString[], char secondString[], int maxLenght)
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

char* arrays_stringToUppercase(char string[], int maxLength)
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

char* arrays_stringToLowercase(char string[], int maxLength)
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

char* arrays_stringToCamelCase(char string[], int maxLength)
{
    char* auxString = string;
    int position = 0;

    if(string != NULL && maxLength > 0 && maxLength <= STRING_MAX)
    {
        while(position <= maxLength && auxString[position] != EXIT_BUFFER)
        {
            if((position == 0 && auxString[position] != ' ')
                || (position > 0 && auxString[position - 1] == ' ' && auxString[position] != ' '))
            {
                auxString[position] = toupper((char)auxString[position]);
            }
            else
            {
                auxString[position] = tolower((char)auxString[position]);
            }

            position++;
        }

        auxString[position] = EXIT_BUFFER;
    }

    return auxString;
}
