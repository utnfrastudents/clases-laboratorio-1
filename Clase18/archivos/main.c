#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* f1;
    FILE* f2;
    FILE* f3;
    FILE* f4;
    char nombre[] = "Juan";
    char apellido[] = "Perez";
    char nombre2[40];


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

    fclose(f1);

    f2 = fopen("archivo.txt", "a");

    if(f2 != NULL
       && fprintf(f2, " %s", apellido))
    {
        printf("Archivo editado con exito.\n");
    }

    fclose(f2);

    f3 = fopen("archivo2.txt", "w");

    fwrite(nombre, sizeof(char), strlen(nombre), f3);

    fclose(f3);

    f4 = fopen("archivo.txt", "r");

    while(!feof(f4))
    {
        fread(nombre2, sizeof(char), 1, f4);
        printf(nombre2);
    }

    fclose(f4);

    return 0;
}
