#include <stdio.h>
#include <stdlib.h>


int getIntRange(int* numero,
                char* mensaje,
                char* mensajeError,
                int min,
                int max,
                int intentos,
                int retornoError);

int main()
{
    int numero;
    int todoOk;

    todoOk=getIntRange(&numero,"Ingrese un numero entre 1 y 10", "El numero no se encuentra entre el rango solicitado",1,10,3,-1);

    if (todoOk == 1){
            printf("No se pudo conseguir el numero despues de 3 reintentos\n");

    }else{
        printf("El numero es: %d\n", numero);
    }

    return 0;
}
int getIntRange(int* numero, char* mensaje, char* mensajeError, int min, int max, int intentos, int retornoError)
{
    int auxiliar;
    int todoOk=1;

    printf("%s \n", mensaje);
    scanf("%d", &auxiliar);

    while(auxiliar < min || auxiliar > max)
    {
        intentos--;
        if(intentos == 0){
            break;
        }
        printf("%s\n", mensajeError);
        scanf("%d", &auxiliar);
    }

    if (intentos !=0){
        todoOk=0;
        *numero = auxiliar;

    }

    return todoOk;
}
