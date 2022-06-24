#ifndef BANCO_H
#define BANCO_H
#include "Cliente.h"
typedef enum{RETIRO = 0, DEPOSITO, TRANSFERENCIA, PAGO} TipoOperacion;
typedef enum{PERSONA = 0, BANCO, IMPUESTO} TipoDestinatario;
class Banco
{
    public:
        Banco();
        virtual ~Banco();
        void ingresaCliente(Cliente & nuevoCliente);
        void atender();
        void abrirColaConCriterio(TipoOperacion op, bool esCliente);
        void cerrarColaConCriterio();
        void listarOperaciones(unsigned int minimo, unsigned int maximo);

    protected:

    private:
        typedef struct colaEspecial{
            TipoOperacion operacion;
            bool esCliente;
            Fila<Cliente> * cola;
        }colaEspecial;

        Fila<Cliente>* colaGeneral;

        Lista<colaEspecial>* colasEspeciales;

        Lista<Cliente>* historial;

};

#endif // BANCO_H
