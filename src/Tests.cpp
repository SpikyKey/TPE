#include <iostream>
#include "Fila.h"
#include "Lista.h"
#include "ArbolBinario.h"
#include "Tests.h"



void testsFila(){
    //ejemplo
    assert(nuevaFilaEsVacia() == true);






}


static bool nuevaFilaEsVacia(){
    Fila nueva = new Fila;

    return nueva.esVacia();
}
