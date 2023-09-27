#include "LinkedList.h"

LinkedList::LinkedList() {
    cabeza = NULL;
    cola = NULL;
}

/* Este algoritmo tiene una complejidad  de O(1) en tiempo y O(1) en espacio.
 * 
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
void LinkedList::create(int valor) {
    Nodo* temp = new Nodo;
    temp->dato = valor;
    temp->siguiente = NULL;

    if(cabeza == NULL) {
        cabeza = temp;
        cola = temp;
        temp = NULL;
    }
    else {	
        cola->siguiente = temp;
        cola = temp;
    }
}


/* Este algoritmo tiene una complejidad  de O(n) en tiempo y O(1) en espacio.
 * 
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
Nodo* LinkedList::read(int valor) {
    Nodo* temp = cabeza;
    while(temp != NULL) {
        if(temp->dato == valor) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;  // Retorna NULL si el valor no se encuentra en la lista
}

/* Este algoritmo tiene una complejidad  de O(n) en tiempo y O(1) en espacio.
 * 
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
void LinkedList::update(int valorAntiguo, int valorNuevo) {
    Nodo* nodoParaActualizar = read(valorAntiguo);
    if(nodoParaActualizar != NULL)
        nodoParaActualizar->dato = valorNuevo;
    else
        std::cout << "El valor " << valorAntiguo << " no fue encontrado para actualizar." << std::endl;
}

/* Este algoritmo tiene una complejidad  de O(n) en tiempo y O(1) en espacio.
 * 
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
void LinkedList::del(int valor) {
    if(cabeza == NULL) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    if(cabeza->dato == valor) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return;
    }

    Nodo* actual = cabeza;
    while(actual->siguiente != NULL && actual->siguiente->dato != valor) {
        actual = actual->siguiente;
    }

    if(actual->siguiente != NULL) {
        Nodo* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
    } else {
        std::cout << "El valor " << valor << " no fue encontrado para eliminar." << std::endl;
    }
}

/* Este algoritmo tiene una complejidad  de O(n) en tiempo y O(1) en espacio.
  * 
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
void LinkedList::display() {
    Nodo* temp = new Nodo;
    temp = cabeza;
    while(temp != NULL) {
        std::cout << temp->dato << "\t";
        temp = temp->siguiente;
    }
}

LinkedList::~LinkedList() {
    Nodo* temp = new Nodo;
    while(cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}
