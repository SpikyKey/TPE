#include <iostream>
#include "../include/Fila.h"
#include "../include/Lista.h"
#include "../include/ArbolBinario.h"
#include "../include/Tests.h"
#include <assert.h>
#include <iostream>

unsigned int nuevaListaZeroElementos(){
    Lista<int> * nueva = new Lista<int>;
    return nueva->longitud();
}
bool listaNoVaciaTieneElementos(){
    Lista<int> * nueva = new Lista<int>;
    nueva->agregar(1, 22);
    return nueva->longitud() != 0;
}

unsigned int listaContieneTresElementos(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregar(1, 22);
    nueva->agregar(2, 33);
    nueva->agregar(2,44);
    return nueva->longitud();
}

void fallaAlAgregarEnPosicionCero(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregar(0,-21);
}

void fallaAlAgregarIndiceMayorLongitud(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregar(1, 31);
    nueva->agregar(2, -31);
    nueva->agregar(2, 222);
    nueva->agregar(3, -42);
    nueva->agregar(6, 111);
}

bool listaVaciaEsVacia(){
    Lista<int>* nueva = new Lista<int>;
    return nueva->vacia();
}

bool listaNoVaciaEsVacia(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregar(1, 234);
    return nueva->vacia();
}

bool recuperaAgregadoAnterior(){
    Lista<int>*nueva = new Lista<int>;
    nueva->agregar(1, -31);
    nueva->agregar(2, 32);
    nueva->agregar(3, 22);
    nueva->agregar(4, 11);
    nueva->agregar(5, -19);
    nueva->agregar(3, -1000);
    return nueva->recuperar(3) == -1000;
}

bool recuperaEnOrden(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregar(1, 111);
    nueva->agregar(1, -222);
    nueva->agregar(1, -333);
    nueva->agregar(1, 444);
    return (nueva->recuperar(1) == 444 &&
            nueva->recuperar(2) == -333 &&
            nueva->recuperar(3) == -222 &&
            nueva->recuperar(4) == 111);
}

bool eliminarDeVaciaEsFalse(){
    Lista<int>* nueva = new Lista<int>;
    return !nueva->eliminar(1);
}

bool eliminarConteniendoUnElementoResultaEnVacia(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregar(1, -111);
    nueva->eliminar(1);
    return nueva->vacia();
}

bool eliminarDecrementaLongitud(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregar(1, -223);
    nueva->agregar(2, -112);
    nueva->agregar(3, -1);
    nueva->agregar(4, 110);
    nueva->eliminar(2);
    return nueva->longitud() == 3;
}

bool agregarFinAgregarAlFinal(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregarFin(356);
    nueva->agregarFin(2213);
    nueva->agregarFin(-481);
    return nueva->recuperar(3) == -481;
}

bool agregarPrincipioAgregaInicio(){
    Lista<int>* nueva = new Lista<int>;
    nueva->agregarPrincipio(111);
    nueva->agregarPrincipio(222);
    nueva->agregarPrincipio(-333);
    return (nueva->recuperar(3) == 111 &&
            nueva->recuperar(2) == 222 &&
            nueva->recuperar(1) == -333);
}

void testsLista(){
    std::cout << "Comienzan los tests de Lista\n";

    assert(nuevaListaZeroElementos() == 0);
    assert(listaNoVaciaTieneElementos() == true);
    assert(listaContieneTresElementos() == 3);
    //fallaAlAgregarEnPosicionCero();
    //fallaAlAgregarIndiceMayorLongitud();

    assert(listaVaciaEsVacia() == true);
    assert(listaNoVaciaEsVacia() == false);

    assert(recuperaAgregadoAnterior() == true);
    assert(recuperaEnOrden() == true);

    assert(eliminarDeVaciaEsFalse() == true);
    assert(eliminarConteniendoUnElementoResultaEnVacia() == true);
    assert(eliminarDecrementaLongitud() == true);

    assert(agregarFinAgregarAlFinal() == true);
    assert(agregarPrincipioAgregaInicio() == true);

    std::cout << "La Lista paso los tests! \n";
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
