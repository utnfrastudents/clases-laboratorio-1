#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "alumno.h"
#include "carrera.h"
#include "informes.h"
#include "comidas.h"

void mostrarComidas(eComida comidas[], int tam)
{
    printf(" Id   Descripcion      Precio\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarComida( comidas[i]);
    }
    printf("\n");
}

void mostrarComida(eComida comida)
{

    printf("  %d      %10s     %3.2f\n", comida.id, comida.descripcion, comida.precio);

}

int cargarDescComida(int id, eComida comidas[], int tam, char desc[])
{
    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {
        if( id == comidas[i].id)
        {
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}


void inicializarAlmuerzos(eAlmuerzo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad)
{
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20000, 5000, {1, 10, 2019}, 0},
        { 60001, 20001, 5002, {1, 10, 2019}, 0},
        { 60002, 20005, 5002, {1, 10, 2019}, 0},
        { 60003, 20003, 5004, {1, 10, 2019}, 0},
        { 60004, 20004, 5001, {2, 10, 2019}, 0},
        { 60005, 20001, 5000, {2, 10, 2019}, 0},
        { 60006, 20002, 5002, {2, 10, 2019}, 0},
        { 60007, 20004, 5004, {2, 10, 2019}, 0},
        { 60008, 20003, 5000, {3, 10, 2019}, 0},
        { 60009, 20001, 5001, {3, 10, 2019}, 0},

    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tamC)
{
    char descComida[20];

    cargarDescComida(x.idComida, comidas, tamC, descComida);
    printf("  %d    %10s   %d  %02d/%02d/%d\n",
           x.id,
           descComida,
           x.legajo,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio);
}

void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC)
{

    int flag = 0;
    system("cls");

    printf(" Id       Comida      Legajo    Fecha \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlmuerzo(vec[i], comidas, tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar\n");
    }

    printf("\n\n");
}
int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlmuerzo( eAlmuerzo almuerzos[], int tAlmuerzo,int idAlmuerzo, eComida comidas[],int tComida, eAlumno alumnos[],int tAlumno, eCarrera carreras[],int tCarrera)
{
    int todoOk = 0;
    int indice;
    int idComida;
    int legajo;
    eFecha fecha;

    system("cls");

    printf("*****Alta Almuerzo*****\n\n");

    indice = buscarAlmuerzoLibre(almuerzos, tAlmuerzo);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        mostrarAlumnos(alumnos, tAlumno, carreras, tCarrera);
        printf("Ingrese legajo alumno: ");
        scanf("%d", &legajo);

        mostrarComidas(comidas, tComida);
        printf("Ingrese id comida: ");
        scanf("%d", &idComida);

        printf("Ingrese fecha : ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);



        almuerzos[indice] = newAlmuerzo(idAlmuerzo, legajo, idComida, fecha);
        todoOk = 1;
        printf("Alta Almuerzo exitosa!!\n\n");
    }
    return todoOk;
}

eAlmuerzo newAlmuerzo(int id,int legajo,int idComida, eFecha fecha)
{
    eAlmuerzo al;
    al.id = id;
    al.legajo = legajo;
    al.idComida = idComida;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}

int compararFechas( eFecha f1, eFecha f2)
{
    int sonIguales = 0;

    if( f1.anio == f2.anio && f1.dia == f2.dia && f1.mes == f2.mes){
        sonIguales = 1;
    }

    return sonIguales;

}
