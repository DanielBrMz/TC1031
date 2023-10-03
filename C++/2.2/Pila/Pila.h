#pragma once

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Pila {
private:
    Nodo* tope;

public:
    Pila();

    // Crear: Agrega un valor al tope de la pila
    void create(int valor);

    // Leer: Retorna verdadero si el valor se encuentra en la pila, de lo contrario retorna falso
    bool read(int valor);

    // Actualizar: Actualiza el valor antiguo con el valor nuevo en la pila
    void update(int valorAntiguo, int valorNuevo);

    // Eliminar: Elimina el valor de la pila
    void del(int valor);

    // Mostrar: Imprime todos los elementos de la pila
    void display();
};
