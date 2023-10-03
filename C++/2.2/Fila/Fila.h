#pragma once
#include "../Nodo.h"

class Fila {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    Fila();

    void create(int valor);
    bool read();
    void update(int valorNuevo);
    void del();
    void display();
};
