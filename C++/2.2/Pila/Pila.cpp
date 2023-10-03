#include "Pila.h"
#include <iostream>

Pila::Pila() : tope(nullptr) {}

/* Este algoritmo tiene complejidad temporal O(1) y complejidad espacial O(1) 
    * Complejidad temporal:
    * - Mejor caso: O(1)
    * - Caso promedio: O(1)
    * - Peor caso: O(1)
    * 
    * Complejidad espacial:
    * - Mejor caso: O(1)
    * - Caso promedio: O(1)
    * - Peor caso: O(1)
*/
void Pila::create(int valor) {
    Nodo* temp = new Nodo;
    temp->dato = valor;
    temp->siguiente = tope;
    tope = temp;
}

/* Este algoritmo tiene complejidad temporal O(n) y complejidad espacial O(1) 
    * Complejidad temporal:
    * - Mejor caso: O(1)
    * - Caso promedio: O(n)
    * - Peor caso: O(n)
    * 
    * Complejidad espacial:
    * - Mejor caso: O(1)
    * - Caso promedio: O(1)
    * - Peor caso: O(1)
*/
bool Pila::read() {
    if(tope == nullptr) {
        std::cout << "La pila está vacía." << std::endl;
        return false;
    }
    std::cout << "El valor superior de la pila es: " << tope->dato << std::endl;
    return true;
}

/* Este algoritmo tiene complejidad temporal O(n) y complejidad espacial O(1) 
    * Complejidad temporal:
    * - Mejor caso: O(1)
    * - Caso promedio: O(n)
    * - Peor caso: O(n)
    * 
    * Complejidad espacial:
    * - Mejor caso: O(1)
    * - Caso promedio: O(1)
    * - Peor caso: O(1)
*/
void Pila::update(int valorNuevo) {
    if(tope == nullptr) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }
    tope->dato = valorNuevo;
}

/* Este algoritmo tiene complejidad temporal O(1) y complejidad espacial O(1) 
    * Complejidad temporal:
    * - Mejor caso: O(1)
    * - Caso promedio: O(1)
    * - Peor caso: O(1)
    * 
    * Complejidad espacial:
    * - Mejor caso: O(1)
    * - Caso promedio: O(1)
    * - Peor caso: O(1)
*/
void Pila::del() {
    if(tope == nullptr) {
        std::cout << "La pila está vacía." << std::endl;
        return;
    }

    Nodo* temp = tope;
    tope = tope->siguiente;
    delete temp;
}

void Pila::display() {
    Nodo* temp = tope;
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
