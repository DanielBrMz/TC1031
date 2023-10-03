#include "Pila.h"
#include <iostream>

Pila::Pila() : tope(nullptr) {}

void Pila::create(int valor) {
    Nodo* temp = new Nodo;
    temp->dato = valor;
    temp->siguiente = tope;
    tope = temp;
}

bool Pila::read(int valor) {
    Nodo* temp = tope;
    while(temp != nullptr) {
        if(temp->dato == valor) {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;  // Retorna falso si el valor no se encuentra en la pila
}

void Pila::update(int valorAntiguo, int valorNuevo) {
    Nodo* temp = tope;
    while(temp != nullptr) {
        if(temp->dato == valorAntiguo) {
            temp->dato = valorNuevo;
            return;
        }
        temp = temp->siguiente;
    }
    std::cout << "El valor " << valorAntiguo << " no fue encontrado para actualizar." << std::endl;
}

void Pila::del(int valor) {
    if(tope == nullptr) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }

    if(tope->dato == valor) {
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
        return;
    }

    Nodo* actual = tope;
    while(actual->siguiente != nullptr && actual->siguiente->dato != valor) {
        actual = actual->siguiente;
    }

    if(actual->siguiente != nullptr) {
        Nodo* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
    } else {
        std::cout << "El valor " << valor << " no fue encontrado para eliminar." << std::endl;
    }
}

void Pila::display() {
    Nodo* temp = tope;
    while(temp != nullptr) {
        std::cout << temp->dato << "\t";
        temp = temp->siguiente;
    }
}
