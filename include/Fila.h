#ifndef FILA_H
#define FILA_H

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
        typedef struct Nodo{
            T elemento;
            struct Nodo* siguiente;

        }Nodo;
        // el primerNodo no debe confundirse con el primer elemento de la Fila
        // en terminos del orden en que se retiran los elementos
        Nodo* primerNodo;

 };

#endif // FILA_H
