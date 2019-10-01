#include "comidas.h"

static void mostrarComidaSinEncabezado(sComida comida);
static void mostrarAlmuerzoSinEncabezado(sAlmuerzo almuerzo, sAlumno alumno, sComida comida);

void inicializarAlmuerzos(sAlmuerzo almuerzos[], int len)
{
    if(almuerzos != NULL && len > 0 && len <= TAMAL)
    {
        for(int i=0; i < len; i++)
        {
            almuerzos[i].isEmpty = 1;
        }
    }
}

int hardcodearAlmuerzos(sAlmuerzo almuerzos[], int len, int cantidad)
{
    int contador = 0;

    sAlmuerzo aux[] = {
        {60000, 1990, 5002, {12, 5, 2019}, 0},
        {60001, 1994, 5001, {22, 6, 2019}, 0},
        {60002, 1998, 5004, {14, 1, 2019}, 0},
        {60003, 1990, 5000, {2, 2, 2019}, 0},
        {60004, 1995, 5001, {15, 10, 2019}, 0},
        {60005, 1991, 5000, {1, 6, 2019}, 0},
        {60006, 1999, 5003, {27, 12, 2019}, 0},
        {60007, 1997, 5002, {19, 8, 2019}, 0},
        {60008, 1991, 5001, {5, 6, 2019}, 0},
        {60009, 1992, 5000, {10, 4, 2019}, 0}
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

int altaAlmuerzo(sAlmuerzo almuerzos[], int lenAlmuerzos,
    int id, sAlumno alumnos[], int lenAlumnos, sComida comidas[],
    int lenComidas, sCarrera carreras[], int lenCarreras)
{
    int returnValue = 0;
    int indiceAlmuerzo;
    int almuerzoExistente;

    if(almuerzos != NULL && lenAlmuerzos > 0 && lenAlmuerzos <= TAMAL
        && alumnos != NULL && lenAlumnos > 0 && lenAlumnos <= TAM
        && comidas != NULL && lenComidas > 0 && lenComidas <= TAMCOM
        && carreras != NULL && lenCarreras > 0 && lenCarreras <= TAMC)
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
                almuerzos[indiceAlmuerzo].id = id;
                
                mostrarAlumnos(alumnos, lenAlumnos, carreras, lenCarreras);
                if(!inputs_getInt(&almuerzos[indiceAlmuerzo].idAlumno,
                        "Elija el legajo del alumno: ", "Intente nuevamente: ", 1900, 2100)
                    && buscarAlumnoPorLegajo(alumnos, lenAlumnos, almuerzos[indiceAlmuerzo].idAlumno) != -1)
                {
                    inputs_clearScreen();
                    mostrarComidas(comidas, lenComidas);
                    if(!inputs_getInt(&almuerzos[indiceAlmuerzo].idComida,
                            "Elija el ID de la comida: ", "Intente nuevamente: ", 5000, 5004)
                        && !inputs_getDate(&almuerzos[indiceAlmuerzo].fecha,
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
    printf("+=======+======================+========+\n");
    printf("|   ID  | Descripcion          | Precio |\n");
    printf("+=======+======================+========+\n");
    mostrarComidaSinEncabezado(comida);
    printf("+-------+----------------------+--------+\n");
}

void mostrarComidas(sComida comidas[], int len)
{
    if(comidas != NULL && len > 0 && len <= TAMCOM)
    {
        printf("+=======+======================+========+\n");
        printf("|   ID  |      Descripcion     | Precio |\n");
        printf("+=======+======================+========+\n");
        for(int i=0; i < len; i++)
        {
            mostrarComidaSinEncabezado(comidas[i]);
        }
        printf("+-------+----------------------+--------+\n");
    }
}

void mostrarAlmuerzo(sAlmuerzo almuerzo, sAlumno alumno, sComida comida)
{
    printf("+=======+========+======================+======================+========+============+\n");
    printf("|  ID   | Legajo |       Alumno         |        Comida        | Precio |    Fecha   |\n");
    printf("+=======+========+======================+======================+========+============+\n");
    mostrarAlmuerzoSinEncabezado(almuerzo, alumno, comida);
    printf("+-------+--------+----------------------+----------------------+--------+------------+\n");
}

void mostrarAlmuerzos(sAlmuerzo almuerzos[], int lenAlmuerzos,
    sAlumno alumnos[], int lenAlumnos, sComida comidas[], int lenComidas)
{
    int indiceAlumno;
    int indiceComida;

    if(almuerzos!=NULL)
    {
        printf("+=======+========+======================+======================+========+============+\n");
        printf("|  ID   | Legajo |       Alumno         |        Comida        | Precio |    Fecha   |\n");
        printf("+=======+========+======================+======================+========+============+\n");

        for(int i = 0; i < lenAlmuerzos; i++)
        {
            indiceAlumno = buscarAlumnoPorLegajo(alumnos, lenAlumnos, almuerzos[i].idAlumno);

            if(indiceAlumno != -1)
            {
                indiceComida = buscarComidaPorId(comidas, lenComidas, almuerzos[i].idComida);

                if (indiceComida != -1) {
                    mostrarAlmuerzoSinEncabezado(almuerzos[i], alumnos[indiceAlumno], comidas[indiceComida]);
                }
            }
        }

        printf("+-------+--------+----------------------+----------------------+--------+------------+\n");
    }
}

static void mostrarComidaSinEncabezado(sComida comida)
{
    printf("| %5d | %20s | %5.2f |\n",
        comida.id, arrays_stringToCamelCase(comida.descripcion, NOMBRE_COMIDA), comida.precio);
}

static void mostrarAlmuerzoSinEncabezado(sAlmuerzo almuerzo, sAlumno alumno, sComida comida)
{
    printf("| %5d |  %5d | %20s | %20s | %5.2f | %02d/%02d/%4d |\n",
        almuerzo.id, alumno.legajo, arrays_stringToCamelCase(alumno.nombre, NOMBRE),
        arrays_stringToCamelCase(comida.descripcion, NOMBRE_COMIDA), comida.precio,
        almuerzo.fecha.day, almuerzo.fecha.month, almuerzo.fecha.year);
}
