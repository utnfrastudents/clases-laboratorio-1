#include "carreras.h"

int buscarCarreraPorId(int id, sCarrera vec[], int tam, char descrip[])
{
    int aux = 0;

    if(descrip != NULL && vec != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].idCarrera == id)
            {
                strcpy(descrip, vec[i].descripcion);
                aux = 1;
                break;
            }
        }
    }

    return aux;
}

void mostrarCarrera(sCarrera carrera)
{
    printf("+======+=========+\n");
    printf("|  ID  | Descrip |\n");
    printf("+======+=========+\n");
    printf("| %4d |  %5s  |\n", carrera.idCarrera, carrera.descripcion);
    printf("+------+---------+\n");
}

void mostrarCarreras(sCarrera vec[], int tam)
{
    int flag = 0;

    if(vec != NULL && tam > 0)
    {
        printf("+======+=========+\n");
        printf("|  ID  | Descrip |\n");
        printf("+======+=========+\n");

        for(int i=0; i < tam; i++)
        {
            printf("| %4d |  %5s  |\n", vec[i].idCarrera, vec[i].descripcion);
            flag = 1;
        }

        printf("+------+---------+\n");
    }

    if(flag == 0)
    {
        printf("No hay carreras que mostrar.\n");
    }
}
