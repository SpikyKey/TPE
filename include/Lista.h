#ifndef LISTA_H
#define LISTA_H


//!!!!!!!!!!!!! CAMBIAR ESTE TYPEDEF Y USAR UN TEMPLATE COMO LO PIDE !!!!!!!!!!!!!!!!!!!!
typedef int t_elem;


typedef struct Nodo{
            t_elem elemento;
            struct Nodo * siguiente;
}Nodo;

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void agregar(unsigned int lugar, t_elem elemento);
        unsigned int longitud();
        void agregarFin(t_elem elemento);
        void agregarPrincipio(t_elem elemento);
        bool pertenece(t_elem elemento);


        bool vacia();

        // si el elemento se pudo eliminar retorna true
        // si el elemento no esta retorna false
        bool eliminar(t_elem elemento);
        t_elem recuperar(unsigned int posicion);

    private:

        Nodo * primerNodo;

        Nodo* agregarRecursivo(Nodo* nodo, unsigned int posicion, t_elem elemento);
        bool eliminarRecursivo(Nodo* & nodo, t_elem elemento);
};

#endif // LISTA_H
