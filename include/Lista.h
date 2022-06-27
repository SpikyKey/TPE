#ifndef LISTA_H
#define LISTA_H


template <typename T>class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void agregar(unsigned int lugar, T elemento);
        unsigned int longitud();
        void agregarFin(T elemento);
        void agregarPrincipio(T elemento);
        bool pertenece(T elemento);


        bool vacia();

        // si el elemento se pudo eliminar retorna true
        // si el elemento no esta retorna false
        bool eliminar(unsigned int posicion);
        T recuperar(unsigned int posicion);

    private:

        typedef struct Nodo{
                    T elemento;
                    struct Nodo * siguiente;
        }Nodo;

        Nodo * primerNodo;
        Nodo * ultimoNodo;
        unsigned int contador;
        void agregarRecursivo(Nodo*& nodo, unsigned int posicion, T elemento);
        bool eliminarRecursivo(Nodo* & nodo, unsigned int posicion);
};

#endif // LISTA_H
