#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char marca[30];
    int modelo;
    float precio;
}eAuto;

eAuto* newAuto();
eAuto* new_AutoParametros(int id, char marca[], int modelo, float precio);
int setIdAuto(eAuto* unAuto, int id);
int getIdAuto(eAuto* unAuto, int* id);
int setMarcaAuto(eAuto* unAuto, char marca[]);
int getMarcaAuto(eAuto* unAuto, char* marca);
int setModeloAuto(eAuto* unAuto, int modelo);
int getMarcaAuto(eAuto* unAuto, char* marca);
int setPrecioAuto(eAuto* unAuto, float precio);
int getModeloAuto(eAuto* unAuto, int* modelo);
int mostrarAuto(eAuto* unAuto);
int mostrarAutos(eAuto** autos, int tam);

int main()
{

    return 0;
}

eAuto* newAuto()
{
    eAuto* aux = (eAuto*)malloc(sizeof(eAuto));

    return aux;
}

eAuto* new_AutoParametros(int id, char marca[], int modelo, float precio)
{
    eAuto* aux = newAuto();

    if(aux != NULL &&
       (!setIdAuto(aux, id)
       || !setMarcaAuto(aux, marca)
       || !setModeloAuto(aux, modelo)
       || !setPrecioAuto(aux, precio)))
    {
        free(aux);
        aux = NULL;
    }

    return aux;
}

int setIdAuto(eAuto* unAuto, int id)
{
    int returnValue = 0;

    if(unAuto != NULL
       && id >= 1000 && id <= 2000)
    {
        unAuto->id = id;
        returnValue = 1;
    }

    return returnValue;
}

int getIdAuto(eAuto* unAuto, int* id)
{
    int returnValue = 0;

    if(unAuto != NULL && id != NULL)
    {
        *id = unAuto->id;
        returnValue = 1;
    }

    return returnValue;
}

int setMarcaAuto(eAuto* unAuto, char marca[])
{
    int returnValue = 0;

    if(unAuto != NULL && marca != NULL)
    {
        strcpy(unAuto->marca, marca);
        returnValue = 1;
    }

    return returnValue;
}

int getMarcaAuto(eAuto* unAuto, char* marca)
{
    int returnValue = 0;

    if(unAuto != NULL && marca != NULL)
    {
        strcpy(marca, unAuto->marca);
        returnValue = 1;
    }

    return returnValue;
}

int setModeloAuto(eAuto* unAuto, int modelo)
{
    int returnValue = 0;

    if(unAuto != NULL && modelo >= 1900 && modelo <= 2500)
    {
        unAuto->modelo = modelo;
        returnValue = 1;
    }

    return returnValue;
}

int getModeloAuto(eAuto* unAuto, int* modelo)
{
    int returnValue = 0;

    if(unAuto != NULL && modelo != NULL)
    {
        *modelo = unAuto->modelo;
        returnValue = 1;
    }

    return returnValue;
}

int setPrecioAuto(eAuto* unAuto, float precio)
{
    int returnValue = 0;

    if(unAuto != NULL && precio >= 0 && precio <= 10000000)
    {
        unAuto->precio = precio;
        returnValue = 1;
    }

    return returnValue;
}

int getPrecioAuto(eAuto* unAuto, float* precio)
{
    int returnValue = 0;

    if(unAuto != NULL && precio != NULL)
    {
        *precio = unAuto->precio;
        returnValue = 1;
    }

    return returnValue;
}

int mostrarAuto(eAuto* unAuto)
{
    int returnValue = 0;

    if(unAuto != NULL)
    {
        if(printf("| %4d | %20s | %6d | %12.2f |\n",
               unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio) == 4)
        {
            returnValue = 1;
        }
    }

    return returnValue;
}

int mostrarAutos(eAuto** autos, int tam)
{
    int counter = 0;
    int i;

    if(autos != NULL && tam > 0 && tam <= 1000)
    {
        for(i = 0; i < tam; i++)
        {
            if(counter == 0)
            {
                printf("+=======+======================+========+==============+\n");
                printf("|   ID  |        MARCA         | MODELO |    PRECIO    |\n");
                printf("+=======+======================+========+==============+\n");
            }

            /**< La direccion de memoria de la posicion del arreglo al que apunta esa direccion. >*/
            if(mostrarAuto(*(autos + i)))
            {
                counter++;
            }
        }

        if(counter == i)
        {
            printf("+-------+----------------------+--------+--------------+\n");
        }
    }

    return counter;
}
