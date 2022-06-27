#ifndef FILA_H
#define FILA_H
#include "Lista.h"

template <typename T>
class Fila
{
    public:
        Fila();
        virtual ~Fila();
        // primero consulta el valor del proximo elemento a retirar pero sin cambiar la Fila
        T primero();
        bool vacia();
        void agregar(T elemento);
        unsigned int longitud();
        //retirar retorna el primer elemento de la fila y lo elimina de la Fila
        T retirar();


    private:
        Lista<T>* lista;

 };

#endif // FILA_H
