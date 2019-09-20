#include "input.h"

#define FILAS 5
#define COLUMNAS 20

void mostrarNombres( char mat[][COLUMNAS], int filas);
void ordenarNombres( char mat[][COLUMNAS], int filas);
void swapStrings(char string1[], char string2[], int length);

int main()
{
    input_clearScreen();
    
    char nombres[FILAS][COLUMNAS]= {"juan", "Lucia", "Pedro", "Ana", "Miguel"};

    mostrarNombres(nombres, FILAS);
    ordenarNombres(nombres, FILAS);
    mostrarNombres(nombres, FILAS);

    input_pauseScreen("Presione Enter para salir del programa...");

    return 0;
}

void mostrarNombres( char mat[][COLUMNAS], int filas)
{
    for(int i=0; i < filas; i++)
    {
         printf("%s\n", mat[i]);
    }
    printf("\n");
}

void ordenarNombres( char mat[][COLUMNAS], int filas)
{
    for(int i=0; i < filas -1; i++)
    {
        for(int j= i+1; j < filas; j++)
        {
            if( strcmp( mat[i], mat[j]) > 0  )
            {
                swapStrings(mat[i], mat[j], COLUMNAS);
            }
        }
    }
}

void swapStrings(char string1[], char string2[], int length)
{
    char aux1[STRING_MAX];

    if(string1 != NULL && string2 != NULL
        && length > 0 && length < STRING_MAX)
    {
        strncpy(aux1, string1, length);
        strncpy(string1, string2, length);
        strncpy(string2, aux1, length);
    }
}
