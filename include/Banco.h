#ifndef BANCO_H
#define BANCO_H
#include "Cliente.h"
#include "Fila.h"
#include "Lista.h"

const int MAXIMAS_ESP = 2;

const int MINIMAS_COLAS = 1;
const int MAXIMAS_COLAS = 1 + MAXIMAS_ESP;




class Banco
{
    public:
        Banco();
        virtual ~Banco();
        void ingresaCliente(Cliente* nuevoCliente);
        Cliente* atender();
        Cliente* atender(TipoOperacion operacion, bool esCliente);
        void abrirColaConCriterio(TipoOperacion op, bool esCliente);
        bool cerrarColaConCriterio(TipoOperacion op, bool esCliente);
        void listarOperaciones(unsigned int minimo, unsigned int maximo);

        unsigned int colasAbiertas();
        bool existeColaConCriterio(TipoOperacion op, bool esCliente);

    private:
        typedef struct ColaEspecial{
            TipoOperacion operacion;
            bool esCliente;
            Fila<Cliente*> * cola;
        }ColaEspecial;

        Fila<Cliente*>* colaGeneral;

        Lista<ColaEspecial>* colasEspeciales;

        Lista<Cliente*>* historial;

};

#endif // BANCO_H
