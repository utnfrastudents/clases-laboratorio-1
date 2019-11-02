#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char marca[32];
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
int guardarAutosBinario(eAuto** autos, int tam, char path[]);

int main()
{
    int tam = 0;
    int cant = 0;
    char buffer[4][30];
    FILE* file = NULL;
    eAuto* aux = NULL;
    eAuto** listaux = NULL;
    eAuto** lista = (eAuto**)malloc(sizeof(eAuto*));

    if(lista == NULL)
    {
        printf("Sin memoria.\n");
        //TODO: Pausar programa.
        exit(EXIT_FAILURE);
    }

    file = fopen("autos.csv", "r");

    if(file == NULL)
    {
        printf("Error de archivo.\n");
        //TODO: Pausar programa.
        exit(EXIT_FAILURE);
    }

    /**< Lectura fantasma de encabezado, >*/
    fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(file))
    {
        cant = fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        if(cant < 4)
        {
            break;
        }
        else
        {
            aux = new_AutoParametros(atoi(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]));

            if(aux != NULL)
            {
                *(lista + tam) = aux;
                tam++;
                listaux = (eAuto**)realloc(lista, sizeof(eAuto*) * (tam +1));

                if(listaux != NULL)
                {
                    lista = listaux;
                }
            }
        }
    }

    fclose(file);

    mostrarAutos(lista, tam);

    if(guardarAutosBinario(lista, tam, "autosBinario.bin"))
    {
        printf("Autos guardados a binario.\n");
    }

    /**< Lectura de binario. >*/
    int tam2 = 0;
    eAuto** lista2 = (eAuto**)malloc(sizeof(eAuto*));

    if(lista2 == NULL)
    {
        printf("Sin memoria.\n");
        //TODO: Pausar programa.
        exit(EXIT_FAILURE);
    }

    file = fopen("autosBinario.bin", "rb");

    if(file == NULL)
    {
        printf("Error de archivo.\n");
        //TODO: Pausar programa.
        exit(EXIT_FAILURE);
    }

    while(!feof(file))
    {
        aux = newAuto();
        if(aux == NULL)
        {
            break;
        }

        cant = fread(aux, sizeof(eAuto), 1, file);

        if(cant < 1)
        {
            break;
        }
        else
        {
            *(lista2 + tam2) = aux;
            tam2++;
            listaux = (eAuto**)realloc(lista2, sizeof(eAuto*) * (tam +1));

            if(listaux != NULL)
            {
                lista2 = listaux;
            }
        }
    }

    fclose(file);

    printf("Lectura desde binario en pantalla.\n");
    mostrarAutos(lista2, tam);

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
        printf("| %4d | %20s | %6d | %12.2f |\n",
               unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio);
        returnValue = 1;
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
                printf("+======+======================+========+==============+\n");
                printf("|  ID  |        MARCA         | MODELO |    PRECIO    |\n");
                printf("+======+======================+========+==============+\n");
            }

            /**< La direccion de memoria de la posicion del arreglo al que apunta esa direccion. >*/
            if(mostrarAuto(*(autos + i)))
            {
                counter++;
            }
        }

        if(counter == i)
        {
            printf("+------+----------------------+--------+--------------+\n");
        }
    }

    return counter;
}

int guardarAutosBinario(eAuto** autos, int tam, char path[])
{
    int returnValue = 0;
    FILE* file = NULL;
    int i;

    if(autos != NULL && tam > 0 && path != NULL)
    {
        file = fopen("autosBinario.bin", "wb");

        if(file == NULL)
        {
            printf("Error de archivo.\n");
        }
        else
        {
            for(i = 0; i < tam; i++)
            {
                fwrite((eAuto*)*(autos + i), sizeof(eAuto), 1, file);
            }

            fclose(file);

            if(i == tam)
            {
                returnValue = 1;
            }
        }
    }

    return returnValue;
}
