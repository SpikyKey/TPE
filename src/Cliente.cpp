#include "../include/Cliente.h"


using namespace std;
Cliente::Cliente(string nombre, unsigned int edad, TipoOperacion operacion,
                TipoDestinatario destinatario, unsigned int monto, bool esCliente)
{
    this->nombre = nombre;
    this->edad = edad;
    this->operacion = operacion;
    this->destinatario = destinatario;
    this->monto = monto;
    this->esCliente = esCliente;
}

Cliente::~Cliente()
{
    //delete string;
}

TipoOperacion Cliente::getOperacion(){
    return operacion;
}

bool Cliente::getEsCliente(){
    return esCliente;
}

unsigned int Cliente::getMonto(){
    return monto;
}

unsigned int Cliente::getEdad(){
    return edad;
}

void Cliente::imprimir(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Operacion: " << operacionAString(operacion) << endl;
    cout << "Destinatario: " << destinatarioAString(destinatario) << endl;
    cout << "Monto: " << monto << " Pesos" << endl;
    if (esCliente){
        cout << "Cliente: Si" << endl;
    }else{
        cout << "Cliente: No" << endl;
    }
}


// funciones auxiliares de impresion
std::string operacionAString(TipoOperacion op){
    switch (op){
    case RETIRO:
        return "Retiro";
    case DEPOSITO:
        return "Deposito";
    case TRANSFERENCIA:
        return "Transferencia";
    case PAGO:
        return "Pago";
    default:
        assert(0);
    }
}

std::string destinatarioAString(TipoDestinatario dest){
    switch (dest){
    case PERSONA:
        return "Persona";
    case BANCO:
        return "Banco";
    case IMPUESTO:
        return "Impuesto";
    default:
        assert(0);
    }
}
