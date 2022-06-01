#include "../include/Fila.h"
#include <cstddef>
#include <assert.h>
#include <stdlib.h>

template <typename T>
Fila<T>::Fila()
{
    primerNodo = NULL;
}

template <typename T>
Fila<T>::~Fila()
{
    Nodo* aBorrar = NULL;
    Nodo* cursor = primerNodo;

    while (cursor->siguiente != NULL){
        aBorrar = cursor;
        cursor = cursor->siguiente;
        delete aBorrar;
    }
    delete cursor;
}

template <typename T>
unsigned int Fila<T>::longitud(){
   if (primerNodo == NULL)
       return 0;

   unsigned int contador = 0;
   Nodo* aux = primerNodo;
   while (aux != NULL){
        contador++;
        aux = aux->siguiente;
   }
   return contador;
}

template <typename T>
void Fila<T>::agregar(T elementonuevo){
    Nodo* aux;
    aux= new Nodo;
    aux-> siguiente = primerNodo->siguiente;
    aux-> elemento = primerNodo-> elemento;
    primerNodo->elemento = elementonuevo;
    primerNodo->siguiente =aux;

    return;

   }

template <typename T>
T Fila<T>::primero(){
    assert(!vacia());
    Nodo* cursor= primerNodo;
    while (cursor->siguiente!=NULL){
        cursor= cursor->siguiente;
    }
    return cursor->elemento;
}

template <typename T>
T Fila<T>::retirar(){
    assert(!vacia());
    Nodo* cursor= primerNodo;
    Nodo* anteriorcursor;
    while (cursor->siguiente!=NULL){
        anteriorcursor=cursor;
        cursor= cursor->siguiente;
    }
    anteriorcursor->siguiente=NULL;
    int copia=cursor->elemento;
    delete cursor;
    return copia;
}

template <typename T>
bool Fila<T>::vacia(){
    return primerNodo == NULL;
}
