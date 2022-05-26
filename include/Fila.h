#ifndef FILA_H
#define FILA_H


class Fila
{
    public:
        Fila();
        virtual ~Fila();
        int ultimo();
        bool vacia();
        void agrFila (int elemento);
        unsigned int longitud();
        int retirar ();
        int proximoasalir();




    private:
        typedef struct Nodo{
            int elemento;
            struct Nodo* siguiente;

        }Nodo;
        Nodo* primerNodo;

 };

#endif // FILA_H
