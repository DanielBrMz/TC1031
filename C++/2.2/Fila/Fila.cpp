#include <iostream>
#include "Fila.h"

Fila::Fila() : cabeza(nullptr), cola(nullptr) {}

// Complejidad temporal y espacial: O(1)
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

// Complejidad temporal y espacial: O(1)
bool Fila::read() {
    if(cabeza == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
        return false;
    }
    std::cout << "El primer valor en la cola es: " << cabeza->dato << std::endl;
    return true;
}

// Complejidad temporal y espacial: O(1)
void Fila::update(int valorNuevo) {
    if(cabeza == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }
    cabeza->dato = valorNuevo;
}

// Complejidad temporal y espacial: O(1)
void Fila::del() {
    if(cabeza == nullptr) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }

    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;
    delete temp;
}

// Complejidad temporal: O(n), Complejidad espacial: O(1)
void Fila::display() {
    Nodo* temp = cabeza;
    if(temp != nullptr) {
        std::cout << temp->dato;
        temp = temp->siguiente;
    }
    while(temp != nullptr) {
        std::cout << " " << temp->dato;
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}
