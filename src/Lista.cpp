#include "../include/Lista.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>


Lista::Lista()
{
    primerNodo = NULL;
}
// complejidad de la función borrar T(1)
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
// complejidad de la función longitud T(n)
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
// complejidad de la función agregarrecursivo T(n)
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
// complejidad de la función agregar T(n)
void Lista::agregar(unsigned int posicion, t_elem elemento){
    assert(posicion <= 1 + longitud() && posicion > 0);
    primerNodo = agregarRecursivo(primerNodo, posicion, elemento);
}
// complejidad de la función vacia T(1)
bool Lista::vacia(){
    return longitud() == 0;
}

// complejidad de la función recuperar T(n)
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

// complejidad de la función eliminarRecursivo T(n)
bool Lista::eliminarRecursivo(Nodo* & nodo, unsigned int posicion){
    if (nodo == NULL)
        return false;

    if (posicion == 1){
        Nodo* aux = nodo->siguiente;
        delete nodo;
        nodo = aux;
        return true;
    }

    return eliminarRecursivo(nodo->siguiente, posicion - 1);
}

bool Lista::eliminar(unsigned int posicion){
        return eliminarRecursivo(primerNodo, posicion);
}

// complejidad de la función agregarFin T(n)
void Lista::agregarFin(t_elem elemento){
    agregar(longitud()+1, elemento);
}
// complejidad de la función agregarPrincipio T(1)
void Lista::agregarPrincipio(t_elem elemento){
    Nodo* nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->siguiente = primerNodo;
    primerNodo = nuevo;
}


