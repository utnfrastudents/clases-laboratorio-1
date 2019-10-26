#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int id;
    char nombre[20];
    float sueldo;
    int estado;
} eEmpleado;

int mostrarEmpleado( eEmpleado* unEmpleado);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo);

int main()
{
    //eEmpleado emp1;
    int tam = 0;
    eEmpleado* aux;
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado)* (tam +1));

  /* if( inicializarEmpleados(lista, tam) ){
    printf("Empleados inicializados\n");
   }
   else{
    printf("Problemas para inicializar empleados");
   }
*/

   // eEmpleado* emp2 = newEmpleado();
    // 2 maneras de cargar el id
    // emp2->id = 1234;

    // printf("Ingrese id: ");
    //  scanf("%d", &emp2->id);

    //  mostrarEmpleado(emp2);
    eEmpleado* emp3 = newEmpleadoParam(3322, "Jose", 34000);

    *(lista + tam) = *emp3;

    mostrarEmpleado( lista + tam);
    tam++;


    aux = (eEmpleado*) realloc( lista, sizeof(eEmpleado) *())








    return 0;
}

eEmpleado* newEmpleado()
{
    eEmpleado* e;

    e = (eEmpleado*) malloc( sizeof(eEmpleado));

    if( e != NULL)
    {
        e->id = 0;
        strcpy(e->nombre, "Sin asignar");
        e->sueldo = 0;
        e->estado = 0;
    }
    return e;
}

eEmpleado* newEmpleadoParam(int id, char* nombre, float sueldo)
{

    eEmpleado* e = newEmpleado();
    if( e != NULL)
    {
        e->id = id;
        strcpy(e->nombre, nombre);
        e->sueldo = sueldo;
        e->estado = 0;
    }
    return e;
}





int mostrarEmpleado( eEmpleado* unEmpleado)
{
    int todoOk = 0;
    if( unEmpleado != NULL)
    {
        printf(" %d  %s  %.2f\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->sueldo);

        todoOk = 1;
    }
    return todoOk;
}

int inicializarEmpleados(eEmpleado* vec, int tam)
{
    int todoOk = 0;

    if( vec != NULL && tam >=0)
    {

        for(int i=0; i < tam; i++)
        {

            (vec + i)->estado = 0;
        }
        todoOk = 1;
    }

    return todoOk;

}

