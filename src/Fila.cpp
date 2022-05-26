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
   Nodo * aux = primerNodo;
   while (aux != NULL){
        contador++;
        aux = aux->siguiente;
   }
   return contador;
}


void Fila::agrlista(Nodo * nodo,int elementonuevo){
    aux-> siguiente = primerNodo->siguiente;
    aux-> elemento = primerNodo-> elemento;
    primerNodo->elemento = elementonuevo;
    segundo-> elemento = aux-> elemento;
    segundo-> siguiente = aux-> siguiente;
    primerNodo->siguiente = *segundo;
    return;

   }

void Fila::elemento=ultimo(F){
        *nodo cursor= primer elemento;
        if NOT vacia(F)
            if *cursor->siguiente=NULL
                return *cursor->elemento
        else *cursor->siguiente!=NULL
             cursor->siguiente=*siguiente->siguiente;

    }

void Fila::retirar(F){
         }
