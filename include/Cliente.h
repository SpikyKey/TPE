#ifndef CLIENTE_H
#define CLIENTE_H
#include "string"
#include "iostream"


typedef enum{RETIRO = 1, DEPOSITO, TRANSFERENCIA, PAGO} TipoOperacion;
typedef enum{PERSONA = 1, BANCO, IMPUESTO} TipoDestinatario;

std::string destinatarioAString(TipoDestinatario dest);
std::string operacionAString(TipoOperacion op);

class Cliente
{
    public:
        Cliente(std::string nombre, unsigned int edad, TipoOperacion operacion,
                TipoDestinatario destinatario, unsigned int monto, bool esCliente);
        virtual ~Cliente();
        TipoOperacion getOperacion();
        bool getEsCliente();
        unsigned int getMonto();
        unsigned int getEdad();
        void imprimir();
    protected:

    private:
        std::string nombre;
        unsigned int edad;
        TipoOperacion operacion;
        TipoDestinatario destinatario;
        unsigned int monto;
        bool esCliente;

};

#endif // CLIENTE_H
