#include <stdio.h>
//#include <stdlib.h>

int main()
{
    char name[50];
    int age;

    printf("Ingrese su nombre: ");
    gets(name);
    printf("Ingrese su edad: ");
    scanf("%d", &age);

    printf("Usted se llama %s y tiene %d anios\n", name, age);

    return 0;
}
