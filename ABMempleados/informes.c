#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "informes.h"
#include "empleado.h"
#include "sectores.h"


///informes

int empleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    //mostrar sector, pedir sector y contar la cantidad de empleados que pertenecen a ese sector
    int idSector;
    int contador=0;
    int todoOk=0;
    char descripcion[20];


    if(lista!=NULL && sectores!=NULL && tam>0 && tamS>0)
    {
        printf("    Informes de empleados por sector      \n");
        mostrarSectores(sectores, tamS);

        printf("Ingrese el sector: ");
        scanf("%d", &idSector);
        cargarDescripcionSector(idSector, sectores, tamS, descripcion);
        for(int i=0; i<tam; i++)
        {
            if(lista[i].idSector==idSector && !lista[i].isEmpty)//busca la coincidencia del id con el id seleccionado cuando esta ocupado el espacio
            {
                contador++;
            }
        }

        if(contador==0)
        {
            printf("No hay empleados en el sector %s\n", descripcion);
        }
        else
        {
            printf("Cantidad de empleados en %s: %d\n", descripcion, contador);
        }

        todoOk=1;
    }

    return todoOk;

}

int actualizarSueldosPorSector(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    //mostrar sector
    //pedir sector
    //pedir porcentaje de aumento
    //incrementar el sueldo

    int todoOk=0;
    int idSector;
    char descripcion[20];
    int porcentaje;
    float sueldo;
    float nuevoSueldo;

    if(lista!=NULL && sectores!=NULL && tam>0 && tamS>0)
    {
        printf("    Actualizar sueldo por sector      \n");
        mostrarSectores(sectores, tamS);

        printf("Ingrese el sector: ");
        scanf("%d", &idSector);
        cargarDescripcionSector(idSector, sectores, tamS, descripcion);
        printf("Ingrese el porcentaje a aumentar: ");
        scanf("%d", &porcentaje);

        for(int i=0; i<tam; i++)
        {
            if(lista[i].idSector==idSector && !lista[i].isEmpty)//busca la coincidencia del id con el id seleccionado cuando esta ocupado el espacio
            {
                sueldo=lista[i].sueldo;
                nuevoSueldo= sueldo + sueldo * porcentaje /100;
                lista[i].sueldo= nuevoSueldo;
            }
        }

        printf("Se han actualizado los sueldos del sector %s\n", descripcion);
        todoOk=1;
    }

    return todoOk;
}


int sueldosTotalesPorSector(eEmpleado lista[], int tam, eSector sectores[], int tamS)///se fija los sueldos totales de cada sector y los muestra y muestra el total de sueldos
{
    int todoOk=0;
    float totalSector;
    float totalTotal=0;

    if(lista!=NULL && sectores!=NULL && tam>0 && tamS>0)
    {
        printf(" Informes sueldos por sector y total sueldos\n");

        for(int i=0; i<tamS; i++)//recorro el vector de sectores
        {
            printf("Sector: %s", sectores[i].descripcion);//cada vez que arranco un sector nuevo muestro el encabezado
            totalSector=0;//reseteo el acumulador de los sueldos
            for(int j=0; j<tam; j++)//recorro el vec de empleados
            {
                if(lista[j].isEmpty==0 && lista[j].idSector==sectores[i].id)///busco empleados activos y que el sector dle empleado coincida con el sector del for anterior
                totalSector+=lista[j].sueldo;//acumulo el sueldo
            }//barro todos los empleados del sector

            printf("Total $%.2f\n", totalSector);
            totalTotal+=totalSector;//acumulo el total total antes de la siguiente iteracion
        }


        printf("Total de sueldos de la empresa: $%.2f\n", totalTotal);
        todoOk=1;
    }

    return todoOk;
}
