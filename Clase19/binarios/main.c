#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[30];
    float salario;
}eEmpleado;

void escribirBinario(char* path);
void leerBinario(char* path);

int main()
{
    escribirBinario("D:\\Clase19\\binarios\\midato.dat");
    leerBinario("D:\\Clase19\\binarios\\midato.dat");

    return 0;
}

void escribirBinario(char* path)
{
    eEmpleado miEmpleado = {100, "Pepe", 1000};
    FILE* miArchivo;

    miArchivo = fopen(path, "wb");

    if(miArchivo != NULL)
    {
      if(fwrite((eEmpleado*)(&miEmpleado), sizeof(eEmpleado), 1, miArchivo) == 1)
      {
          printf("Se almaceno el Dato.\n");
      }

      fclose(miArchivo);
    }
}

void leerBinario(char* path)
{
    eEmpleado miEmpleado;
    FILE* miArchivo;

    miArchivo = fopen(path, "rb");

    if(miArchivo != NULL)
    {
      if(fread((eEmpleado*)(&miEmpleado), sizeof(eEmpleado), 1, miArchivo) == 1)
      {
          printf("%d-%s-%.2f.\n", miEmpleado.legajo, miEmpleado.nombre, miEmpleado.salario);
      }

      fclose(miArchivo);
    }
}
