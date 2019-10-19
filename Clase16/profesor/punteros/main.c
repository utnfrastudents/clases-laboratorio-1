#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5;
    int y = 10;


    printf("x= %d  y= %d\n", x, y);

    swap( &x, &y);

    printf("x= %d  y= %d\n", x, y);

    return 0;
}

void swap( int* p, int* q){
int aux;

    aux = *p;
    *p = *q;
    *q = aux;
    printf("x= %d  y= %d\n", *p, *q);
}

