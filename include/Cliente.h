#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    public:
        Cliente();
        virtual ~Cliente();

    protected:

    private:
        string nombre;
        unsigned int edad;
        TipoOperacion operacion;
        TipoDestinatario destinatario;
        unsigned int monto;
        bool esCliente;
};

#endif // CLIENTE_H
