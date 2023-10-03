#include <iostream>
#include <fstream>
#include "Fila/Fila.h"
#include "Pila/Pila.h"

/*
  * Este programa utliza los ADT Fila y Pila para almacenar datos.
  * implementados en los archivos Fila/Fila.cpp y Pila/Pila.cpp
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
  * Complejidad espacial:
  * Crear: O(1)
  * Leer: O(1)
  * Actualizar: O(1)
  * Eliminar: O(1)
  * 
  * Nota: El programa espera que el archivo de texto tenga el formato correcto.
  * 
  * Autor: Daniel Alfredo Barreras Meraz
  * Matrícula: A01254805
  * Fecha: 24 de septiembre de 2023
*/

/*
    Pasos para compilar y ejecutar uel programa tilizando make:
    Compilar y ejecutar: make
*/

int main() {
    Fila fila;
    Pila pila;

    std::fstream archivo("input.txt");
    std::string linea;

    std::cout << "Creando nodos en la Fila y la Pila:\n";
    while(std::getline(archivo, linea)) {
        int valor = std::stoi(linea);
        fila.create(valor);
        pila.create(valor);

        std::cout << "Fila después de crear nodos: ";
        fila.display();

        std::cout << "Pila después de crear nodos: ";
        pila.display();
    }

    std::cout << "\nLeyendo valores en la Fila y la Pila:\n";
    for(int i = 1; i <= 5; i++) {
        bool encontradoEnFila = fila.read(i);
        bool encontradoEnPila = pila.read(i);

        std::cout << "El valor " << i << (encontradoEnFila ? " fue" : " no fue") << " encontrado en la fila.\n";
        std::cout << "El valor " << i << (encontradoEnPila ? " fue" : " no fue") << " encontrado en la pila.\n";
    }

    std::cout << "\nActualizando valores en la Fila y la Pila:\n";
    for(int i = 1; i <= 5; i++) {
        fila.update(i, i+5);
        pila.update(i, i+5);

        std::cout << "Fila después de actualizar el nodo con valor " << i << ": ";
        fila.display();

        std::cout << "Pila después de actualizar el nodo con valor " << i << ": ";
        pila.display();
    }

    std::cout << "\nEliminando valores en la Fila y la Pila:\n";
    for(int i = 1; i <= 5; i++) {
        fila.del(i+5);
        pila.del(i+5);

        std::cout << "Fila después de eliminar el nodo con valor " << i+5 << ": ";
        fila.display();

        std::cout << "Pila después de eliminar el nodo con valor " << i+5 << ": ";
        pila.display();
    }

    return 0;
}