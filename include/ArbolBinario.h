#ifndef Arbin_H
#define Arbin_H

#include "../include/Lista.h"
template <typename T> class Arbin
{
    public:
        Arbin();
        virtual ~Arbin();
        void cargar(T elemento);
	    bool pertenece(T elemento);
        unsigned int cantelmentos();
	    bool vacio ();
	    unsigned int profundidad ();
	    Lista<T>* listarFrontera ();
	    Lista<T>* listarArbin();



    protected:

    private:
        typedef struct NodoArbin{
            T campo;
            struct NodoArbin * hijoizq;
            struct NodoArbin * hijoder;
        }NodoArbin;

        NodoArbin* raiz;
        void cargarRecursivo(NodoArbin*& raiz, T elemento);
        bool perteneceRecursiva(NodoArbin* raiz, T elemento);
        unsigned int contarRecursivo(NodoArbin* raiz);
        unsigned int profundidadRecursiva(NodoArbin* raiz);
        Lista<T>* listarFronteraRecursiva(NodoArbin* raiz, Lista<T>*& Frontera);
        void listarRecursivo(NodoArbin* raiz, Lista<T> *& lista);

        void destructorRecursivo(NodoArbin* raiz);

};

#endif // ARBOLBINARIO_H
