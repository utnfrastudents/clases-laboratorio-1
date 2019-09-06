#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 8;
    int numeros[5] = {5, 3, 4, 1, 9}; //Declaracion explicita
    int inicializacionEnCero[5] = {0}; //Inicializar todos sus elementos en cero

    printf("%d\n%d\n%d\n", x, numeros[1], inicializacionEnCero[1]);

    return 0;
}
