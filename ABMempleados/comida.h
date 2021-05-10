#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
}eComida;


#endif // COMIDA_H_INCLUDED


int mostrarComidas(eComida comidas[], int tam);

int mostrarComida(eComida unaComida);

int buscarComida(eComida comidas[],int tam, int id);
