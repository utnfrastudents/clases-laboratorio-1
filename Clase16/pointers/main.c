#include <stdio.h>
#include <stdlib.h>

void swap(int* p, int* q);

int main()
{
    /**
    * ======================================================
    * Division logica de la memoria del tipo de arquitectura
    * ======================================================
    * Segmento de codigo
    * Memoria estatica
    *   ----------------
    *   Memoria Dinamica
    *   ----------------
    * Heap (Se van cargando todas las variables dinamicas)
    * Memoria libre.
    *
    *       (Se apilan las funciones y las bibliotecas de dependencias
    *       por encima del stack luego del heap)
    * Stack
    *
    *   Otros significados
    * [&] Operador de direccion.
    * [*] Operador de indireccion.
    */

    int j = 7;
    int* p = &j;
    int** q = &p;
    int*** r = &q;
    int* s = p;

    printf("p: %d\n", *p);
    printf("q: %d\n", **q);
    printf("r: %d\n", ***r);
    printf("s: %d\n", *s);

    *p = 15;

    printf("s: %d\n", *s);

    int x = 5;
    int y = 10;

    printf("x:%d-y:%d\n", x, y);
    swap(&x, &y);
    printf("x:%d-y:%d\n", x, y);

    return 0;
}

void swap(int* p, int* q)
{
    int aux;

    aux = *p;
    *p = *q;
    *q = aux;

    printf("p:%d-q:%d\n", *p, *q);
}
