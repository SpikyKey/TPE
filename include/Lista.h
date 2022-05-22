#ifndef LISTA_H
#define LISTA_H



class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void agregar(unsigned int lugar, int elemento);
        unsigned int longitud();
        void agregarFin(int elemento);
        void agregarPrincipio(int elemento);
        bool pertenece(int elemento);
        bool vacia();
        bool eliminar(int elemento);
        int recuperar(unsigned int posicion);

    private:
        typedef struct Nodo{
            int elemento;
            struct Nodo * siguiente;
        }Nodo;
        Nodo * primerNodo;

        void agregarRecursivo(Nodo* nodo, unsigned int posicion, unsigned int lugar, int elemento);
};

#endif // LISTA_H
