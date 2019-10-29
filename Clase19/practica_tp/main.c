#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
}eEmpleado;

int main()
{
    FILE* miArchivo;
    eEmpleado miEmpleado;
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[15];
    int id;
    float salary;

    miArchivo = fopen("ramdom_data.csv", "r");

    if(miArchivo != NULL)
    {
        while(!feof(miArchivo))
        {
            if(fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", legajo, nombre, apellido, sueldo) == 4)
            {
                id = atoi(legajo);
                salary = atof(sueldo);

                if(id != 0 && salary != 0 && nombre != NULL && apellido != NULL)
                {
                    miEmpleado.legajo = id;
                    strcpy(miEmpleado.nombre, nombre);
                    strcpy(miEmpleado.apellido, apellido);
                    miEmpleado.sueldo = salary;

                    printf("%d-%s-%s-%.2f\n", miEmpleado.legajo, miEmpleado.nombre, miEmpleado.apellido, miEmpleado.sueldo);
                }
            }
        }

        fclose(miArchivo);
    }

    return 0;
}
