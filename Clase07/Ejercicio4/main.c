#include "input.h"

#define CANTIDAD_NOMBRES 5
#define NOMBRE_LONGITUD 20

typedef char mNombres[CANTIDAD_NOMBRES][NOMBRE_LONGITUD];

void cargarNombres(mNombres nombres, int cantidad, int longitud);

int main()
{
    input_clearScreen();

    mNombres nombres;

    cargarNombres(nombres, CANTIDAD_NOMBRES, NOMBRE_LONGITUD);

    input_pauseScreen("Presione Enter para salir...");

    return 0;
}

void cargarNombres(mNombres nombres, int cantidad, int longitud)
{
    if(nombres != NULL && cantidad > 0 && cantidad <= CANTIDAD_NOMBRES
        && longitud > 0 && longitud <= NOMBRE_LONGITUD)
    {
        for(int i = 0; i < cantidad; i++)
        {
            if(!input_getString(&nombres[i][i], "Ingrese un nombre: ", "Intente nuevamente: ", 1, longitud))
            {
                printf("%d nombre ingresado correctamente.\n", i+1);
            }
        }
    }
}
