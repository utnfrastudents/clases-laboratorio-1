#include <stdio.h>
#include <stdlib.h>

void mostrarEnteros(int* x, int tam);

int main()
{

    int vec[]= {3,2,1,4,7};

    mostrarEnteros(vec, 5);

    return 0;
}

void mostrarEnteros(int* x, int tam){

    for(int i=0; i < tam; i++){
        printf("%d ", *(x+i));
    }

}
