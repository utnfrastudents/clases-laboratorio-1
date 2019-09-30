#include "comidas.h"

void mostrarComida(sComida comida)
{
    printf("| %5d | %20s | %5.2f |\n", comida.id, comida.descripcion, comida.precio);
}

void mostrarComidas(sComida comidas[], int len)
{
    if(comidas != NULL && len > 0 && len <= TAMCOM)
    {
        printf("+=======+======================+========+\n");
        printf("|   ID  | Descripcion          | Precio |\n");
        printf("+=======+======================+========+\n");
        for(int i=0; i < len; i++)
        {
            mostrarComida(comidas[i]);
        }
        printf("+-------+----------------------+--------+\n");
    }
}
