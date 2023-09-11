#include "OrdenaBurbuja.h"
#include <vector>

/* Este algoritmo tiene una complejidad de O(n^2) en tiempo y O(1) en espacio.
 * 
 * Complejidad temporal:
 * - Mejor caso: O(n)
 * - Caso promedio: O(n^2)
 * - Peor caso: O(n^2)
 * 
 * Complejidad espacial:
 * - Mejor caso: O(1)
 * - Caso promedio: O(1)
 * - Peor caso: O(1)
*/
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