#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 30;
    int numero2 = 12;
    int numero3;
    float pi = 3.14;
    float decimal;
    char sexo = 'A';
    char caracter;
    char nombre[20] = "Jose";
    char nombre2[20];

    printf("La variable numero vale %d y numero 2 vale %d\n", numero, numero2);
    printf("La letra es %c y su codigo ASCII es %d\n", sexo, sexo);
    printf("Pi vale %.2f\n", pi);
    printf("Usted se llama %s\n", nombre);

    printf("Ingrese un numero: ");
    scanf("%d", &numero3);
    printf("El numero ingresado es %d\n", numero3);

    printf("Ingrese un numero con decimales: ");
    scanf("%f", &decimal);
    printf("El decimal ingresado es %.2f\n", decimal);

    fflush(stdin); // Limpiar el buffer del teclado

    printf("Ingrese el sexo en un caracter: ");
    scanf("%c", &caracter);
    printf("El caracter ingresado es %c\n", caracter);

    fflush(stdin);

    printf("Ingrese su nombre: ");
    gets(nombre2);
    printf("El nombre ingresado es %s\n", nombre2);

    return 0;
}
