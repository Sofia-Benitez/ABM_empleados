#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "informes.h"
#include "sectores.h"
#include "comida.h"
#include "almuerzo.h"


#define TAM 14 /// empleados
#define TAM_SEC 5 ///sector
#define TAMC 5 /// comidas
#define TAMA 20 ///almuerzo
#define EDAD_DES 1//criterio 1: edad descendiente
#define NOMBRE_ASC 0//criterio 0:Nombre ascendente(A-Z)
#define SEX_DES_LEGAJO_ASC 2 //criterio 2:sexo descendente y legajo ascendente

int menu();

int main()
{
    char seguir = 's';
    int nextId=2000;//arranca de este valor
    int criterioOrdenamiento;
    int opcionInformes;

    int nextIdAlmuerzo=50000;

    eSector sectores[TAM_SEC]={
        {500, "Sistemas"},
        {501, "RRHH"},
        {502, "Cobranzas"},
        {503, "Legales"},
        {504, "Ventas"}
        };

    eComida comidas[TAMC]= {
        {1000, "Milanesa", 100},
        {1001, "Fideos", 50},
        {1002, "Pizza", 150},
        {1003, "Ensalada", 200},
        {1004, "Empanadas", 75}
        };


    eEmpleado nomina[TAM]; ///INICIALIZAR ESTRUCTURA SI NO HAY HARCODEO

    inicializarEmpleados(nomina, TAM);//setea todas las estructuras como disponibles

    harcodearEmpleados(nomina, TAM, 10, &nextId);

    eAlmuerzo almuerzos[TAMA];

    while(seguir=='s')
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(nomina, TAM, &nextId, sectores , TAM_SEC))
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta\n");
            }
            break;
        case 2:
            printf("sirve?");
            break;
        case 3:
            if(bajaEmpleado(nomina, TAM, sectores, TAM_SEC))
            {
                printf("Baja exitosa\n");
            }
            else
            {
                printf("Hubo un problema al dar de baja\n");
            }
            break;
        case 4:
            mostrarEmpleados(nomina, TAM, sectores, TAM_SEC);
            break;
        case 5:
                printf("\n****Ordenamiento de empleados****\n");
                printf("1. Edad descendiente\n");
                printf("2. Nombre ascendente\n");
                printf("3. Sexo descendente y legajo ascendente\n\n");
                printf("Elija un criterio para ordenar empleados: ");
                scanf("%d", &criterioOrdenamiento);

                switch(criterioOrdenamiento)
                {
                case 1:
                    if(ordenarEmpleados(nomina, TAM, EDAD_DES))
                    {
                        printf("Ordenamiento exitoso\n");
                    }
                    else
                    {
                        printf("ERROR. No es posible ordenar a los empleados");
                    }
                    break;
                case 2:
                    if(ordenarEmpleados(nomina, TAM, NOMBRE_ASC))
                    {
                        printf("Ordenamiento exitoso\n");
                    }
                    else
                    {
                        printf("ERROR. No es posible ordenar a los empleados");
                    }
                    break;
                case 3:
                    if(ordenarEmpleados(nomina, TAM, SEX_DES_LEGAJO_ASC))
                    {
                        printf("Ordenamiento exitoso\n");
                    }
                    else
                    {
                        printf("ERROR. No es posible ordenar a los empleados");
                    }
                    break;
                default:
                    printf("No existe ese criterio\n");
                    break;
                }

            break;
        case 6:
            mostrarSectores(sectores, TAM_SEC);
            break;
        case 7:
            ///submenu de informes
                printf("\n****Informes****\n");
                printf("1. Cantidad de empleados por sector\n");
                printf("2. Actualizacion de sueldos por sector\n");
                printf("3. Sueldos totales por sector y total \n");
                printf("Elija el informe que desea ver: ");
                scanf("%d", &opcionInformes);

                switch(opcionInformes)
                {
                    case 1:
                        empleadosSector(nomina, TAM, sectores, TAM_SEC);
                        break;
                    case 2:
                        actualizarSueldosPorSector(nomina, TAM, sectores, TAM_SEC);
                        break;
                    case 3:
                        sueldosTotalesPorSector(nomina, TAM, sectores, TAM_SEC);
                        break;
                }

            break;
        case 8:
            //comidas
            mostrarComidas(comidas, TAMC);
            break;
        case 9:
            printf("Alta almuerzo: \n");
            break;
        case 20:
            seguir='n';
            //salir, desea salir?
            break;
        }

        printf("Desea seleccionar otra opcion?: ");
        fflush(stdin);
        scanf("%c", &seguir);

        system("pause");

    };

    return 0;
}



int menu()
{
    int opcion;

    system("cls");

    printf("Gestion de empleados\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Listar empleados\n");
    printf("5. Ordenar empleados\n");
    printf("6. Mostrar sectores\n");
    printf("7. Informes\n");
    printf("8. Mostrar comidas\n");
    printf("9. Alta almuerzo\n");
    printf("10. Mostrar almuerzos\n");
    printf("11. -------\n");
    printf("20. Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}






