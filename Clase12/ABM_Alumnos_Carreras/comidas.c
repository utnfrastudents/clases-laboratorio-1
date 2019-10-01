#include "comidas.h"

void inicializarAlmuerzos(sAlmuerzo almuerzos[], int len)
{
    if(almuerzos != NULL && len > 0 && len <= TAMAL)
    {
        for(int i=0; i < len; i++)
        {
            almuerzos[i].isEmpty = 0;
        }
    }
}

int hardcodearAlmuerzos(sAlmuerzo almuerzos[], int len, int cantidad)
{
    int contador = 0;

    sAlmuerzo aux[] = {
        {6000, 1990, 5002, {12, 5, 2019}, 0},
        {6001, 1994, 5001, {22, 6, 2019}, 0},
        {6002, 1998, 5004, {14, 1, 2019}, 0},
        {6003, 1990, 5000, {2, 2, 2019}, 0},
        {6004, 1995, 5001, {15, 10, 2019}, 0},
        {6005, 1991, 5000, {1, 6, 2019}, 0},
        {6006, 1999, 5003, {27, 12, 2019}, 0},
        {6007, 1997, 5002, {19, 8, 2019}, 0},
        {6008, 1991, 5001, {5, 6, 2019}, 0},
        {6009, 1992, 5000, {10, 4, 2019}, 0}
    };

    if(almuerzos != NULL && cantidad <= TAMAL && len >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            almuerzos[i] = aux[i];
            contador++;
        }
    }

    return contador;
}

int buscarAlmuerzoLibre(sAlmuerzo almuerzos[], int len)
{
    int returnValue = -1;

    if(almuerzos != NULL && len > 0 && len <= TAMAL)
    {
        for(int i=0; i < len; i++)
        {
            if(almuerzos[i].isEmpty)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int buscarAlmuerzoPorId(sAlmuerzo almuerzos[], int len, int id)
{
    int indice = -1;

    if(almuerzos != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            if(almuerzos[i].id == id
                && almuerzos[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int buscarComidaPorId(sComida vec[], int len, int id)
{
    int indice = -1;

    if(vec != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            if(vec[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int altaAlmuerzo(sAlmuerzo almuerzos[], int lenAlmuerzos,
    int id, sAlumno alumnos[], int lenAlumnos, sComida comidas[],
    int lenComidas, sCarrera carreras[], int lenCarreras)
{
    int returnValue = 0;
    sAlmuerzo almuerzoAux;
    int indiceAlmuerzo;
    int almuerzoExistente;

    if(almuerzos != NULL && lenAlmuerzos > 0)
    {
        indiceAlmuerzo = buscarAlmuerzoLibre(almuerzos, lenAlmuerzos);

        if(indiceAlmuerzo == -1)
        {
            printf("Sistema de almuerzos completo.\n");
        }
        else
        {
            almuerzoExistente = buscarAlmuerzoPorId(almuerzos, lenAlmuerzos, id);

            if(almuerzoExistente != -1)
            {
                printf("El almuerzo ya se encuentra registrado.\n");
            }
            else
            {
                almuerzos[almuerzoExistente].id = id;
                
                inputs_clearScreen();
                mostrarAlumnos(alumnos, lenAlumnos, carreras, lenCarreras);
                if(!inputs_getInt(&almuerzos[almuerzoExistente].idAlumno,
                        "Elija el legajo del alumno: ", "Intente nuevamente", 1900, 2100)
                    && buscarAlumnoPorLegajo(alumnos, lenAlumnos, almuerzos[almuerzoExistente].idAlumno) != -1)
                {
                    inputs_clearScreen();
                    mostrarComidas(comidas, lenComidas);
                    if(!inputs_getInt(&almuerzos[almuerzoExistente].idComida,
                            "Elija el ID de la comida: ", "Intente nuevamente: ", 5000, 5004)
                        && !inputs_getDate(&almuerzos[almuerzoExistente].fecha,
                            "Ingrese la fecha en DD/MM/AAAA: ", "Intente nuevamente: "))
                    {
                        returnValue = 1;
                    }
                }
            }
        }
    }

    return returnValue;
}

void mostrarComida(sComida comida)
{
    printf("| %5d | %20s | %5.2f |\n", comida.id, comida.descripcion, comida.precio);
}

void mostrarComidas(sComida comidas[], int len)
{
    if(comidas != NULL && len > 0 && len <= TAMCOM)
    {
        printf("+=======+======================+========+\n");
        printf("|   ID  | Descripcion          | Precio |\n");
        printf("+=======+======================+========+\n");
        for(int i=0; i < len; i++)
        {
            mostrarComida(comidas[i]);
        }
        printf("+-------+----------------------+--------+\n");
    }
}

void mostrarAlmuerzo(sAlmuerzo almuerzo, sAlumno alumno, sComida comida)
{
    printf("| %5d | %5d | %20s | %20s | %5.2f | %02d/%02d/%4d |\n",
        almuerzo.id, alumno.legajo, alumno.nombre, comida.descripcion, 
        comida.precio, almuerzo.fecha.day, almuerzo.fecha.month, almuerzo.fecha.year);
}

void mostrarAlmuerzos(sAlmuerzo almuerzos[], int lenAlmuerzos,
    sAlumno alumnos[], int lenAlumnos, sComida comidas[], int lenComidas)
{
    int indiceAlumno;
    int indiceComida;

    if(almuerzos!=NULL)
    {
        for(int i = 0; i < lenAlmuerzos; i++)
        {
            indiceAlumno = buscarAlumnoPorLegajo(alumnos, lenAlumnos, almuerzos[i].idAlumno);

            if(indiceAlumno != -1)
            {
                indiceComida = buscarComidaPorId(comidas, lenComidas, almuerzos[i].idComida);

                if (indiceComida != -1) {
                    mostrarAlmuerzo(almuerzos[i], alumnos[indiceAlumno], comidas[indiceComida]);
                }
            }
        }
    }
}