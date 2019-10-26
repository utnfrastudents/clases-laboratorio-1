#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;

    char nombre[] = "Juan Carlos";
    char x;
    char nombre2[20];

    f = fopen("archivo.txt", "r");

    if(f == NULL){
        printf("No se pudo abrir el archivo.");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fprintf(f, "%s", nombre);

    while( !feof(f)){
    //x = fgetc(f);
    fgets(nombre2, 19, f);
    printf("%s", nombre2);

    }

    fclose(f);




    return 0;
}
