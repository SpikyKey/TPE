#include "Banco.h"

Banco::Banco()
{
    colaGeneral = new Fila<Cliente>;
    colasEspeciales = new Lista<colaEspecial>;
    historial = new Lista<Cliente>;
}

Banco::~Banco()
{
    delete colaGeneral;
    delete historial;
    for (int i = 1; i <= colasEspeciales->longitud(); i++){
        delete colasEspeciales->recuperar(i);
    }
    delete colasEspeciales;
}
