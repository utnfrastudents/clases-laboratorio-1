#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* f1;
    FILE* f2;
    FILE* f3;
    char nombre[] = "Juan";
    char apellido[] = "Perez";
    char nombre2[20];

    f1 = fopen("archivo.txt", "w");

    if(f1 == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    if(fprintf(f1, "Hola %s", nombre))
    {
        printf("Archivo creado y guardado con exito.\n");
    }

    f2 = fopen("archivo.txt", "a");

    if(f2 != NULL
       && fprintf(f2, " %s", apellido))
    {
        printf("Archivo editado con exito.\n");
    }

    f3 = fopen("archivo2.txt", "w");

    fwrite(nombre, sizeof(char), strlen(nombre), f3);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}
