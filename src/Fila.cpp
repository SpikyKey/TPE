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
// Coplejidad de la funci�n longitud T(n)
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

// complejidad de la funci�n agrFila T(1)
void Fila::agrFila (int elementonuevo){
    Nodo* aux;
    aux= new Nodo;
    aux-> siguiente = primerNodo->siguiente;
    aux-> elemento = primerNodo-> elemento;
    primerNodo->elemento = elementonuevo;
    primerNodo->siguiente =aux;

    return;

   }
// complejidad de la funci�n ultimo T(n)
int Fila::ultimo(){
        assert(!vacia());
        Nodo* cursor= primerNodo;
            while (cursor->siguiente!=NULL){
                cursor= cursor->siguiente;
            }
            return cursor->elemento;
    }
// complejidad de la funci�n retirar T(n) .
//Se podr�a optimizar guardando de alguna manera un puntero al �ltimo
//para no tener que recorrer toda la fila desde el principio.
// Una forma podr�a ser guardando en un arreglo paralelo a la Fila la direcci�n al anterior de cada nodo.
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
// complejidad de la funci�n vacia T(1)
bool Fila::vacia(){
    if (primerNodo==NULL)
        return true;
    else
        return false;
}
