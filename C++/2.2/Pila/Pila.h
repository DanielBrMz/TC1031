#pragma once
#include "../Nodo.h"

class Pila {
private:
    Nodo* tope;

public:
    Pila();

    void create(int valor);
    bool read();
    void update(int valorNuevo);
    void del();
    void display();
};
