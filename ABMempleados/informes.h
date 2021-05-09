#include "empleado.h"
#include "sectores.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

//informes

/** \brief informa la cantidad de empleados de un sector
 *
 * \param empleados[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamS int
 * \return void
 *
 */
int empleadosSector(eEmpleado lista[], int tam,eSector sectores[], int tamS);
int sueldosTotalesPorSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);///se fija los sueldos totales de cada sector y los muestra y muestra el total de sueldos
int actualizarSueldosPorSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);

