#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 8;
    int numeros[5] = {5, 3, 4, 1, 9}; //Declaracion explicita
    int inicializacionEnCero[5] = {0}; //Inicializar todos sus elementos en cero

    printf("%d\n%d\n%d\n%d\n", x, numeros[1], inicializacionEnCero[1], *numeros);

    for(int j = 0; j < 5; j++)
    {
        printf("Ingrese un numero para la posicion %d: ", j);
        scanf("%d", &numeros[j]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("El valor del indice %d es %d\n", i, numeros[i]);
    }

    return 0;
}
