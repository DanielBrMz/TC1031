#include "ListaEnlazada.h"

Barco* LinkedList::getHead() {
    return head;
}

void LinkedList::create(Barco* barco) {
    if (!head || barco->UBI < head->UBI) {
        barco->next = head;
        head = barco;
    } else {
        Barco* current = head;
        while (current->next && current->next->UBI < barco->UBI)
            current = current->next;
        barco->next = current->next;
        current->next = barco;
    }

    count++;
}

Barco* LinkedList::read(int index) {
    Barco* current = head;
    int count = 0;
    while (current) {
        if (count == index)
            return current;
        current = current->next;
        count++;
    }
    return nullptr; // No se encontró el índice
}

void LinkedList::del(std::string UBI) {
    if (!head)
        return;

    if (head->UBI == UBI) {
        Barco* to_delete = head;
        head = head->next;
        delete to_delete;
        count--;
        return;
    }

    Barco* current = head;
    while (current->next && current->next->UBI != UBI)
        current = current->next;

    if (current->next) {
        Barco* to_delete = current->next;
        current->next = to_delete->next;
        count--;
        delete to_delete;
    }
}

Barco* LinkedList::mergeSort(Barco* head) {
    if (!head || !head->next)
        return head;
    Barco* slow = head;
    Barco* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = nullptr;

    return merge(mergeSort(head), mergeSort(fast));
}

Barco* LinkedList::merge(Barco* a, Barco* b) {
    if (!a)
        return b;
    if (!b)
        return a;

    if (a->UBI < b->UBI) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}


Barco* LinkedList::binarySearch(std::string UBI) {
    Barco* start = head;
    Barco* end = nullptr;

    do {
        Barco* middle = start;
        Barco* current = start;
        int hops = 0;

        while (current != end) {
            hops++;
            current = current->next;

            if (hops % 2 == 0)
                middle = middle->next;
        }

        if (middle->UBI == UBI)
            return middle;

        if (middle->UBI < UBI)
            start = middle->next;
        else
            end = middle;

    } while (end == nullptr || end != start);

    return nullptr; // No se encontró el UBI
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


/*
    * Este programa utiliza los algoritmos de ordenamiento Merge Sort y búsqueda binaria 
    * implementados en el archivo OrdenamientoBuques.cpp y BusquedaBuques.cpp
    * para ordenar y buscar buques en un archivo de entrada.
    * 
    * El programa lee un archivo de entrada indicado por el usuario con el siguiente formato:
    * - Fecha (formato dd/mm/aaaa)
    * - Hora (formato hh:mm)
    * - Punto de entrada (un caracter)
    * - UBI (formato XXX-NNNNNN-ZZ)
    * 
    * El programa ordena los buques por fecha y hora de entrada, y luego realiza una búsqueda
    * binaria en los buques para encontrar los buques de una serie indicada por el usuario.
    * 
    * El programa imprime los buques de la serie indicada por el usuario en la consola.
    * 
    * Complejidad temporal:
    * Ordenamiento: O(n log n)
    * Búsqueda: O(log n)
    * 
    * Complejidad espacial:
    * Ordenamiento: O(n)
    * Búsqueda: O(1)
    * 
    * Nota: El programa espera que el archivo de texto tenga el formato correcto.
    * 
    * Autor: Daniel Alfredo Barreras Meraz
    * Matrícula: A01254805
    * Fecha: 21 de septiembre de 2023
*/

/*
    Pasos para compilar y ejecutar uel programa tilizando make:
    Compilar: make
    Ejecutar: make run
*/