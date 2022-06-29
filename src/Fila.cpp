
/* IMPLEMENTACION EN EL .H
#include "../include/Fila.h"
#include <cstddef>
#include <assert.h>
#include <stdlib.h>

template <typename T>
Fila<T>::Fila()
{
    lista = new Lista<T>;
}

template <typename T>
Fila<T>::~Fila()
{
    delete lista;
}

template <typename T>
unsigned int Fila<T>::longitud(){
    return lista->longitud();
}

template <typename T>
void Fila<T>::agregar(T elementoNuevo){
    lista->agregarPrincipio(elementoNuevo);
}

template <typename T>
T Fila<T>::primero(){
    assert(!vacia());
    return lista->recuperar(lista->longitud());
}

template <typename T>
T Fila<T>::retirar(){
    assert(!vacia());
    T copia = primero();
    lista->eliminar(lista->longitud());
    return copia;
}

template <typename T>
bool Fila<T>::vacia(){
    return lista->vacia();
}


*/
