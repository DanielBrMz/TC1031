#include "OrdenaIntercambio.h"
#include <vector>

int ordenaIntercambio(std::vector<int>& numeros) {
    int comparaciones = 0; // Inicializa comparaciones en 0
    for (std::vector<int>::size_type i = 0; i < numeros.size() - 1; i++) { // O(n)
        for (std::vector<int>::size_type j = i + 1; j < numeros.size(); j++) { // O(n)
            comparaciones++; // O(1)
            if (numeros[i] > numeros[j]) { // O(1)
                std::swap(numeros[i], numeros[j]); // O(1)
            }
        }
    }
    return comparaciones; // Devuelve el total de comparaciones
}