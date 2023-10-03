#pragma once

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Fila {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    Fila();

    void create(int valor);
    bool read(int valor);
    void update(int valorAntiguo, int valorNuevo);
    void del(int valor);
    void display();
};
