#include "alumnos.h"

/** \brief Funcion que carga como un constructor los campos de un Alumno
 *
 * \param
 * \return
 *
 */
sAlumno newAlumno(int legajo, char nombre[NOMBRE], int edad, char sexo,
    int notaParcial1, int notaParcial2, sDate fechaIngreso, int idCarrera);

void inicializarAlumnos(sAlumno vec[], int tam)
{
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = ALUMNO_VACIO;
        }
    }
}

int buscarAlumnoLibre(sAlumno vec[], int tam)
{
    int indice = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == ALUMNO_VACIO)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int buscarAlumnoPorLegajo(sAlumno vec[], int tam, int legajo)
{
    int indice = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if(vec[i].legajo == legajo
                && vec[i].isEmpty == ALUMNO_CARGADO)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int altaAlumno(sAlumno vec[], int tam, int legajo, sCarrera carreras[], int tam_carreras)
{
    int returnValue = 0;
    sAlumno alumnoAux;
    int indiceAlumno;
    int legajoExistente;

    if(vec != NULL && tam > 0)
    {
        indiceAlumno = buscarAlumnoLibre(vec, tam);

        if(indiceAlumno == -1)
        {
            printf("Sistema de alumnos completo.\n");
        }
        else
        {
            legajoExistente = buscarAlumnoPorLegajo(vec, tam, legajo);

            if(legajoExistente != -1)
            {
                printf("El legajo ya se encuentra registrado.\n");
                mostrarAlumno(vec[legajoExistente], carreras, tam_carreras);
            }
            else
            {
                if(!inputs_getString(alumnoAux.nombre, "Ingrese el nombre: ", "Intente nuevamente: ", 1, NOMBRE)
                    && !inputs_getInt(&alumnoAux.edad, "Ingrese la edad: ", "Intente nuevamente: ", 0, 150)
                    && !inputs_getChar(&alumnoAux.sexo, "Ingrese el sexo [f] o [m]: ", "Intente nuevamente: ", 'a', 'z')
                    && !inputs_getInt(&alumnoAux.notaParcial1, "Ingrese primer parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                    && !inputs_getInt(&alumnoAux.notaParcial2, "Ingrese segundo parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                    && !inputs_getDate(&alumnoAux.fechaIngreso, "Fecha de ingreso DD/MM/AAA: ", "Intente nuevamente: "))
                {
                    mostrarCarreras(carreras, tam_carreras);
                    if(inputs_getInt(&alumnoAux.idCarrera, "Elija una carrera: ", "Intente nuevamente: ", 1000, 1002))
                    {
                        vec[indiceAlumno] = newAlumno(legajo, alumnoAux.nombre, alumnoAux.edad, alumnoAux.sexo,
                            alumnoAux.notaParcial1, alumnoAux.notaParcial2, alumnoAux.fechaIngreso, alumnoAux.idCarrera);
                        returnValue = 1;
                    }
                }
            }
        }
    }

    return returnValue;
}

int bajaAlumno(sAlumno vec[], int tam, sCarrera carreras[], int tam_carreras)
{
    int returnValue = 0;
    int legajo;
    int legajoExistente;

    if(vec != NULL && tam > 0)
    {
        if(!inputs_getInt(&legajo, "Ingrese el legajo: ", "Intente nuevamente: ", 1000, 9999))
        {
            legajoExistente = buscarAlumnoPorLegajo(vec, tam, legajo);

            if(legajoExistente == -1)
            {
                printf("El legajo ingresado no existe.\n");
            }
            else
            {
                printf("El alumno es:\n");
                mostrarAlumno(vec[legajoExistente], carreras, tam_carreras);

                if(inputs_userResponse("Desea borrar? [S] [N]: "))
                {
                    vec[legajoExistente].isEmpty = ALUMNO_VACIO;
                    printf("Alumno borrado.\n");
                }
                else
                {
                    printf("Operacion cancelada.\n");
                }

            }
        }
    }

    return returnValue;
}

void mostrarAlumno(sAlumno alumno, sCarrera vec[], int tam)
{
    char descrip[NOM_CARRERA];

    if(buscarCarreraPorId(alumno.idCarrera, vec, tam, descrip))
    {
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");
        printf("|   %s   |        %s        | %s  | %s  |   %s   |   %s   |  %s  |  %s   | %s |\n",
                "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso", "Carrera");
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");
        printf("| %10d | %20s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d | %7s |\n",
            alumno.legajo, arrays_stringToCamelCase(alumno.nombre, NOMBRE),
            alumno.edad, alumno.sexo, alumno.notaParcial1,
            alumno.notaParcial2, alumno.promedio, alumno.fechaIngreso.day,
            alumno.fechaIngreso.month, alumno.fechaIngreso.year, descrip);
        printf("+------------+----------------------+-------+-------+------------+------------+------------+------------+---------+\n");
    }
    else
    {
        printf("El alumno no tiene carrera asignada.\n");
    }
}

void mostrarAlumnos(sAlumno vec[], int tam, sCarrera carreras[], int tam_carreras)
{
    int flag = 0;
    char descrip[NOM_CARRERA];

    if(vec != NULL && tam > 0)
    {
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");
        printf("|   %s   |        %s        | %s  | %s  |   %s   |   %s   |  %s  |  %s   | %s |\n",
                "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso", "Carrera");
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");

        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == ALUMNO_CARGADO && buscarCarreraPorId(vec[i].idCarrera, carreras, tam_carreras, descrip))
            {
                printf("| %10d | %20s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d | %7s |\n",
                    vec[i].legajo, arrays_stringToCamelCase(vec[i].nombre, NOMBRE), vec[i].edad, vec[i].sexo,
                    vec[i].notaParcial1, vec[i].notaParcial2, vec[i].promedio, vec[i].fechaIngreso.day,
                    vec[i].fechaIngreso.month, vec[i].fechaIngreso.year, descrip);
                flag = 1;
            }
        }

        printf("+------------+----------------------+-------+-------+------------+------------+------------+------------+---------+\n");
    }

    if(flag == 0)
    {
        printf("No hay alumnos que mostrar.\n");
    }
}

sAlumno newAlumno(int legajo, char nombre[NOMBRE], int edad, char sexo,
    int notaParcial1, int notaParcial2, sDate fechaIngreso, int idCarrera)
{
    sAlumno alumnoAux;

    alumnoAux.legajo = legajo;
    strncpy(alumnoAux.nombre, nombre, NOMBRE);
    alumnoAux.edad = edad;
    alumnoAux.sexo = sexo;
    alumnoAux.notaParcial1 = notaParcial1;
    alumnoAux.notaParcial2 = notaParcial2;
    alumnoAux.fechaIngreso = fechaIngreso;
    alumnoAux.promedio = (float)(notaParcial1 + notaParcial2)/2;
    alumnoAux.idCarrera = idCarrera;
    alumnoAux.isEmpty = ALUMNO_CARGADO;

    return alumnoAux;
}

int hardcodearAlumnos(sAlumno vec[], int tam, int cantidad)
{
    int contador = 0;

    sAlumno suplentes[] = {
        {1994, "juan sosa", 20, 'm', 4, 6, 5, {16, 10, 2019}, 1001, 0},
        {1997, "juana martinez", 19, 'f', 7, 4, 5, {20, 2, 2016}, 1000, 0},
        {1996, "ariel perez", 20, 'm', 8, 6, 7, {12, 5, 2014}, 1002, 0},
        {1991, "alicia saenz", 21, 'f', 9, 6, 7, {9, 7, 2013}, 1001, 0},
        {1995, "nahuel hernandez", 30, 'm', 2, 4, 3, {4, 12, 2019}, 1001, 0},
        {1992, "carlos llorente", 33, 'm', 4, 6, 5, {26, 6, 2017}, 1000, 0},
        {1998, "manuela lopez", 39, 'f', 7, 4, 5, {10, 8, 2015}, 1002, 0},
        {2000, "ricado perez", 22, 'm', 8, 6, 7, {15, 11, 2009}, 1000, 0},
        {1999, "sol diaz", 27, 'f', 9, 6, 7, {30, 3, 2012}, 1002, 0},
        {1993, "micael rodriguez", 20, 'm', 2, 4, 3, {10, 1, 2018}, 1001, 0}
    };

    if(vec != NULL && cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            contador++;
        }
    }

    return contador;
}
