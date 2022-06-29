#include <iostream>
#include "include/Lista.h"
#include "include/Tests.h"
#include "include/Fila.h"
#include "include/ArbolBinario.h"

#include "include/Banco.h"
#include "include/Cliente.h"

using namespace std;

typedef enum{INGRESA = 1, ATENDER, ABRIR_COLA, CERRAR_COLA, LISTAR, SALIR} Opcion;

Opcion menu(void){
    unsigned int seleccion = 0;
    cout << endl << "Opciones:" << endl;
    cout << "1) Ingresar un nuevo cliente" << endl;
    cout << "2) Atender al proximo cliente" << endl;
    cout << "3) Abrir cola con criterio" << endl;
    cout << "4) Cerrar cola con criterio" << endl;
    cout << "5) Listar Operaciones realizadas" << endl;
    cout << "6) Salir" << endl;

    while (seleccion == 0 || seleccion > 6){
        cin >> seleccion;
    }
    return (Opcion)seleccion;
}

TipoOperacion ingresarOperacion(){
    unsigned int operacion = 0;
        cout << "Ingrese la operacion: " << endl;
        cout << "1) Retiro" << endl;
        cout << "2) Deposito" << endl;
        cout << "3) Transferencia" << endl;
        cout << "4) Pago" << endl;

        while (operacion == 0 || operacion > 4){
            cin >> operacion;
        }
    return (TipoOperacion)operacion;
}

bool ingresarEsCliente(){
    bool esCliente;
    unsigned int respuesta;
    cout << "Ingrese 1 si es cliente del banco: ";
    cin >> respuesta;
    respuesta == 1? esCliente = true : esCliente = false;

    return esCliente;
}
int main()
{

    testsLista();

    Banco* banco = new Banco;
    bool salir = false;
    Opcion op;

    while (!salir){
        op = menu();

        switch(op){
        case INGRESA:
            {
            string nombre;
            cout << "Ingrese el nombre del cliente:";
            cin >> nombre;

            unsigned int edad;
            cout << "Ingrese la edad del cliente: ";
            cin >> edad;

            TipoOperacion operacion = ingresarOperacion();


            unsigned int destinatario = 0;
            cout << "Ingrese el destinatario: " << endl;
            cout << "1) Persona" << endl;
            cout << "2) Banco" << endl;
            cout << "3) Impuesto" << endl;

            while (destinatario == 0 || destinatario > 3){
                cin >> destinatario;
            }

            unsigned int monto;
            cout << "Ingrese el monto: ";
            cin >> monto;

            bool esCliente = ingresarEsCliente();

            Cliente* nuevoCliente = new Cliente(nombre, edad, operacion, (TipoDestinatario)destinatario, monto, esCliente);
            banco->ingresaCliente(nuevoCliente);
            }
            break;

        case ATENDER:
            {
            unsigned int abiertas = banco->colasAbiertas();
            Cliente* atendido;

            if (abiertas == 1){
                atendido = banco->atender();
                if (atendido == NULL){
                    cout << "La cola general esta vacia" << endl;
                }else{
                    cout << "Datos del cliente atendido:" << endl;
                    atendido->imprimir();
                }

            }else{
                cout << "Ingrese el criterio: " << endl;
                bool esClienteCriterio;
                TipoOperacion operacionCriterio;
                do
                {
                    operacionCriterio = ingresarOperacion();
                    esClienteCriterio = ingresarEsCliente();
                }while(!banco->existeColaConCriterio(operacionCriterio, esClienteCriterio));

                atendido = banco->atender(operacionCriterio, esClienteCriterio);
                if (atendido == NULL){
                    cout << "Esta cola especial esta vacia" << endl;
                }else{
                    atendido->imprimir();
                }
            }
            }
            break;

        case ABRIR_COLA:
            {
            if (banco->colasAbiertas() != MAXIMAS_COLAS){

                TipoOperacion operacionAbrir;
                bool esClienteAbrir;
                do
                {
                    operacionAbrir = ingresarOperacion();
                    esClienteAbrir = ingresarEsCliente();
                }while (banco->existeColaConCriterio(operacionAbrir, esClienteAbrir));

                banco->abrirColaConCriterio(operacionAbrir, esClienteAbrir);
                cout << "Abierta una nueva cola especial" << endl;

            }else{
                cout << "Ya estan abiertas todas las colas posibles" << endl;
            }
            }
            break;

        case CERRAR_COLA:
            {
            if (banco->colasAbiertas() == MINIMAS_COLAS){
                cout << "No hay colas especiales abiertas" << endl;
            }else{
                cout << "Ingrese el Criterio:" << endl;

                TipoOperacion operacionCerrar;
                bool esClienteCerrar;
                do
                {
                    operacionCerrar = ingresarOperacion();
                    esClienteCerrar = ingresarEsCliente();
                }while (!banco->existeColaConCriterio(operacionCerrar, esClienteCerrar));

                if (banco->cerrarColaConCriterio(operacionCerrar, esClienteCerrar) == true){
                    cout << "Se cerro una cola especial" << endl;
                }else{
                    cout << "La cola aun no esta vacia" << endl;
                }
            }
            }
            break;

        case LISTAR:
            {
            unsigned int minimo, maximo;
            cout << "Ingrese un monto minimo: ";
            cin >> minimo;

            cout << "Ingrese un monto maximo: ";
            do
            {
                cin >> maximo;
            }while (maximo < minimo);

            banco->listarOperaciones(minimo, maximo);
            }
            break;

        case SALIR:
            {
            salir = true;
            }
            break;
        }
    }
    return 0;
}
