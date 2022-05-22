#include "../include/Lista.h"
#include <stdlib.h>
#include <assert.h>


Lista::Lista()
{
    primerNodo = NULL;
}

Lista::~Lista()
{
    //dtor
}

unsigned int Lista::longitud(){
    if (primerNodo == NULL)
        return 0;

    unsigned int contador = 0;
    Nodo * aux = primerNodo;
    while(aux != NULL){
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}

void Lista::agregarRecursivo(Nodo* nodo, unsigned int posicion, unsigned int lugar, int elemento){
    if (posicion == lugar - 1){
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = nodo->siguiente;
        nodo->siguiente = nuevoNodo;
        return;
    }

    agregarRecursivo(nodo->siguiente, posicion+1, lugar, elemento);

}

void Lista::agregar(unsigned int lugar, int elemento){
    assert(lugar <= 1 + longitud() && lugar > 0);

    agregarRecursivo(primerNodo, 1, lugar, elemento);





/*
    unsigned int indice = 0;
    Nodo * aux = primerNodo;
    Nodo * sigAux = aux->siguiente;

    if (posicion == 0){
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = primerNodo;
    }
    while(sigAux != NULL){
        indice++
        if (indice )

    }
    if (indice == 1 + longitud()){
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = NULL;

    }*/
}


