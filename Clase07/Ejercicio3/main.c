#include "input.h"
#define FULL_NAME 100

char* stringCamelCase(char string[], int maxLength);

int main()
{
    char name[FULL_NAME];
    char lastName[FULL_NAME];

    input_clearScreen();

    if(!input_getString(name, "Ingrese su nombre: ", "Intente nuevamente: ", 1, FULL_NAME)
        && !input_getString(lastName, "Ingrese su apellido: ", "Intente nuevamente: ", 1, FULL_NAME))
    {
        if(!input_concatStrings(stringCamelCase(name, FULL_NAME), " ", FULL_NAME)
            && !input_concatStrings(name, stringCamelCase(lastName, FULL_NAME), FULL_NAME))
        {
            printf("Nombre y Apellido ingresado: %s\n", name);
        }
    }

    input_pauseScreen("Presione Enter para continuar...");

    return 0;
}

char* stringCamelCase(char string[], int maxLength)
{
    char* auxString = string;
    int position = 0;

    if(string != NULL && maxLength > 0 && maxLength < STRING_MAX)
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
