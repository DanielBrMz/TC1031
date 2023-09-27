#include <iostream>
#include <fstream>
#include "LinkedList.h"

/*
    * Este programa utiliza una lista enlazada para almacenar datos.
    * implementados en el archivo LinkedList.cpp
    * para crear, leer, actualizar y eliminar nodos de la lista.
    * 
    * El programa crea 5 nodos desde un archivo input.txt, los lee, los actualiza y los elimina.
    *
    * Complejidad temporal:
    * Crear: O(1)
    * Leer: O(n)
    * Actualizar: O(n)
    * Eliminar: O(n)
    *
    * Nota: El programa espera que el archivo de texto tenga el formato correcto.
    * 
    * Autor: Daniel Alfredo Barreras Meraz
    * Matrícula: A01254805
    * Fecha: 26 de septiembre de 2023
*/

/*
    Pasos para compilar y ejecutar uel programa tilizando make:
    Compilar y ejecutar: make
*/

int main() {
    LinkedList lista;

    std::fstream archivo("input.txt");
    std::string linea;


    // Crear 5 elementos y mostrar la lista
    while(std::getline(archivo, linea)) {
        lista.create(std::stoi(linea));
        std::cout << "Lista después de crear nodos: ";
        lista.display();
        std::cout << std::endl;
    }

    // Leer 5 elementos
    for(int i = 1; i <= 5; i++) {
        Nodo* nodo = lista.read(i);
        if(nodo != NULL)
            std::cout << "El valor " << i << " fue encontrado en la posición: " << nodo << std::endl;
        else
            std::cout << "El valor " << i << " no fue encontrado." << std::endl;
    }

    // Actualizar 5 elementos
    for(int i = 1; i <= 5; i++) {
        Nodo* nodo = lista.read(i);
        if(nodo != NULL) {
            lista.update(i, i+5);
            std::cout << "Lista después de actualizar el nodo con valor " << i << ": ";
            lista.display();
            std::cout << std::endl;
        }
    }

    // Eliminar 5 elementos
    for(int i = 1; i <= 5; i++) {
        Nodo* nodo = lista.read(i+5);
        if(nodo != NULL) {
            lista.del(i+5);
            std::cout << "Lista después de eliminar el nodo con valor " << i+5 << ": ";
            lista.display();
            std::cout << std::endl;
        }
    }

    return 0;
}

