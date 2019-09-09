#include <stdio.h>
//#include <stdlib.h>

int main()
{
    int number1;
    int number2;
    float average;

    printf("Ingrese el primer numero: ");
    scanf("%d", &number1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &number2);

    average = (float)(number1 + number2) / 2;

    printf("El promedio es %.2f\n", average);
    return 0;
}
