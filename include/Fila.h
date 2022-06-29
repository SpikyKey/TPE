#ifndef FILA_H
#define FILA_H
#include "Lista.h"
#include <cstddef>
#include <assert.h>
#include <stdlib.h>


template <typename T>
class Fila
{
    public:
        Fila();
        virtual ~Fila();
        // primero consulta el valor del proximo elemento a retirar pero sin cambiar la Fila
        T primero();
        bool vacia();
        void agregar(T elemento);
        unsigned int longitud();
        //retirar retorna el primer elemento de la fila y lo elimina de la Fila
        T retirar();


    private:
        Lista<T>* lista;

 };


 // ---------------IMPLEMENTACION--------------------


/*Esta implementacion estaba en Fila.cpp pero para poder definir por ejemplo
  Fila<Cliente*> sin llenar de encabezados ajenos a Filaa.cpp debimos moverla aqui.
*/


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


#endif // FILA_H
