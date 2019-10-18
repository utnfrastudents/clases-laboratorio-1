#include <stdio.h>
#include <stdlib.h>

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

    printf("%d", *p);

    return 0;
}
