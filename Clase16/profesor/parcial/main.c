#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

float aplicarDescuento(float precio);
int contarCaracteres( char cadena[], char c);
void ordenarNotebooks(eNotebook lista[], int tam);

int main()
{
 /*   float precio = 100;
    float precioFinal = aplicarDescuento(precio);

    printf("%d\n", contarCaracteres("obelisco", 'b'));


    eNotebook lista[]=
    {
        { 1000, "i7", "Hp", 50000 },
        { 1005, "i5", "Asus", 23000 },
        { 1003, "i3", "Lenovo", 60000 },
        { 1012, "R7", "Asus", 15000 },
        { 1009, "Pentium", "Asus", 63000 },
        { 1001, "i7", "Hp", 10000 }
    };

    ordenarNotebooks(lista, 6);

    mostrarNotebooks(lista, 6);*/


    for(int i=0; i < 20; i++){

         if( i % 2 == 1){
            continue;
            printf("Hola");
         }

        printf("%d ", i);

    }












}


float aplicarDescuento(float precio)
{

    return precio * .95;
}

int contarCaracteres( char cadena[], char c)
{
    int contador = 0;
//int i=0;
    int largo = strlen(cadena);
    /*
    while( cadena[i] != '\0'){

        if( cadena[i] == c){
            contador++;
        }
        i++;
    }*/
    for(int i = 0; i < largo; i++ )
    {
        if( cadena[i] == c)
        {
            contador++;
        }
    }

    return contador;

}


void ordenarNotebooks(eNotebook lista[], int tam)
{
    eNotebook aux;

    for(int i=0; i < tam-1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {
            if( strcmp(lista[i].marca, lista[j].marca) > 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
            else if( strcmp(lista[i].marca, lista[j].marca) == 0 && lista[i].precio > lista[j].precio)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }



}

void mostrarNotebooks( eNotebook lista[], int tam){

for(int i=0; i < tam; i++){
    printf("%d  %s  %s  %.2f\n", lista[i].id, lista[i].marca, lista[i].procesador, lista[i].precio);
}


}
