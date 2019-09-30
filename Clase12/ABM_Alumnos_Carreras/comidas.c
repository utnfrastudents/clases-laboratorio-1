#include "comidas.h"

void inicializarAlmuerzos(sAlmuerzo almuerzos[], int len)
{
    if(almuerzos != NULL && len > 0 && len <= TAMAL)
    {
        for(int i=0; i < len; i++)
        {
            almuerzos[i].isEmpty = 0;
        }
    }
}

int hardcodearAlmuerzos(sAlmuerzo almuerzos[], int len, int cantidad)
{
    int contador = 0;

    sAlmuerzo aux[] = {
        {6000, 1990, 5002, {12, 5, 2019}, 0},
        {6001, 1994, 5001, {22, 6, 2019}, 0},
        {6002, 1998, 5004, {14, 1, 2019}, 0},
        {6003, 1990, 5000, {2, 2, 2019}, 0},
        {6004, 1995, 5001, {15, 10, 2019}, 0},
        {6005, 1991, 5000, {1, 6, 2019}, 0},
        {6006, 1999, 5003, {27, 12, 2019}, 0},
        {6007, 1997, 5002, {19, 8, 2019}, 0},
        {6008, 1991, 5001, {5, 6, 2019}, 0},
        {6009, 1992, 5000, {10, 4, 2019}, 0}
    };

    if(almuerzos != NULL && cantidad <= TAMAL && len >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            almuerzos[i] = aux[i];
            contador++;
        }
    }

    return contador;
}

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

int buscarAlmuerzoLibre(sAlmuerzo almuerzos[], int len)
{
    int returnValue = -1;

    if(almuerzos != NULL && len > 0 && len <= TAMAL)
    {
        for(int i=0; i < len; i++)
        {
            if(almuerzos[i].isEmpty)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int buscarAlmuerzoPorId(sAlmuerzo almuerzos[], int len, int id)
{
    int indice = -1;

    if(almuerzos != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            if(almuerzos[i].id == id
                && almuerzos[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int altaAlmuerzo(sAlmuerzo almuerzos[], int lenAlmuerzos,
    int id, sAlumno alumnos[], int lenAlumnos, sComida comidas[],
    int lenComidas, sDate fecha)
{
    int returnValue = 0;
    sAlmuerzo almuerzoAux;
    int indiceAlmuerzo;
    int almuerzoExistente;

    if(almuerzos != NULL && lenAlmuerzos > 0)
    {
        indiceAlmuerzo = buscarAlmuerzoLibre(almuerzos, lenAlmuerzos);

        if(indiceAlmuerzo == -1)
        {
            printf("Sistema de alumnos completo.\n");
        }
        else
        {
            almuerzoExistente = buscarAlmuerzoPorId(almuerzos, lenAlmuerzos, id);

            if(almuerzoExistente != -1)
            {
                //TODO: Implementar Mostar Almuerzo
                //mostrarAlmuerzo(almuerzos[almuerzoExistente]);
            }
            else
            {
                if(1) //TODO: Implementar la carga del Almuerzo
                {
                    returnValue = 1;
                }
            }
        }
    }

    return returnValue;
}
