#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"


int mostrarComida(eComida unaComida)
{
    printf("%d      %s       %f  \n", unaComida.id, unaComida.descripcion, unaComida.precio);
}


int mostrarComidas(eComida comidas[], int tam)
{

    printf("\n  ******Lista de comidas******    \n");
    printf("ID       Descripcion     Precio \n");

    for(int i=0; i<tam; i++)
    {
        mostrarComida(comidas[i]);//llamo a la funcion que muestra una comida
    }

}

int buscarComida(eComida comidas[],int tam, int id)
{
    int indice=-1;///si no lo encunetra devuelve -1 que es imposible como indice

    if(comidasa!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(comidas[i].id == id)//si no es 1, es decir si esta ocupado && si el indice es igual al legajo que me pasan
            {
                indice=i;///guardo en la variable indice le indice de la estructura que coincide
                break;///si no rompe me devuelve el indice de la ultima estructura vacia y yo necesito el primero.
            }
        }
    }

    return indice;
}

