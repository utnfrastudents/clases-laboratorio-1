#include <stdio.h>
#include <stdlib.h>

int calcular(int a, int b , int (*pFunc)(int x, int y));

int sumar( int r, int s);
int restar( int r, int s);
int multiplicar( int r, int s);

int main()
{
    int resultado;

    resultado = calcular( 5, 7,  multiplicar);

    printf("El resultado es %d\n", resultado);

    return 0;
}

int sumar( int r, int s){

    return r + s;

}

int restar( int r, int s){

    return r - s;

}

int multiplicar( int r, int s){

    return r * s;

}

int calcular(int a, int b , int (*pFunc)(int x, int y)){

    int rta;

    rta = pFunc(a, b);

    return rta;
}

