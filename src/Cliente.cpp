#include "../include/Cliente.h"

Cliente::Cliente(std::string nombre, unsigned int edad, TipoOperacion operacion,
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
    std::cout << "Nombre: " << nombre << endl;
    std::cout << "Edad: " << edad << endl;
    std::cout << "Operacion: " << operacionAString(operacion) << endl;
    std::cout << "Destinatario: " << destinatarioAString(destinatario) << endl;
    std::cout << "Monto: " << monto << " Pesos" << endl;
    if (esCliente){
        std::cout << "Cliente: Si" << endl;
    }else{
        std::cout << "Cliente: No" << endl;
    }
}



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
