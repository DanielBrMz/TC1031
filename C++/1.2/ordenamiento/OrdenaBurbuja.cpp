#include "OrdenaBurbuja.h"
#include <vector>

int ordenaBurbuja(std::vector<int>& numeros) {
    int comparaciones = 0; // Inicializa comparaciones en 0
    for (std::vector<int>::size_type i = 0; i < numeros.size() - 1; i++) { // O(n)
        for (std::vector<int>::size_type j = 0; j < numeros.size() - i - 1; j++) { // O(n)
            comparaciones++; // O(1)
            if (numeros[j] > numeros[j + 1]) { // O(1)
                std::swap(numeros[j], numeros[j + 1]); // O(1)
            }
        }
    }
    return comparaciones; // Devuelve el total de comparaciones
}