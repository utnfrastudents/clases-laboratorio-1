#include "input.h"

#define CANTIDAD_NOMBRES 5
#define NOMBRE_LONGITUD 20

typedef char mNombres[CANTIDAD_NOMBRES][NOMBRE_LONGITUD];

void cargarNombres(mNombres nombres, int cantidad, int longitud);
void imprimirNombres(mNombres nombres, int cantidad, int longitud);

int main()
{
    input_clearScreen();

    mNombres nombres;

    cargarNombres(nombres, CANTIDAD_NOMBRES, NOMBRE_LONGITUD);
    imprimirNombres(nombres, CANTIDAD_NOMBRES, NOMBRE_LONGITUD);

    input_pauseScreen("Presione Enter para salir...");

    return 0;
}

void cargarNombres(mNombres nombres, int cantidad, int longitud)
{
    char auxNombre[NOMBRE_LONGITUD];

    if(nombres != NULL && cantidad > 0 && cantidad <= CANTIDAD_NOMBRES
        && longitud > 0 && longitud <= NOMBRE_LONGITUD)
    {
        for(int i = 0; i < cantidad; i++)
        {
            if(!input_getString(auxNombre, "Ingrese un nombre: ", "Intente nuevamente: ", 1, longitud))
            {
                strncpy(nombres[i], auxNombre, longitud);
                printf("Nombre %d ingresado correctamente: %s\n", i+1, nombres[i]);
            }
        }
    }
}

void imprimirNombres(mNombres nombres, int cantidad, int longitud)
{
    if(nombres != NULL && cantidad > 0 && cantidad <= CANTIDAD_NOMBRES
        && longitud > 0 && longitud <= NOMBRE_LONGITUD)
    {
        printf("\n%s\n", "=======================");
        printf("%s\n", "        NOMBRES        ");
        printf("%s\n", "=======================");
        for(int i = 0; i < cantidad; i++)
        {
            printf("%s\n", nombres[i]);
        }
        printf("%s\n\n", "=======================");
    }
}
