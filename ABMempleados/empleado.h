#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "sectores.h"
#include "fecha.h"

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

}eEmpleado;

#endif // EMPLEADO_H_INCLUDED




void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS);//recibe un array y lo recorre
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam);//recibe una estrutura y la muestra, recibe los sectores para cargar la descripcion y el tamanio del array

/** \brief funcion que ordena empleados segun distintos criterios
 *
 * \param lista[] eEmpleado    array de eEmpleado
 * \param tam int              tamanio del array
 * \param criterio int         criterio de ordenamiento(criterio 1: edad descendiente / criterio 0:Nombre ascendente(A-Z) /  criterio 2:sexo descendente y legajo ascendente)
 * \return int                 devuelve 0 si no se puede ejecutar y 1 si se ejecuta correctamente
 *
 */
int ordenarEmpleados(eEmpleado lista[], int tam, int criterio);//recibe un array, un tamanio y un criterio de ordenamiento


void inicializarEmpleados(eEmpleado lista[], int tam);
int altaEmpleado(eEmpleado lista[], int tam, int* pId, eSector sectores[], int tamSec);//le paso el array, el tamanio y el id siguiente
int buscarLibre(eEmpleado lista[], int tam);
int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
int harcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo);
