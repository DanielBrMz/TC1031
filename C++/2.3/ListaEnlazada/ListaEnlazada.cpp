#include "ListaEnlazada.h"

int ListaEnlazada::length() {
    return count;
}

Barco* ListaEnlazada::getHead() {
    return head;
}

/* Los algoritmos de las operaciones CRUD tienen una complejidad de O(n) en tiempo y O(1) en espacio.
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
void ListaEnlazada::create(Barco* barco) {
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

Barco* ListaEnlazada::read(int index) {
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

void ListaEnlazada::del(std::string UBI) {
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

/* Este algoritmo tiene una complejidad de O(n log n) en tiempo y O(n) en espacio.
 * 
 * Complejidad temporal:
 * - Mejor caso: O(n log n)
 * - Caso promedio: O(n log n)
 * - Peor caso: O(n log n)
 * 
 * Complejidad espacial:
 * - Mejor caso: O(n)
 * - Caso promedio: O(n)
 * - Peor caso: O(n)
*/
Barco* ListaEnlazada::mergeSort(Barco* head) {
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

Barco* ListaEnlazada::merge(Barco* a, Barco* b) {
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

