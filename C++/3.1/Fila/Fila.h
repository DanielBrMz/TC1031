#include "Nodo.h"
#include "NodoFila.h"

class Fila {
public:
    NodoFila *frente;
    NodoFila *atras;

    Fila(){
        frente = atras = nullptr;
    }

    void enqueue(Nodo *nodo){
        NodoFila *temp = new NodoFila;
        temp->nodo = nodo;
        temp->siguiente = nullptr;

        if (atras == nullptr){
            frente = atras = temp;
            return;
        }

        atras->siguiente = temp;
        atras = temp;
    }

    void dequeue(){
        if (frente == nullptr)
            return;

        NodoFila *temp = frente;
        frente = frente->siguiente;

        if (frente == nullptr)
            atras = nullptr;

        delete (temp);
    }

    bool isEmpty(){
        return (frente == nullptr);
    }

    Nodo *getFront() {
        return (frente->nodo);
    }
};