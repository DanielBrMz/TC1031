#include <iostream>
#include "Fila.h"

Fila::Fila() : cabeza(nullptr), cola(nullptr) {}

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