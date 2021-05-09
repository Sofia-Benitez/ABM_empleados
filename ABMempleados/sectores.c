#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sectores.h"
#include "empleado.h"


///funciones de SECTORES

void mostrarSector(eSector unSector)
{
    printf("     %d     %10s\n", unSector.id, unSector.descripcion);

}


void mostrarSectores(eSector sectores[], int tam)
{
    printf("Lista de sectores\n\n");
    printf("     ID     Descripcion\n");

    for(int i=0; i<tam; i++)
    {
        mostrarSector(sectores[i]);
    }
    printf("\n\n");
}

int cargarDescripcionSector(int id, eSector sectores[], int tam, char descripcion[])
{
    int todoOk=0;

    if(id>=500 &&  id<=504 && sectores!=NULL && tam>0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(sectores[i].id==id)
            {
                strcpy(descripcion, sectores[i].descripcion);///cargo la cadena que me pasan en la funcion
                todoOk=1;
                break;///ya consegui la descripcion correspondiente
            }
        }
    }

    return todoOk;
}


