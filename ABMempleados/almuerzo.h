
#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

#include "fecha.h"
#include "empleado.h"
#include "sectores.h"
#include "comida.h"

typedef struct
{
    int id;
    int legajoEmpleado;//foreign key
    int idComida;
    eFecha fecha;//fecha de cuando el empleado comio la comida
    int isEmpty;
}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED


///almuerzo se comporta como empleados

int inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int buscarLibreAlmuerzos(eAlmuerzo almuerzos[], int tam);///devuelve el indice del primer almuerzo libre
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, eEmpleado lista[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC, int* pIdAlmuerzo);///se fija si hay lugar, muestra los empleados y pide legajo, muestra las comidas y pide ID de comida, pide la fecha e inserta el almuerazo en el indice del array que da buscarLibre()
int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam);//id comida, empleado, fecha, si quiero con nombre tiene que se parecida a cargarDescripcionSector
int mostrarAlmuerzo(eAlmuerzo unAlmuerzo);
