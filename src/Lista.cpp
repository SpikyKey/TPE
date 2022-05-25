#include "../include/Lista.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>


Lista::Lista()
{
    primerNodo = NULL;
}

Lista::~Lista()
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

Nodo* Lista::agregarRecursivo(Nodo* nodo, unsigned int posicion, t_elem elemento){
    if (posicion == 1){
        Nodo * nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = nodo;
        return nuevoNodo;
    }
    nodo->siguiente = agregarRecursivo(nodo->siguiente, posicion -1, elemento);
    return nodo;

}

void Lista::agregar(unsigned int posicion, t_elem elemento){
    assert(posicion <= 1 + longitud() && posicion > 0);
    primerNodo = agregarRecursivo(primerNodo, posicion, elemento);
}

bool Lista::vacia(){
    return longitud() == 0;
}

int Lista::recuperar(unsigned int posicion){
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

bool Lista::eliminarRecursivo(Nodo* & nodo, t_elem elemento){
    if (nodo == NULL)
        return false;

    if (nodo->elemento == elemento){
        Nodo* aux = nodo->siguiente;
        delete nodo;
        nodo = aux;
        return true;
    }

    return eliminarRecursivo(nodo->siguiente, elemento);
}

bool Lista::eliminar(t_elem elemento){
    return eliminarRecursivo(primerNodo, elemento);

}

void Lista::agregarFin(t_elem elemento){
    //agregar(longitud()+1, elemento);
}


