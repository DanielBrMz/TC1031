#include <vector>

#pragma once

class priority_queue{
    public:
    // Constructor por default
    priority_queue();

    // Constructor que tambien inicializa un nodo
    priority_queue(int value);

    // Heap
    std::vector<int> data;

    // Tamano
    int heap_size;

    // Funcion para agregar valores al heap
    void push(int value);

    // Funcion para extraer el dato prioritario del heap
    void pop();

    // Funcion para imprimir el dato prioritario del heap
    int top();

    // Funcion que devuelve si el heap esta vacio
    bool empty();

    // Funcion que devuelve el valor actual del heap
    int size();

    // Imprimir heap
    void print();
};