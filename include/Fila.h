#ifndef FILA_H
#define FILA_H


class Fila
{
    public:
        Fila();
        virtual ~Fila();
        void agregar (int elemento);
        unsigned int longitud();
        int retirar ();
        int proximoasalir();
        bool vacia();



    private:
        typedef struct F{
            int elemento;
            struct Nodo * siguiente;
        };

#endif // FILA_H
