#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x;
    char y;
    float z;

    int* a = (int*) malloc(sizeof(int));

   if( a == NULL){
    exit(1);
   }

   *a = 5;



    char* b = (char*) malloc(sizeof(char));
    float* c = (float*) malloc(sizeof(float));





    return 0;
}

