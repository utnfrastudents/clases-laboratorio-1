#ifndef COMIDAS_H_INCLUDED
#define COMIDAS_H_INCLUDED

typedef struct
{

    int id;
    char descripcion[20];
    float precio;

} eComida;

typedef struct
{

    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;

} eAlmuerzo;

#endif // COMIDAS_H_INCLUDED

void mostrarComidas(eComida comidas[], int tam);
void mostrarComida(eComida comida);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);
void inicializarAlmuerzos(eAlmuerzo vec[], int tam);
int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzo(eAlmuerzo x, eComida comidas[], int tamC);
void mostrarAlmuerzos(eAlmuerzo vec[], int tam,  eComida comidas[], int tamC);
int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam);
int altaAlmuerzo( eAlmuerzo almuerzos[], int tAlmuerzo,int idAlmuerzo, eComida comidas[],int tComida, eAlumno alumnos[],int tAlumno, eCarrera carreras[],int tCarrera);
eAlmuerzo newAlmuerzo(int id,int legajo,int idComida, eFecha fecha);
int compararFechas( eFecha f1, eFecha f2);




























