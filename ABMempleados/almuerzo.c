#include "almuerzo.h"

int inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam)
{

    int todoOk=0;
    if(almuerzos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)//recorro el array para inicializar
        {
            almuerzos[i].isEmpty= 1;
        }
        todoOk=1;
    }


    return todoOk;
}

int buscarLibreAlmuerzos(eAlmuerzo almuerzos[], int tam)///devuelve el indice del primer almuerzo libre
{
    int indice=-1;

    if(almuerzos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(almuerzos[i].isEmpty)//si es 1
            {
                indice=i;
                break;///si no rompe me devuelve el indice de la ultima estructura vacia y yo necesito el primero.
            }
        }

    }

    return indice;
}



int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, eEmpleado lista[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC, int* pIdAlmuerzo);///se fija si hay lugar, muestra los empleados y pide legajo, muestra las comidas y pide ID de comida, pide la fecha e inserta el almuerazo en el indice del array que da buscarLibre()
{
    int todoOk=0;
    int indice;
    int legajo;
    int idComida;


    eAlmuerzo nuevoAlmuerzo;  ///auxiliar


    if(almuerzos!=NULL && tamA>0 && pIdAlmuerzo!=NULL)
    {
        system("cls");
        printf("Alta almuerzo\n\n");
        printf("ID almuerzo: %d\n", *pIdAlmuerzo);
        indice=buscarLibreAlmuerzos(almuerzos, tamA);
        if(indice==-1)
        {
            printf("No hay lugar para mas almuerzos\n");
        }
        else
        {

            nuevoAlmuerzo.id= *pIdAlmuerzo; ///traigo el id

            mostrarEmpleados(lista, tamE, sectores, tamS);

            printf("Ingrese legajo empleado: ");
            scanf("%d", &legajo);

            while(buscarEmpleado(lista, tamE, legajo)==-1)
            {
                printf("No es un empleado valido. Reingrese legajo: ");
                scanf("%d", &legajo);
            }

            nuevoAlmuerzo.legajoEmpleado = legajo;

            mostrarComidas(comidas, tamC);

            printf("Ingrese ID comida: ");
            scanf("%d", &idComida);

            while(buscarComida(comidas, tamC, id)==-1)
            {
                printf("No es una comida valida. Reingrese id: ");
                scanf("%d", &idComida);
            }

            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);

            mostrarSectores(sectores, tamSec);
            printf("Ingrese el sector: ");
            scanf("%d", &nuevoEmpleado.idSector);

            nuevoAlmuerzo.isEmpty=0;///ahora es una estructura cargada

            almuerzos[indice]=nuevoAlmuerzo;///copio el contenido al array

            ///actualizo el proximo id
            *pIdAlmuerzo=(*pIdAlmuerzo)+1;   ///referencia al nextId del main e incrementacion


             todoOk=1;
        }

    }

    return todoOk;
}



int mostrarAlmuerzo(eAlmuerzo unAlmuerzo)
{
    printf("  %d   %d   %d   %02d/%02d/%02d\n", unAlmuerzo.id,
           unAlmuerzo.legajoEmpleado,
           unAlmuerzo.idComida,
           unAlmuerzo.fecha.dia,
           unAlmuerzo.fecha.mes,
           unAlmuerzo.fecha.anio);
}

int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tam)//id comida, empleado, fecha, si quiero con nombre tiene que se parecida a cargarDescripcionSector
{
    int flag=1;
    printf("\n                      ******Lista almuerzos******\n");
    printf("ID       Legajo empleado          ID comida           Fecha      \n");

    for(int i=0; i<tam; i++)
    {
       if(almuerzos[i].isEmpty==0)///muestra los que estan en el indice que estan ocupados
       {
            mostrarAlmuerzo(almuerzos[i]);//llamo a la funcion que muestra un almuerzo
            flag=0;
       }
    }
   if(flag)
   {
       printf("No hay almuerzos en la lista");
   }
   printf("\n\n");
}



