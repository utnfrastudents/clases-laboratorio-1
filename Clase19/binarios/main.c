#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[30];
    float salario;
} eEmpleado;

void escribirBinario(char* path);
void leerBinario(char* path);

int main()
{
    escribirBinario("midato.dat");
    leerBinario("midato.dat");

    return 0;
}

void escribirBinario(char* path)
{
    eEmpleado miEmpleado[2] = {{100, "Pepe", 1000}, {101, "Mony", 2000}};
    FILE* miArchivo;
    int i;
    int len = 2;

    miArchivo = fopen(path, "wb");

    if(miArchivo != NULL)
    {
        /**< Longitud de la estructura como cabeza del archivo. >*/
        fwrite((int*)&len, sizeof(miEmpleado), 2, miArchivo);

        for(i=0; i<2; i++)
        {
            if(fwrite((eEmpleado*)(&miEmpleado+i), sizeof(eEmpleado), 1, miArchivo) == 1)
            {
                printf("Se almacenaron los datos.\n");
            }
        }

        fclose(miArchivo);
    }
}

void leerBinario(char* path)
{
    eEmpleado miEmpleado[10];
    FILE* miArchivo;
    int i;
    int len;

    miArchivo = fopen(path, "rb");

    if(miArchivo != NULL)
    {
        if(fread((int*)&len, sizeof(int), 1, miArchivo) == 1)
        {
            if(fread((eEmpleado*)(&miEmpleado), sizeof(eEmpleado), len, miArchivo) == len)
            {
                for(i=0; i<len; i++)
                {
                    printf("%d-%s-%.2f.\n", miEmpleado[i].legajo, miEmpleado[i].nombre, miEmpleado[i].salario);
                }
            }
        }

        fclose(miArchivo);
    }
}
