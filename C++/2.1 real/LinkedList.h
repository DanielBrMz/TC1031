#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class LinkedList {
    private:
        Nodo* cabeza;
        Nodo* cola;
    public:
        LinkedList();
        void create(int valor);
        Nodo* read(int valor);
        void update(int valorAntiguo, int valorNuevo);
        void del(int valor);
        void display();
        ~LinkedList();
};

#endif 
