#include <stdio.h>
#include <stdlib.h>

int getMax(int, int, int);

int main()
{
    int a, b, c;
    int max;

    printf("Ingresar 3 enteros sepados por espacio: ");
    scanf("%d %d %d", &a, &b, &c);

    max = getMax(a, b, c);

    printf("El valor maximo entre %d, %d y %d es %d\n", a, b, c, max);

    return 0;
}

int getMax(int a, int b, int c)
{
    int max = a;

    if(b > a)
    {
        max = b;
    }

    if(c > a && c > b)
    {
        max = c;
    }

    return max;
}
