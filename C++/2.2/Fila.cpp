#include <iostream>
#include "Fila.h"

Fila::Fila() : cabeza(nullptr), cola(nullptr) {}

void Fila::create(int valor) {
    Nodo* temp = new Nodo;
    temp->dato = valor;
    temp->siguiente = nullptr;

    if(cabeza == nullptr) {
        cabeza = temp;
        cola = temp;
        temp = nullptr;
    }
    else {	
        cola->siguiente = temp;
        cola = temp;
    }
}

bool Fila::read(int valor) {
    Nodo* temp = cabeza;
    while(temp != nullptr) {
        if(temp->dato == valor) {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;  // Retorna falso si el valor no se encuentra en la cola
}

void Fila::update(int valorAntiguo, int valorNuevo) {
    Nodo* temp = cabeza;
    while(temp != nullptr) {
        if(temp->dato == valorAntiguo) {
            temp->dato = valorNuevo;
            return;
        }
        temp = temp->siguiente;
    }
    std::cout << "El valor " << valorAntiguo << " no fue encontrado para actualizar." << std::endl;
}

void Fila::del(int valor) {
    if(cabeza == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }

    if(cabeza->dato == valor) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return;
    }

    Nodo* actual = cabeza;
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

void Fila::display() {
    Nodo* temp = cabeza;
    while(temp != nullptr) {
        std::cout << temp->dato << "\t";
        temp = temp->siguiente;
    }
}
