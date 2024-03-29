#include "alumnos.h"

/** \brief Funcion que carga como un constructor los campos de un Alumno
 *
 * \param
 * \return
 *
 */
sAlumno newAlumno(int legajo, char nombre[NOMBRE], int edad, char sexo,
    int notaParcial1, int notaParcial2, sDate fechaIngreso, int idCarrera);

static int alumnosCompare(sAlumno alumno1, sAlumno alumno2);
static int swapAlumnos(sAlumno* alumno1, sAlumno* alumno2);
int cantidadAlumnosPorCarrera(sAlumno alumnos[], int tam_alumnos, int idCarrera);
float promedioMasAltoPorCarrera(sAlumno alumnos[], int tam_alumnos, int idCarrera);

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
                    if(!inputs_getInt(&alumnoAux.idCarrera, "Elija una carrera: ", "Intente nuevamente: ", 1000, 1002))
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
                    returnValue = 1;
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

int modificarAlumno(sAlumno vec[], int tam, sCarrera carreras[], int tam_carreras)
{
    int returnValue = 0;
    int legajo;
    int legajoExistente;
    int optionUpdateMenu = 0;
    int nuevaNota;

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

                if(inputs_userResponse("Desea modificar las notas del alumno? [S] [N]: "))
                {
                    if(menu_update(&optionUpdateMenu) == -1)
                    {
                        printf("Operacion cancelada.\n");
                    }
                    else
                    {
                        switch (optionUpdateMenu)
                        {
                            case 1:
                                if(!inputs_getInt(&nuevaNota, "Ingrese la nueva nota 1 de [1-10]: ", "Intente nuevamente: ", 1, 10))
                                {
                                    vec[legajoExistente].notaParcial1 = nuevaNota;
                                    vec[legajoExistente].promedio = (float)(nuevaNota + vec[legajoExistente].notaParcial2)/2;
                                    returnValue = 1;
                                }
                                break;
                            case 2:
                                if(!inputs_getInt(&nuevaNota, "Ingrese la nueva nota 2 de [1-10]: ", "Intente nuevamente: ", 1, 10))
                                {
                                    vec[legajoExistente].notaParcial2 = nuevaNota;
                                    vec[legajoExistente].promedio = (float)(vec[legajoExistente].notaParcial1 + nuevaNota)/2;
                                    returnValue = 1;
                                }
                                break;
                        }
                    }
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

int ordenarAlumnosPorLegajo(sAlumno vec[], int tam, int criterio)
{
    int orderValue = -1;

    if(vec != NULL && tam > 0 && (criterio == ASC || criterio == DESC))
    {
        for(int i= 0; i < tam-1 ; i++)
        {
            for(int j= i+1; j <tam; j++)
            {
                if((vec[i].legajo > vec[j].legajo && criterio == ASC)
                    || (vec[i].legajo < vec[j].legajo && criterio == DESC))
                {
                    if(!swapAlumnos(&vec[i], &vec[j]))
                    {
                        orderValue = 0;
                    }
                }
            }
        }
    }

    return orderValue;
}

int ordenarAlumnosPorNombre(sAlumno vec[], int tam, int criterio)
{
    int orderValue = -1;

    if(vec != NULL && tam > 0 && (criterio == ASC || criterio == DESC))
    {
        for(int i= 0; i < tam-1 ; i++)
        {
            for(int j= i+1; j <tam; j++)
            {
                if((strcmp(vec[i].nombre, vec[j].nombre) > 0 && criterio == ASC)
                    || (strcmp(vec[i].nombre, vec[j].nombre) < 0 && criterio == DESC))
                {
                    if(!swapAlumnos(&vec[i], &vec[j]))
                    {
                        orderValue = 0;
                    }
                }
            }
        }
    }

    return orderValue;
}

int ordenarAlumnosPorSexoEdad(sAlumno vec[], int tam, int criterioEdad)
{
    int orderValue = -1;

    if(vec != NULL && tam > 0 && (criterioEdad == ASC || criterioEdad == DESC))
    {
        for(int i= 0; i < tam-1 ; i++)
        {
            for(int j= i+1; j <tam; j++)
            {
                if((vec[i].sexo > vec[j].sexo))
                {
                    if(!swapAlumnos(&vec[i], &vec[j]))
                    {
                        orderValue = 0;
                    }
                }
                else
                {
                    if(vec[i].sexo == vec[j].sexo)
                    {
                        if((vec[i].edad > vec[j].edad && criterioEdad == ASC)
                            || (vec[i].edad < vec[j].edad && criterioEdad == DESC))
                        {
                            if(!swapAlumnos(&vec[i], &vec[j]))
                            {
                                orderValue = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return orderValue;
}

int ordenarAlumnosPorPromedio(sAlumno vec[], int tam, int criterio)
{
    int orderValue = -1;

    if(vec != NULL && tam > 0 && (criterio == ASC || criterio == DESC))
    {
        for(int i= 0; i < tam-1 ; i++)
        {
            for(int j= i+1; j <tam; j++)
            {
                if((vec[i].promedio > vec[j].promedio && criterio == ASC)
                    || (vec[i].promedio < vec[j].promedio && criterio == DESC))
                {
                    if(!swapAlumnos(&vec[i], &vec[j]))
                    {
                        orderValue = 0;
                    }
                }
            }
        }
    }

    return orderValue;
}

int ordenarAlumnosPorFechaIngreso(sAlumno vec[], int tam, int criterio)
{
    int orderValue = -1;

    if(vec != NULL && tam > 0 && (criterio == ASC || criterio == DESC))
    {
        for(int i= 0; i < tam-1 ; i++)
        {
            for(int j= i+1; j <tam; j++)
            {
                if((structs_dateCompare(vec[i].fechaIngreso, vec[j].fechaIngreso) == 1 && criterio == ASC)
                    || (structs_dateCompare(vec[i].fechaIngreso, vec[j].fechaIngreso) == -1 && criterio == DESC))
                {
                    if(!swapAlumnos(&vec[i], &vec[j]))
                    {
                        orderValue = 0;
                    }
                }
            }
        }
    }

    return orderValue;
}

int ordenarAlumnosPorCarreraNombre(sAlumno vec[], int tam, int criterioNombre)
{
    int orderValue = -1;

    if(vec != NULL && tam > 0 && (criterioNombre == ASC || criterioNombre == DESC))
    {
        for(int i= 0; i < tam-1 ; i++)
        {
            for(int j= i+1; j <tam; j++)
            {
                if((vec[i].idCarrera > vec[j].idCarrera))
                {
                    if(!swapAlumnos(&vec[i], &vec[j]))
                    {
                        orderValue = 0;
                    }
                }
                else
                {
                    if(vec[i].idCarrera == vec[j].idCarrera)
                    {
                        if((strcmp(vec[i].nombre, vec[j].nombre) > 0 && criterioNombre == ASC)
                            || (strcmp(vec[i].nombre, vec[j].nombre) < 0 && criterioNombre == DESC))
                        {
                            if(!swapAlumnos(&vec[i], &vec[j]))
                            {
                                orderValue = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return orderValue;
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

    if(vec != NULL && tam > 0 && carreras != NULL && tam_carreras > 0)
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

void mostrarAlumnosPorCarrera(sAlumno vec[], int tam_alumnos, sCarrera carreras[], int tam_carreras, int idCarrera)
{
    int flag = 0;
    char descrip[NOM_CARRERA];
    int contador = 0;

    if(vec != NULL && tam_alumnos > 0 && carreras != NULL && tam_carreras > 0)
    {
        for(int i=0; i < tam_alumnos; i++)
        {
            if(vec[i].isEmpty == ALUMNO_CARGADO
                && buscarCarreraPorId(idCarrera, carreras, tam_carreras, descrip))
            {
                contador++;
                if(contador == 1)
                {
                    printf("+============+======================+=======+=======+============+============+============+============+\n");
                    printf("|                                    CARRERA: %s                                                      |\n", descrip);
                    printf("+============+======================+=======+=======+============+============+============+============+\n");
                    printf("|   %s   |        %s        | %s  | %s  |   %s   |   %s   |  %s  |  %s   |\n",
                            "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso");
                    printf("+============+======================+=======+=======+============+============+============+============+\n");
                }

                if(vec[i].idCarrera == idCarrera)
                {
                    printf("| %10d | %20s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d |\n",
                        vec[i].legajo, arrays_stringToCamelCase(vec[i].nombre, NOMBRE), vec[i].edad, vec[i].sexo,
                        vec[i].notaParcial1, vec[i].notaParcial2, vec[i].promedio, vec[i].fechaIngreso.day,
                        vec[i].fechaIngreso.month, vec[i].fechaIngreso.year);
                    flag = 1;
                }
            }
        }

        if(flag == 1)
        {
            printf("+------------+----------------------+-------+-------+------------+------------+------------+------------+\n");
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos que mostrar.\n");
    }
}

void mostrarAlumnosTodasLasCarreras(sAlumno vec[], int tam_alumnos, sCarrera carreras[], int tam_carreras)
{
    for(int i = 1000; i <= 1002; i++)
    {
        mostrarAlumnosPorCarrera(vec, tam_alumnos, carreras, tam_carreras, i);
    }
}

void mostrarCantidadAlumnosPorCarrera(sAlumno vec[], int tam_alumnos, sCarrera carreras[], int tam_carreras)
{
    int flag = 0;
    int contador = 0;
    int cantidadAlumnos = 0;

    if(vec != NULL && tam_alumnos > 0 && carreras != NULL && tam_carreras > 0)
    {
        for(int i = 0; i < tam_carreras; i++)
        {
            contador++;
            if(contador == 1)
            {
                printf("+=========+=========+\n");
                printf("| %7s | %7s |\n", "Carrera", "Alumnos");
                printf("+=========+=========+\n");
            }

            cantidadAlumnos = cantidadAlumnosPorCarrera(vec, tam_alumnos, carreras[i].idCarrera);

            if (cantidadAlumnos > 0)
            {
                printf("| %7s | %7d |\n", carreras[i].descripcion, cantidadAlumnos);
                flag = 1;
            }

            if (flag == 1)
            {
                printf("+---------+---------+\n");
            }
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos que mostrar.\n");
    }
}

void mostrarCarreraConMasInscriptos(sAlumno vec[], int tam_alumnos, sCarrera carreras[], int tam_carreras)
{
    int cantidadMaxima = 0;
    int aux;

    for (int i = 0; i < tam_carreras; i++)
    {
        aux = cantidadAlumnosPorCarrera(vec, tam_alumnos, carreras[i].idCarrera);
        if (aux > cantidadMaxima)
        {
            cantidadMaxima = aux;
        }
    }

    if (cantidadMaxima > 0)
    {
        printf("======================================\n");
        printf("      CARRERA CON MAS ALUMNOS\n");
        printf("======================================\n");

        for (int i = 0; i < tam_carreras; i++)
        {
            if(cantidadAlumnosPorCarrera(vec, tam_alumnos, carreras[i].idCarrera) == cantidadMaxima)
            {
                printf("La carrera %s tiene %d alumnos.\n", carreras[i].descripcion, cantidadMaxima);
            }
        }

        printf("--------------------------------------\n");
    }
}

void mostrarMejorPromedioPorCarrera(sAlumno alumnos[], int tam_alumnos, sCarrera carreras[], int tam_carreras)
{
    int flag = 0;
    int contador = 0;
    char descrip[NOM_CARRERA];

    if (alumnos != NULL && tam_alumnos > 0 && carreras != NULL && tam_carreras > 0)
    {
        for(int i = 0; i < tam_carreras; i++)
        {
            contador++;
            if(contador == 1)
            {
                printf("+========+======================+========+========+==========+=========+\n");
                printf("| %6s | %20s | %6s | %6s | %8s | %7s |\n",
                        "Legajo", "Nombre", "Nota 1", "Nota 2", "Promedio", "Carrera");
                printf("+========+======================+========+========+==========+=========+\n");
            }

            for (int j = 0; j < tam_alumnos; j++)
            {
                if(alumnos[j].idCarrera == carreras[i].idCarrera
                    && alumnos[j].promedio == promedioMasAltoPorCarrera(alumnos, tam_alumnos, carreras[i].idCarrera)
                    && buscarCarreraPorId(carreras[i].idCarrera, carreras, tam_carreras, descrip))
                {
                    printf("| %6d | %20s | %6d | %6d |     %.2f | %7s |\n",
                        alumnos[j].legajo, arrays_stringToCamelCase(alumnos[j].nombre, NOMBRE),
                        alumnos[j].notaParcial1, alumnos[j].notaParcial2, alumnos[j].promedio, descrip);
                    flag = 1;
                }
            }
        }

        if (flag == 1)
        {
            printf("+--------+----------------------+--------+--------+----------+---------+\n");
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos que mostrar.\n");
    }
}

void mostrarAlumnosVarones(sAlumno alumnos[], int tam_alumnos, sCarrera carreras[], int tam_carreras)
{
    int flag = 0;
    char descrip[NOM_CARRERA];

    if(alumnos != NULL && tam_alumnos > 0 && carreras != NULL && tam_carreras > 0)
    {
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");
        printf("|   %s   |        %s        | %s  | %s  |   %s   |   %s   |  %s  |  %s   | %s |\n",
                "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso", "Carrera");
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");

        for(int i=0; i < tam_alumnos; i++)
        {
            if(alumnos[i].isEmpty == ALUMNO_CARGADO
                && buscarCarreraPorId(alumnos[i].idCarrera, carreras, tam_carreras, descrip)
                && toupper(alumnos[i].sexo) == 'M')
            {
                printf("| %10d | %20s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d | %7s |\n",
                    alumnos[i].legajo, arrays_stringToCamelCase(alumnos[i].nombre, NOMBRE), alumnos[i].edad, alumnos[i].sexo,
                    alumnos[i].notaParcial1, alumnos[i].notaParcial2, alumnos[i].promedio, alumnos[i].fechaIngreso.day,
                    alumnos[i].fechaIngreso.month, alumnos[i].fechaIngreso.year, descrip);
                flag = 1;
            }
        }

        if (flag == 1)
        {
            printf("+------------+----------------------+-------+-------+------------+------------+------------+------------+---------+\n");
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos varones que mostrar.\n");
    }
}

void mostrarMujeresPorCarrera(sAlumno alumnos[], int tam_alumnos, sCarrera carreras[], int tam_carreras, int idCarrera)
{
    int flag = 0;
    char descrip[NOM_CARRERA];

    if(alumnos != NULL && tam_alumnos > 0 && carreras != NULL && tam_carreras > 0)
    {
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");
        printf("|   %s   |        %s        | %s  | %s  |   %s   |   %s   |  %s  |  %s   | %s |\n",
                "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso", "Carrera");
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");

        for(int i=0; i < tam_alumnos; i++)
        {
            if(alumnos[i].isEmpty == ALUMNO_CARGADO
                && buscarCarreraPorId(alumnos[i].idCarrera, carreras, tam_carreras, descrip)
                && toupper(alumnos[i].sexo) == 'F'
                && alumnos[i].idCarrera == idCarrera)
            {
                printf("| %10d | %20s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d | %7s |\n",
                    alumnos[i].legajo, arrays_stringToCamelCase(alumnos[i].nombre, NOMBRE), alumnos[i].edad, alumnos[i].sexo,
                    alumnos[i].notaParcial1, alumnos[i].notaParcial2, alumnos[i].promedio, alumnos[i].fechaIngreso.day,
                    alumnos[i].fechaIngreso.month, alumnos[i].fechaIngreso.year, descrip);
                flag = 1;
            }
        }

        if (flag == 1)
        {
            printf("+------------+----------------------+-------+-------+------------+------------+------------+------------+---------+\n");
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnas mujeres que mostrar.\n");
    }
}

void mostrarAlumnosMayoresDe30DeLicenciatura(sAlumno alumnos[], int tam_alumnos, sCarrera carreras[], int tam_carreras)
{
    int flag = 0;
    char descrip[NOM_CARRERA];

    if(alumnos != NULL && tam_alumnos > 0 && carreras != NULL && tam_carreras > 0)
    {
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");
        printf("|   %s   |        %s        | %s  | %s  |   %s   |   %s   |  %s  |  %s   | %s |\n",
                "Legajo", "Nombre", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio", "Ingreso", "Carrera");
        printf("+============+======================+=======+=======+============+============+============+============+=========+\n");

        for(int i=0; i < tam_alumnos; i++)
        {
            if(alumnos[i].isEmpty == ALUMNO_CARGADO
                && buscarCarreraPorId(alumnos[i].idCarrera, carreras, tam_carreras, descrip)
                && !strcmp(descrip, "LIC")
                && alumnos[i].edad > 30)
            {
                printf("| %10d | %20s | %5d | %5c | %10d | %10d | %10.2f | %02d/%02d/%4d | %7s |\n",
                    alumnos[i].legajo, arrays_stringToCamelCase(alumnos[i].nombre, NOMBRE), alumnos[i].edad, alumnos[i].sexo,
                    alumnos[i].notaParcial1, alumnos[i].notaParcial2, alumnos[i].promedio, alumnos[i].fechaIngreso.day,
                    alumnos[i].fechaIngreso.month, alumnos[i].fechaIngreso.year, descrip);
                flag = 1;
            }
        }

        if (flag == 1)
        {
            printf("+------------+----------------------+-------+-------+------------+------------+------------+------------+---------+\n");
        }
    }

    if(flag == 0)
    {
        printf("No hay alumnos mayores de 30 en licenciatura que mostrar.\n");
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
        {1994, "juan sosa", 25, 'm', 4, 6, 5, {16, 10, 2019}, 1001, 0},
        {1997, "juana martinez", 19, 'f', 7, 4, 5.5, {20, 2, 2016}, 1001, 0},
        {1996, "ariel perez", 20, 'm', 8, 6, 7, {12, 5, 2014}, 1002, 0},
        {1991, "alicia saenz", 21, 'f', 9, 6, 7.5, {9, 7, 2013}, 1001, 0},
        {1995, "nahuel hernandez", 30, 'm', 2, 4, 3, {4, 12, 2019}, 1001, 0},
        {1992, "carlos llorente", 33, 'm', 4, 5, 4.5, {26, 6, 2017}, 1000, 0},
        {1998, "manuela lopez", 39, 'f', 7, 5, 6, {10, 8, 2015}, 1002, 0},
        {1990, "ricado perez", 22, 'm', 8, 9, 8.5, {15, 11, 2009}, 1000, 0},
        {1999, "sol diaz", 27, 'f', 9, 7, 8, {30, 3, 2012}, 1002, 0},
        {1993, "micael rodriguez", 20, 'm', 2, 6, 4, {10, 1, 2018}, 1001, 0}
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

static int alumnosCompare(sAlumno alumno1, sAlumno alumno2)
{
    int returnValue = -1;

    if(alumno1.legajo == alumno2.legajo
        && !strcmp(alumno1.nombre, alumno2.nombre)
        && alumno1.edad == alumno2.edad
        && alumno1.sexo == alumno2.sexo
        && alumno1.notaParcial1 == alumno2.notaParcial1
        && alumno1.notaParcial2 == alumno2.notaParcial2
        && alumno1.promedio == alumno2.promedio
        && !structs_dateCompare(alumno1.fechaIngreso, alumno2.fechaIngreso)
        && alumno1.idCarrera == alumno2.idCarrera
        && alumno1.isEmpty == alumno2.isEmpty)
    {
        returnValue = 0;
    }

    return returnValue;
}

static int swapAlumnos(sAlumno* alumno1, sAlumno* alumno2)
{
    int returnValue = -1;
    sAlumno aux1;

    aux1 = *alumno1;
    *alumno1 = *alumno2;
    *alumno2 = aux1;

    if(!alumnosCompare(*alumno1, *alumno2))
    {
        returnValue = 0;
    }

    return returnValue;
}

int cantidadAlumnosPorCarrera(sAlumno alumnos[], int tam_alumnos, int idCarrera)
{
    int contador = 0;

    if(alumnos != NULL && tam_alumnos >0)
    {
        for(int i=0; i< tam_alumnos; i++)
        {
            if(alumnos[i].isEmpty == ALUMNO_CARGADO
                && alumnos[i].idCarrera == idCarrera)
            {
                contador++;
            }
        }
    }

    return contador;
}

float promedioMasAltoPorCarrera(sAlumno alumnos[], int tam_alumnos, int idCarrera)
{
    float promedioMax = 0;

    if(alumnos != NULL && tam_alumnos >0)
    {
        for (int i = 0; i < tam_alumnos; i++)
        {
            //printf("->[debug]: Carrera %d - Promedio %.2f - isEmpty %d\n", alumnos[i].idCarrera, alumnos[i].promedio, alumnos[i].isEmpty);
            if(alumnos[i].isEmpty == ALUMNO_CARGADO
                && alumnos[i].idCarrera == idCarrera
                && alumnos[i].promedio > promedioMax)
            {
                promedioMax = alumnos[i].promedio;
            }
        }
    }

    return promedioMax;
}
