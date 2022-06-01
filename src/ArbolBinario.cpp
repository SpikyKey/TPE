#include "../include/ArbolBinario.h"
#include "../include/Lista.h"
#include <stdlib.h>
#include <assert.h>
#include <iostream>

template <typename T>
Arbin<T>::Arbin()
{
    raiz = NULL;
}

// complejidad de la función cargarRecursivo T(ln n)
template <typename T>
void Arbin<T>::cargarRecursivo(NodoArbin*& raiz, T elemento){
    if (raiz == NULL){
        NodoArbin* nuevo = new NodoArbin;
        nuevo->campo = elemento;
        nuevo->hijoizq = NULL;
        nuevo->hijoder = NULL;
        raiz = nuevo;
        return;
    }
    if (elemento < raiz->elemento){
        raiz->hijoizq = cargarRecursivo(raiz->hijoizq, elemento);
    } else {
        raiz->hijoder = cargarRecursivo(raiz->hijoder, elemento);
    }
    return;
}

// complejidad de la función cargar T(ln n)
template <typename T>
void Arbin<T>::cargar(T elemento){
    raiz = cargarRecursivo(raiz, elemento);
}

// complejidad de la función perteneceRecursiva T(ln n)
template <typename T>
bool Arbin<T>::perteneceRecursiva(NodoArbin* raiz, T elemento){
    if (raiz == NULL)
        return false;

    if (elemento == raiz->campo)
        return true;

    if (elemento < raiz->campo)
        return perteneceRecursiva(raiz->hijoizq, elemento);
    return perteneceRecursiva(raiz->hijoder, elemento);
}

// complejidad de la función pertenece T(ln n)
template <typename T>
bool Arbin<T>::pertenece(T elemento){
    return perteneceRecursiva(raiz, elemento);
}

// complejidad de la función vacio T(1)
template <typename T>
bool Arbin<T>::vacio(){
    return raiz == NULL;
 }

 // complejidad de la función contarRecursivo T(n)
 template <typename T>
 unsigned int Arbin<T>::contarRecursivo(NodoArbin* raiz){
    if (raiz == NULL)
        return 0;
    return 1 + contarRecursivo(raiz->hijoizq) +
               contarRecursivo(raiz->hijoder);
 }

 // complejidad de la función cantelementos T(n)
 template <typename T>
 unsigned int  Arbin<T>::cantelmentos(){
    return contarRecursivo(raiz);
 }


 // complejidad de la función profundidadRecursiva T(n)
template <typename T>
unsigned int Arbin<T>::profundidadRecursiva(NodoArbin* raiz){
    if (raiz == NULL)
        return 0;

    unsigned int profundidadIzq;
    unsigned int profundidadDer;
    unsigned int mayor;
    profundidadIzq = profundidadRecursiva(raiz->hijoizq);
    profundidadDer = profundidadRecursiva(raiz->hijoder);
    if (profundidadIzq < profundidadDer)
        mayor = profundidadDer;
    else
        mayor = profundidadIzq;
    return mayor + 1;
}


// complejidad de la función profundidad T(n)
template <typename T>
unsigned int Arbin<T>::profundidad (){
    return profundidadRecursiva(raiz);
}

// complejidad de la función listarFronteraRecursiva T(n)
template <typename T>
Lista Arbin<T>::listarFronteraRecursiva(NodoArbin* raiz, Lista frontera){
    if (raiz->hijoder == NULL &&
        raiz->hijoizq == NULL){
        frontera.agregarPrincipio(raiz->campo);
        return frontera;
    }

    if (raiz->hijoizq != NULL)
        frontera = listarFronteraRecursiva(raiz->hijoizq, frontera);
    if (raiz->hijoder != NULL)
        frontera = listarFronteraRecursiva(raiz->hijoder, frontera);
    return frontera;
}
template <typename T>
Lista Arbin<T>::listarFrontera (){
    Lista frontera = new Lista;
    return listarFronteraRecursiva(raiz, frontera);
 }


 // Lista los nodos del arbol en preorder
 // complejidad de la función listaRacursivo T(n^2)
 // se puede mejorar arreglando el agregarFin de la lista con un arreglo paralelo con se indicó.
 template <typename T>
void Arbin<T>::listarRecursivo(NodoArbin* raiz, Lista& lista){
    if (raiz == NULL)
        return;

    lista.agregarFin(raiz->campo);
    listarRecursivo(raiz->hijoizq, lista);
    listarRecursivo(raiz->hijoder, lista);
}

// complejidad de la función listarArbin T(n^2)
template <typename T>
Lista Arbin<T>::listarArbin(){
    Lista listado = new Lista;
    listarRecursivo(raiz, listado);
    return listado;
}

// complejidad de la función destructorRecursivo T(n)
template <typename T>
void Arbin<T>::destructorRecursivo(NodoArbin* raiz){
    if (raiz == NULL){
        return;
    }
    destructorRecursivo(raiz->hijoizq);
    destructorRecursivo(raiz->hijoder);
    delete raiz;
}
template <typename T>
Arbin<T>::~Arbin()
{
    destructorRecursivo(raiz);
    raiz = NULL;
}
