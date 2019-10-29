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

eEmpleado* new_empleado();

int main()
{
    FILE* miArchivo;
    eEmpleado* miEmpleado;
    eEmpleado* lista[50];
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[15];
    int id;
    float salary;
    int i = 0;

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
                    miEmpleado = new_empleado();

                    if(miEmpleado != NULL)
                    {
                        miEmpleado->legajo = id;
                        strcpy(miEmpleado->nombre, nombre);
                        strcpy(miEmpleado->apellido, apellido);
                        miEmpleado->sueldo = salary;

                        *(lista+i) = miEmpleado;
                    }

                    printf("%d-%s-%s-%.2f\n", lista[i]->legajo, lista[i]->nombre, lista[i]->apellido, lista[i]->sueldo);

                    i++;
                }
            }
        }

        fclose(miArchivo);
    }

    return 0;
}

eEmpleado* new_empleado()
{
    eEmpleado* aux;

    aux = (eEmpleado*)malloc(sizeof(eEmpleado));

    return aux;
}
