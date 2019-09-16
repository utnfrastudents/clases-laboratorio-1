#include "input.h"

#define CANTIDAD_NOMBRES 5
#define NOMBRE_LONGITUD 20
#define UNA_LINEA 1

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
    int longitudAux;

    if(nombres != NULL && cantidad > 0 && cantidad <= CANTIDAD_NOMBRES
        && longitud > 0 && longitud <= NOMBRE_LONGITUD)
    {
        if(UNA_LINEA)
        {
            longitudAux = 1;
        }
        else
        {
            longitudAux = longitud;
        }
        
        
        for(int i = 0; i < cantidad; i++)
        {
            for(int j = 0; j < longitudAux; j++)
            {
                if(!input_getString(&nombres[i][j], "Ingrese un nombre: ", "Intente nuevamente: ", 1, longitud))
                {
                    printf("Nombre %d ingresado correctamente: %s\n", i+1, &nombres[i][j]);
                }
            }
        }
    }
}
