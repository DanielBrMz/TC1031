#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Barco/Barco.h"

class ListaEnlazada {
private:
    Barco* head;
    int count;

public:
    ListaEnlazada() : head(nullptr), count(0) {}

    int length();
    Barco* getHead();

    void create(Barco* barco);
    Barco* read(int index);
    void del(std::string UBI);

    // Implementación del algoritmo mergesort
    Barco* mergeSort(Barco* head);
    Barco* merge(Barco* a, Barco* b);
};

#endif 
