#include <iostream>
#include "../include/Fila.h"
#include "../include/Lista.h"
#include "../include/ArbolBinario.h"
#include "../include/Tests.h"



void testsFila(){
    //ejemplo
    assert(nuevaFilaEsVacia() == true);






}


static bool nuevaFilaEsVacia(){
    Fila nueva = new Fila;

    return nueva.esVacia();
}
