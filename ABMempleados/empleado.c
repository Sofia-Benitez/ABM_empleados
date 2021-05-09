#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "informes.h"
#include "sectores.h"
#include "datawarehouse.h"


///funciones de empleados

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam)
{
    char descripcion[20];
    cargarDescripcionSector(unEmpleado.idSector, sectores, tam, descripcion);

    printf("%d             %s            %d           %c            %.2f         %02d/%02d/%d      %s\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fechaIngreso.dia,
           unEmpleado.fechaIngreso.mes,
           unEmpleado.fechaIngreso.anio,
           descripcion);

}

void inicializarEmpleados(eEmpleado lista[], int tam)
{

    for(int i=0; i<tam; i++)//recorro el array para inicializar
    {
           lista[i].isEmpty=1;
    }

}

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    int flag=1;
    printf("\n                      ******Nomina de empleados******\n");
    printf("Legajo        Nombre           Edad          Sexo         Sueldo         Fecha de ingreso     Sector \n");

    for(int i=0; i<tam; i++)
    {
       if(lista[i].isEmpty==0)///muestra los que estan en el indice que estan ocupados
       {
            mostrarEmpleado(lista[i], sectores, tamS);//llamo a la funcion que muestra un empleado.
            flag=0;
       }
    }
   if(flag)
   {
       printf("No hay empleados en la lista");
   }
   printf("\n\n");


}


int ordenarEmpleados(eEmpleado lista[], int tam, int criterio)//criterio 1: edad descendiente, criterio 0:Nombre ascendente(A-Z), criterio 2:sexo descendente y legajo ascendente
{
    int todoOk=0;//si no se puede ordenar
    eEmpleado auxEmpleado;//auxiliar de lo que voy a ordenar

    if(lista!=NULL && tam>0 && criterio>=0 && criterio <=2)//validacion
    {
       if(criterio==1)//edad descendiente
       {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(lista[i].edad<lista[j].edad)//si se da los elementos estan desordenados
                    {
                        auxEmpleado=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEmpleado;
                    }
                }
            }
       }
       else
       {
           if(criterio==0)//ordenar por nombre ascendente  A-Z
           {
                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if(strcmp(lista[i].nombre, lista[j].nombre)>0)//si se da los elementos estan desordenados
                        {
                            auxEmpleado=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxEmpleado;
                        }
                    }
                }
           }
           else//criterio 2 //ordeno por sexo descendente y legajo ascendente
           {
                for(int i=0; i<tam-1; i++)
                {
                    for(int j=i+1; j<tam; j++)
                    {
                        if(lista[i].sexo < lista[j].sexo || (lista[i].sexo==lista[j].sexo && lista[i].legajo>lista[j].legajo))//si se da los elementos estan desordenados
                        {
                            auxEmpleado=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxEmpleado;
                        }
                    }
                }
           }

       }

       todoOk=1;
    }

    return todoOk;
}





int buscarLibre(eEmpleado lista[], int tam)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty)//si es 1
            {
                indice=i;
                break;///si no rompe me devuelve el indice de la ultima estructura vacia y yo necesito el primero.
            }
        }

    }

    return indice;
}


int altaEmpleado(eEmpleado lista[], int tam, int* pId, eSector sectores[], int tamSec)///devuelve 0 si no se puede y 1 si se puede
{
    int todoOk=0;
    int indice;


    eEmpleado nuevoEmpleado;  ///auxiliar


    if(lista!=NULL && tam>0 && pId!=NULL)
    {
        system("cls");
        printf("Alta empleado\n\n");
        printf("Legajo: %d\n", *pId);
        indice=buscarLibre(lista, tam);
        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {

            nuevoEmpleado.legajo= *pId; ///traigo el id

            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese la edad: ");
            scanf("%d", &nuevoEmpleado.edad);

            printf("Ingrese el sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese el sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);

            mostrarSectores(sectores, tamSec);
            printf("Ingrese el sector: ");
            scanf("%d", &nuevoEmpleado.idSector);

            nuevoEmpleado.isEmpty=0;///ahora es una estructura cargada

            lista[indice]=nuevoEmpleado;///copio el contenido al array

            ///actualizo el proximo id
            *pId=(*pId)+1;   ///referencia al nextId del main e incrementacion


             todoOk=1;
        }

    }

    return todoOk;
}

int buscarEmpleado(eEmpleado lista[], int tam, int legajo)///busqueda del legajo que me pasan por parametro en las estructuras que estan llenas
{
    int indice=-1;///si no lo encunetra devuelve -1 que es imposible como indice

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].legajo == legajo)//si no es 1, es decir si esta ocupado && si el indice es igual al legajo que me pasan
            {
                indice=i;///guardo en la variable indice le indice de la estructura que coincide
                break;///si no rompe me devuelve el indice de la ultima estructura vacia y yo necesito el primero.
            }
        }
    }

    return indice;

}


int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    int todoOk=0;
    int indice;//para guardar la ubicacion
    int legajo;
    char confirma;

    system("cls");
    printf("       Baja de empleados\n");

    mostrarEmpleados(lista, tam, sectores, tamS);

    printf("Ingrese legajo del empleado: ");
    scanf("%d", &legajo);

    indice=buscarEmpleado(lista, tam, legajo);

    if(indice==-1)
    {
        printf("No existe un empleado con el legajo %d", legajo);
    }
    else
    {
        mostrarEmpleado(lista[indice], sectores, tamS);

        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma=='s')
        {
            lista[indice].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }
    return todoOk;
}

int harcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo)///devuleve todos los empleados que se pudieron cargar correctamente
{
    int total = 0;//si no entra al for devuelve 0

    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pLegajo!=NULL)///recorrer el array
    {

        for(int i=0; i<cant; i++)
        {
            lista[i].legajo=*pLegajo;///valor de legajo en ese momento en main
            (*pLegajo)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo=sexos[i];
            lista[i].sueldo=sueldos[i];
            lista[i].edad=edades[i];
            lista[i].idSector=idSectores[i];
            lista[i].isEmpty=0;
            lista[i].fechaIngreso=fechas[i];
            total++;
        }
    }
    return total;
}



