#include <iostream>
#include "../include/Fila.h"
#include "../include/Lista.h"
#include "../include/ArbolBinario.h"
#include "../include/Tests.h"
#include <assert.h>

unsigned int nuevaListaZeroElementos(){
    Lista * nueva = new Lista;
    return nueva->longitud();
}
bool listaNoVaciaTieneElementos(){
    Lista * nueva = new Lista;
    nueva->agregar(1, 22);
    nueva->agregar(2, 33);
    return nueva->longitud() != 0;
}

void testsLista(){
    assert(nuevaListaZeroElementos() == 0);
    assert(listaNoVaciaTieneElementos() == true);

}



/*
void testsFila(){
    //ejemplo
    assert(nuevaFilaEsVacia() == true);






}


static bool nuevaFilaEsVacia(){
    Fila nueva = new Fila;

    return nueva.esVacia();
}
*/
