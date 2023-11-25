// main.cpp
#include <iostream>
#include "HashTable/HashTable.h"

int main() {
    // Creando cuatro tablas de dispersión
    HashTable ht1(10), ht2(10), ht3(10), ht4(10);
    int keys[] = {26, 30, 44, 20, 2, 5, 27};

    // Prueba 1: quadratic en ht1
    std::cout << "\nTesting quadratic method on ht1:\n";
    // Estructura de ht1 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht1.quadratic(key);
        if (ht1.find(key)) {
            std::cout << "Key " << key << " inserted and found.\n";
        } else {
            std::cout << "Key " << key << " not found.\n";
        }
    }

    // Prueba 2: chain en ht2
    std::cout << "\nTesting chain method on ht2:\n";
    // Estructura de ht2 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht2.chain(key);
        if (ht2.find(key)) {
            std::cout << "Key " << key << " inserted and found.\n";
        } else {
            std::cout << "Key " << key << " not found.\n";
        }
    }

    // Prueba 3: quadratic en ht3
    std::cout << "\nTesting quadratic method on ht3:\n";
    // Estructura de ht3 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht3.quadratic(key);
        if (ht3.find(key)) {
            std::cout << "Key " << key << " inserted and found.\n";
        } else {
            std::cout << "Key " << key << " not found.\n";
        }
    }

    // Prueba 4: chain en ht4
    std::cout << "\nTesting chain method on ht4:\n";
    // Estructura de ht4 antes de la prueba: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for (int key : keys) {
        ht4.chain(key);
        if (ht4.find(key)) {
            std::cout << "Key " << key << " inserted and found.\n";
        } else {
            std::cout << "Key " << key << " not found.\n";
        }
    }

    return 0;
}
