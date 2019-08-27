/* Programa
 * Se pide nombre, sexo y nota y se informa
 * Promedio de notas totales
 * Promedio de nota de las mujeres
 * El nombre y sexo de la nota maxima
 * El nombre y sexo de la nota minima
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char pregunta;
    char nombre[20];
    char nombreMax[20];
    char nombreMin[20];
    char sexo;
    char sexoMaximo;
    char sexoMinimo;

    int contador = 0;
    int contadorMujeres = 0;

    float acumuladorTotal = 0;
    float acumuladorMujeres = 0;
    float nota = 0;
    float notaMaximo;
    float notaMinimo;
    float promedioTotales = 0;
    float promedioMujeres = 0;

    do
    {
        contador++;

        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s", nombre);

        printf("Ingrese el sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese la nota: ");
        scanf("%f", &nota);

        printf("Contador: %d Nombre: %s Sexo: %c Nota: %.2f\n", contador, nombre, sexo, nota);

        if(contador == 1)
        {
            notaMaximo = nota;
            notaMinimo = nota;
            strcpy(nombreMax, nombre);
            strcpy(nombreMin, nombre);
            sexoMaximo = sexo;
            sexoMinimo = sexo;
        }

        if(nota > notaMaximo)
        {
            notaMaximo = nota;
            strcpy(nombreMax, nombre);
            sexoMaximo = sexo;
            printf("Nota maxima: Nombre: %s Sexo: %c Nota %.2f\n", nombreMax, sexoMaximo, notaMaximo);
        }

        if(nota < notaMinimo)
        {
            notaMinimo = nota;
            strcpy(nombreMin, nombre);
            sexoMinimo = sexo;
            printf("Nota minima: Nombre: %s Sexo: %c Nota %.2f\n", nombreMin, sexoMinimo, notaMinimo);
        }

        acumuladorTotal+=nota;

        if(sexo == 'f')
        {
            contadorMujeres++;
            acumuladorMujeres+=nota;
        }

        printf("Desea continuar? (s/n): ");
        fflush(stdin);
        scanf("%c", &pregunta);
    }while(pregunta == 's');

    if(contador > 0)
    {
        promedioTotales = acumuladorTotal / contador;
    }

    if(contadorMujeres > 0)
    {
        promedioMujeres = acumuladorMujeres / contadorMujeres;
    }

    printf("Promedio de notas totales: %.2f\n", promedioTotales);
    printf("Promedio de notas de mujeres: %.2f\n", promedioMujeres);
    printf("Nota maxima: Nombre: %s Sexo: %c Nota %.2f\n", nombreMax, sexoMaximo, notaMaximo);
    printf("Nota minima: Nombre: %s Sexo: %c Nota %.2f\n", nombreMin, sexoMinimo, notaMinimo);

    return 0;
}
