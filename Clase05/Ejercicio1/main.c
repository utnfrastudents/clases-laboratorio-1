#include <stdio.h>
//#include <stdlib.h>

int main()
{
    int x = 8;
    int numeros[5] = {5, 3, 4, 1, 9}; //Declaracion explicita
    int inicializacionEnCero[5] = {0}; //Inicializar todos sus elementos en cero

    printf("%d\n%d\n%d\n%d\n", x, numeros[1], inicializacionEnCero[1], *numeros);

    //Acceso secuencial
    for(int i = 0; i < 5; i++)
    {
        printf("Ingrese un numero para la posicion %d: ", i);
        scanf("%d", &inicializacionEnCero[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("El valor del indice %d es %d\n", i, inicializacionEnCero[i]);
    }

    printf("Acceso aleatorio a un valor del vector: %d\n", inicializacionEnCero[4]);

    return 0;
}
