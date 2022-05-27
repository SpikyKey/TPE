#include "../include/Fila.h"
#include <cstddef>
#include <assert.h>
#include <stdlib.h>

Fila::Fila()
{
    primerNodo = NULL;
}

Fila::~Fila()
{
    //dtor
}

unsigned int Fila::longitud(){
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


void Fila::agrFila (int elementonuevo){
    Nodo* aux;
    aux= new Nodo;
    aux-> siguiente = primerNodo->siguiente;
    aux-> elemento = primerNodo-> elemento;
    primerNodo->elemento = elementonuevo;
    primerNodo->siguiente =aux;

    return;

   }

int Fila::ultimo(){
        assert(!vacia());
        Nodo* cursor= primerNodo;
            while (cursor->siguiente!=NULL){
                cursor= cursor->siguiente;
            }
            return cursor->elemento;
    }

int Fila::retirar(){
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

bool Fila::vacia(){
    if (primerNodo==NULL)
        return true;
    else
        return false;
}
