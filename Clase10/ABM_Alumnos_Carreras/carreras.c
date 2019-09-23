#include "carreras.h"

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
