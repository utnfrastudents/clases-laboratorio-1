#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eCarrera;



#endif // CARRERA_H_INCLUDED

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarCarreras(eCarrera carreras[], int tam);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void mostrarCarrera(eCarrera carrera);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarDescCarrera(int id, eCarrera carreras[], int tam, char desc[]);
