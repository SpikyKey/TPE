#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H


template <typename T> class ArbolBinario
{
    public:
        ArbolBinario();
        virtual ~ArbolBinario();
        void agregar(T elemento);
        bool pertenece(T elemento);
        unsigned int cantidad();
        bool vacio();
        unsigned int profundidad();
        Lista<T> listarFrontera();
        Lista<T> listarElementos();
    protected:

    private:
};

#endif // ARBOLBINARIO_H
