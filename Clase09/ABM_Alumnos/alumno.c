#include "alumno.h"

/** \brief Funcion que carga como un constructor los campos de un Alumno
 *
 * \param
 * \return
 *
 */
sAlumno newAlumno(int legajo, char nombre[TAM], int edad, char sexo,
    int notaParcial1, int notaParcial2, sDate fechaIngreso);

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

int altaAlumno(sAlumno vec[], int tam)
{
    int returnValue = 0;
    sAlumno alumnoAux;
    int indiceAlumno;
    int legajoExistente;

    if(vec != NULL && tam > 0)
    {
        indiceAlumno = buscarAlumnoLibre(vec, tam);

        if(indiceAlumno != -1)
        {
            if(!input_getInt(&alumnoAux.legajo, "Ingrese el legajo: ", "Intente nuevamente: ", 1000, 9999))
            {
                legajoExistente = buscarAlumnoPorLegajo(vec, tam, alumnoAux.legajo);
                if(legajoExistente != -1)
                {
                    printf("El legajo ya se encuentra registrado.\n");
                    mostrarAlumno(vec[legajoExistente]);
                }
                else
                {
                    if(!input_getString(alumnoAux.nombre, "Ingrese el nombre: ", "Intente nuevamente: ", 1, NOMBRE)
                        && !input_getInt(&alumnoAux.edad, "Ingrese la edad: ", "Intente nuevamente: ", 0, 150)
                        && !input_getChar(&alumnoAux.sexo, "Ingrese el sexo [f] o [m]: ", "Intente nuevamente: ", 'a', 'z')
                        && !input_getInt(&alumnoAux.notaParcial1, "Ingrese primer parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                        && !input_getInt(&alumnoAux.notaParcial2, "Ingrese segundo parcial [1-10]: ", "Intente nuevamente: ", 1, 10)
                        && !input_getDate(&alumnoAux.fechaIngreso, "Fecha de ingreso DD/MM/AAA: ", "Intente nuevamente: "))
                    {
                        vec[indiceAlumno] = newAlumno(alumnoAux.legajo, alumnoAux.nombre, alumnoAux.edad,
                            alumnoAux.sexo, alumnoAux.notaParcial1, alumnoAux.notaParcial2, alumnoAux.fechaIngreso);
                        returnValue = 1;
                    }
                }
            }
        }
        else
        {
            printf("Sistema de alumnos completo.\n");
        }
    }

    return returnValue;
}

int bajaAlumno(sAlumno vec[], int tam)
{
    int returnValue = 0;
    int legajo;
    int legajoExistente;
    char borrar;

    if(vec != NULL && tam > 0)
    {
        if(!input_getInt(&legajo, "Ingrese el legajo: ", "Intente nuevamente: ", 1000, 9999))
        {
            legajoExistente = buscarAlumnoPorLegajo(vec, tam, legajo);

            if(legajoExistente == -1)
            {
                printf("El legajo ingresado no existe.\n");
            }
            else
            {
                printf("El alumno es:\n");
                mostrarAlumno(vec[legajoExistente]);

                if(input_userResponse("Desea borrar? [S] [N]: "))
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

void mostrarAlumno(sAlumno alumno)
{
    printf("+============+=================+=======+=======+============+============+============+============+\n");
    printf("|   %s   |      %s     | %s  | %s  |   %s   |   %s   |  %s  |  %s   |\n",
        "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso");
    printf("+============+=================+=======+=======+============+============+============+============+\n");
    printf("| %10d | %15s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d |\n",
        alumno.legajo, alumno.nombre, alumno.edad, alumno.sexo, alumno.notaParcial1, alumno.notaParcial2,
        alumno.promedio, alumno.fechaIngreso.day, alumno.fechaIngreso.month, alumno.fechaIngreso.year);
    printf("+------------+-----------------+-------+-------+------------+------------+------------+------------+\n");
}

void mostrarAlumnos(sAlumno vec[], int tam)
{
    int flag = 0;

    if(vec != NULL && tam > 0)
    {
        printf("+============+=================+=======+=======+============+============+============+============+\n");
        printf("|   %s   |      %s     | %s  | %s  |   %s   |   %s   |  %s  |  %s   |\n",
            "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso");
        printf("+============+=================+=======+=======+============+============+============+============+\n");

        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == ALUMNO_CARGADO)
            {
                printf("| %10d | %15s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d |\n",
                    vec[i].legajo, vec[i].nombre, vec[i].edad, vec[i].sexo, vec[i].notaParcial1, vec[i].notaParcial2,
                    vec[i].promedio, vec[i].fechaIngreso.day, vec[i].fechaIngreso.month, vec[i].fechaIngreso.year);
                flag = 1;
            }
        }

        printf("+------------+-----------------+-------+-------+------------+------------+------------+------------+\n");
    }

    if(flag == 0)
    {
        printf("No hay alumnos que mostrar.\n");
    }
}

sAlumno newAlumno(int legajo, char nombre[NOMBRE], int edad, char sexo,
    int notaParcial1, int notaParcial2, sDate fechaIngreso)
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
    alumnoAux.isEmpty = ALUMNO_CARGADO;

    return alumnoAux;
}
