#include "../include/Banco.h"

using namespace std;
Banco::Banco()
{
    colaGeneral = new Fila<Cliente*>;
    colasEspeciales = new Lista<ColaEspecial>;
    historial = new Lista<Cliente*>;
}


// Si bien en este programa solo se llama al destructor de Banco al salir del main
// (lo cual hace redundante esta limpieza de memoria) lo agregamos por completitud.
Banco::~Banco()
{
    while (!colaGeneral->vacia()){
        delete colaGeneral->retirar();
    }
    delete colaGeneral;

    while (!historial->vacia()){
        delete historial->recuperar(1);
        historial->eliminar(1);
    }
    delete historial;

    for (int i = 1; i <= colasEspeciales->longitud(); i++){
        Fila<Cliente*>* cola = colasEspeciales->recuperar(i).cola;
        while (!cola->vacia()){
            delete cola->retirar();
        }
        delete cola;
    }
    delete colasEspeciales;
}



void Banco::ingresaCliente(Cliente* nuevoCliente)
{
    bool cumpleCriterio = false;

    for (int i = 1; i <= colasEspeciales->longitud() && !cumpleCriterio; i++){
        ColaEspecial colaEsp = colasEspeciales->recuperar(i);

        if (colaEsp.operacion == nuevoCliente->getOperacion() &&
            colaEsp.esCliente == nuevoCliente->getEsCliente()){
                colaEsp.cola->agregar(nuevoCliente);
                cumpleCriterio = true;
            }
    }

    if (!cumpleCriterio)
        colaGeneral->agregar(nuevoCliente);
}

Cliente* Banco::atender(){
    Cliente* cliente = NULL;
    if (!colaGeneral->vacia()){
        cliente = colaGeneral->retirar();
        historial->agregarPrincipio(cliente);
    }

    return cliente;
}
Cliente* Banco::atender(TipoOperacion operacion, bool esCliente){
    Cliente* cliente = NULL;
    for (int i = 1; i <= colasEspeciales->longitud(); i++){
        ColaEspecial colaEsp = colasEspeciales->recuperar(i);
        if (colaEsp.operacion == operacion &&
            colaEsp.esCliente == esCliente){
                if (!colaEsp.cola->vacia()){
                    cliente = colaEsp.cola->retirar();
                    historial->agregarPrincipio(cliente);
                }

        }
    }
    return cliente;
}

void Banco::abrirColaConCriterio(TipoOperacion op, bool esCliente){
    if (colasEspeciales->longitud() == MAXIMAS_ESP){
        return;
    }

    bool duplicada = false;
    for (int i = 1; i <= colasEspeciales->longitud(); i++){
        ColaEspecial colaEsp = colasEspeciales->recuperar(i);
        if (colaEsp.operacion == op && colaEsp.esCliente == esCliente)
            duplicada = true;
    }

    if (!duplicada){
        ColaEspecial nuevaCola;
        nuevaCola.esCliente = esCliente;
        nuevaCola.operacion = op;
        nuevaCola.cola = new Fila<Cliente*>;

        Fila<Cliente*>* auxGeneral = new Fila<Cliente*>;

        Cliente* cliente;
        while (!colaGeneral->vacia()){
            cliente = colaGeneral->retirar();
            if (cliente->getOperacion()== op && cliente->getEsCliente() == esCliente){
                nuevaCola.cola->agregar(cliente);
            }else{
                auxGeneral->agregar(cliente);
            }
        }
        delete colaGeneral; // innecesario?
        colaGeneral = auxGeneral;
        colasEspeciales->agregarPrincipio(nuevaCola);
    }


}

bool Banco::cerrarColaConCriterio(TipoOperacion op, bool esCliente){
    bool fueCerrada = false;

    if (!colasEspeciales->vacia()){
        for (int i = 1; i <= colasEspeciales->longitud() && !fueCerrada; i++){
            ColaEspecial colaEsp = colasEspeciales->recuperar(i);
            if (colaEsp.operacion == op && colaEsp.esCliente == esCliente &&
                colaEsp.cola->vacia())
            {
                delete colaEsp.cola;
                colasEspeciales->eliminar(i);
                fueCerrada = true;
            }
        }
    }
    return fueCerrada;
}


void Banco::listarOperaciones(unsigned int minimo, unsigned int maximo){
    unsigned int monto;
    Cliente* cliente;
    unsigned int contador = 0;
    unsigned int suma = 0;

    cout << "Los clientes que realizaron operaciones entre " << minimo << " y " << maximo << " :" << endl;
    for (int i = 1; i <= historial->longitud(); i++){
        cliente = historial->recuperar(i);
        monto = cliente->getMonto();
        if (minimo <= monto && monto <= maximo){
            contador++;
            suma += cliente->getEdad();
            cout << endl;
            cliente->imprimir();
        }
    }

    if (contador != 0)
        cout << "Estos clientes tienen una edad promedio de: " << suma/contador << endl;
}

unsigned int Banco::colasAbiertas(){
    unsigned int abiertas = 1; //Siempre esta abierta la cola general
    return abiertas + colasEspeciales->longitud();
}

bool Banco::existeColaConCriterio(TipoOperacion op, bool esCliente){
    bool existe = false;

    for (int i = 1; i <= colasEspeciales->longitud(); i++){
        ColaEspecial colaEsp = colasEspeciales->recuperar(i);
        if (colaEsp.operacion == op && colaEsp.esCliente == esCliente)
            existe = true;
    }
    return existe;
}

