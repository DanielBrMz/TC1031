#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Barco.h"

class LinkedList {
private:
    Barco* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    Barco* getHead();
    int length() { return count; }

    // Crear un nuevo nodo
    void create(Barco* barco);

    // Leer un nodo
    Barco* read(int index);

    // Actualizar un nodo
    void update(std::string UBI, Barco* new_data);

    // Eliminar un nodo
    void del(std::string UBI);

    // Implementación del algoritmo mergesort
    Barco* mergeSort(Barco* head);
    Barco* merge(Barco* a, Barco* b);

    // Implementación del algoritmo de búsqueda binaria
    Barco* binarySearch(std::string UBI);
};

#endif // LINKEDLIST_H
