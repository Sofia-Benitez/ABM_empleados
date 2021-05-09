
#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED



typedef struct
{
    int id;
    char descripcion[20];

}eSector;



#endif // SECTORES_H_INCLUDED

///sectores

void mostrarSectores(eSector sectores[], int tam);
void mostrarSector(eSector unSector);
int cargarDescripcionSector(int id, eSector sectores[], int tam, char descripcion[]);
