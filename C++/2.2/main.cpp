#include <iostream>
#include <fstream>
#include "Fila/Fila.h"
#include "Pila/Pila.h"

int main() {
    Fila fila;
    Pila pila;

    std::fstream archivo("input.txt");
    std::string linea;

    // Crear elementos y mostrar la fila y la pila
    while(std::getline(archivo, linea)) {
        int valor = std::stoi(linea);
        fila.create(valor);
        pila.create(valor);

        std::cout << "Fila después de crear nodos: ";
        fila.display();
        std::cout << std::endl;

        std::cout << "Pila después de crear nodos: ";
        pila.display();
        std::cout << std::endl;
    }

    // Leer elementos
    for(int i = 1; i <= 5; i++) {
        bool encontradoEnFila = fila.read(i);
        bool encontradoEnPila = pila.read(i);

        std::cout << "El valor " << i << (encontradoEnFila ? " fue" : " no fue") << " encontrado en la fila." << std::endl;
        std::cout << "El valor " << i << (encontradoEnPila ? " fue" : " no fue") << " encontrado en la pila." << std::endl;
    }

    // Actualizar elementos
    for(int i = 1; i <= 5; i++) {
        fila.update(i, i+5);
        pila.update(i, i+5);

        std::cout << "Fila después de actualizar el nodo con valor " << i << ": ";
        fila.display();
        std::cout << std::endl;

        std::cout << "Pila después de actualizar el nodo con valor " << i << ": ";
        pila.display();
        std::cout << std::endl;
    }

    // Eliminar elementos
    for(int i = 1; i <= 5; i++) {
        fila.del(i+5);
        pila.del(i+5);

        std::cout << "Fila después de eliminar el nodo con valor " << i+5 << ": ";
        fila.display();
        std::cout << std::endl;

        std::cout << "Pila después de eliminar el nodo con valor " << i+5 << ": ";
        pila.display();
        std::cout << std::endl;
    }

    return 0;
}

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

/* Este algoritmo tiene una complejidad  de O(1) en tiempo y O(1) en espacio.
 * 
 * Complejidad temporal:
 * - Mejor caso: O(1)
 * - Caso promedio: O(1)
 * - Peor caso: O(1)
 * 
 * Complejidad espacial:
 * - Mejor caso: O(1)
 * - Caso promedio: O(1)
 * - Peor caso: O(1)
*/