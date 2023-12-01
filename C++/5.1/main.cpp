// main.cpp
#include <iostream>
#include "HashTable/HashTable.h"

/*
  Este programa utiliza la clase HashTable para probar los métodos quadratic y chain de la siguiente manera:
    - Crea cuatro tablas de dispersión
    - Inserta las llaves 26, 30, 44, 20, 2, 5, 27 en las cuatro tablas
    - Imprime si cada llave se insertó correctamente y si se encontró en la tabla
    Se utiliza la estructura de datos HashTable para representar las tablas de dispersión y los métodos quadratic y chain para insertar las llaves.
    Complejidad Temporal de algoritmos utilizados:
        - quadratic: O(n), donde n es el tamaño de la tabla.
        - chain: O(1)
    Complejidad Espacial de algoritmos utilizados:
        - quadratic: O(n), donde n es el tamaño de la tabla.
        - chain: O(1)
*/


/*
    Autor: Daniel Alfredo Barreras Meraz
    Matrícula: A01254805
    Fecha: 20 de noviembre de 2023
*/

/*
  Compilar y ejecutar con make:
    make run
*/

int main() {
    // Creando cuatro tablas de dispersión
    HashTable ht1(10), ht2(10), ht3(10), ht4(10);
    int keys[] = {26, 30, 44, 20, 2, 5, 27};

    // Prueba 1: quadratic en ht1
    std::cout << "\nProbando metodo quadratic en ht1:\n";
    // Estructura de ht1 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht1.quadratic(key);
        if (ht1.find(key)) {
            std::cout << "Key " << key << " insertada y encontrada.\n";
        } else {
            std::cout << "Key " << key << " no encontrada.\n";
        }
    }

    // Prueba 2: chain en ht2
    std::cout << "\nProbando metodo chain en ht2:\n";
    // Estructura de ht2 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht2.chain(key);
        if (ht2.find(key)) {
            std::cout << "Key " << key << " insertada y encontrada.\n";
        } else {
            std::cout << "Key " << key << " no encontrada.\n";
        }
    }

    // Prueba 3: quadratic en ht3
    std::cout << "\nProbando metodo quadratic en ht3:\n";
    // Estructura de ht3 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht3.quadratic(key);
        if (ht3.find(key)) {
            std::cout << "Key " << key << " insertada y encontrada.\n";
        } else {
            std::cout << "Key " << key << " no encontrada.\n";
        }
    }

    // Prueba 4: chain en ht4
    std::cout << "\nProbando metodo chain en ht4:\n";
    // Estructura de ht4 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht4.chain(key);
        if (ht4.find(key)) {
            std::cout << "Key " << key << " insertada y encontrada.\n";
        } else {
            std::cout << "Key " << key << " no encontrada.\n";
        }
    }

    return 0;
}
