#include "../include/Lista.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <string>
template <typename T>
Lista<T>::Lista()
{
    primerNodo = NULL;
    ultimoNodo = NULL;
    contador = 0;
}

template <typename T>
Lista<T>::~Lista()
{
    if (primerNodo == NULL)
        return;

    Nodo * aux = primerNodo;
    Nodo * aBorrar = NULL;
    while (aux->siguiente != NULL){
        aBorrar = aux;
        aux = aux->siguiente;
        delete aBorrar;
    }
    delete aux;
}

template <typename T>
unsigned int Lista<T>::longitud(){
    return contador;
}

template <typename T>
void Lista<T>::agregarRecursivo(Nodo*& nodo, unsigned int posicion, T elemento){
    if (posicion == 1){
        Nodo * nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = nodo;

        if (nodo == NULL){
            ultimoNodo = nuevoNodo;
        }
        contador++;
        nodo = nuevoNodo;
        return;
    }
    agregarRecursivo(nodo->siguiente, posicion -1, elemento);
}

template <typename T>
void Lista<T>::agregar(unsigned int posicion, T elemento){
    assert(posicion <= 1 + longitud() && posicion > 0);
    agregarRecursivo(primerNodo, posicion, elemento);
}

template <typename T>
bool Lista<T>::vacia(){
    return longitud() == 0;
}

template <typename T>
T Lista<T>::recuperar(unsigned int posicion){
    assert(0 < posicion && posicion <= longitud());
    //como el indice esta en rango los punteros a continuacion no deberian ser nulos

    Nodo* aux = primerNodo;
    unsigned int i = 1;
    while (i != posicion){
        i++;
        aux = aux->siguiente;
    }
    return aux->elemento;
}

template <typename T>
bool Lista<T>::eliminarRecursivo(Nodo* & nodo, unsigned int posicion){
    if (nodo == NULL)
        return false;

    if (posicion == 1){
        Nodo* aux = nodo->siguiente;
        delete nodo;
        nodo = aux;
        contador--;
        return true;
    }

    if (nodo->siguiente == ultimoNodo){
        ultimoNodo = nodo;
    }
    return eliminarRecursivo(nodo->siguiente, posicion - 1);
}

template <typename T>
bool Lista<T>::eliminar(unsigned int posicion){

        return eliminarRecursivo(primerNodo, posicion);
}

template <typename T>
void Lista<T>::agregarFin(T elemento){
    if (vacia() == true){
        agregarPrincipio(elemento);
        return;
    }
    agregarRecursivo(ultimoNodo->siguiente, 1, elemento);
    //agregar(longitud()+1, elemento);
}

template <typename T>
void Lista<T>::agregarPrincipio(T elemento){
    agregar(1, elemento);
}

template class Lista<int>;


