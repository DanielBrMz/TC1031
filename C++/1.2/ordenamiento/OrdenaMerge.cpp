#include "OrdenaMerge.h"
#include <vector>


/* Este algoritmo tiene una complejidad de O(n log n) en tiempo y O(n) en espacio.
 * 
 * Complejidad temporal:
 * - Mejor caso: O(n log n)
 * - Caso promedio: O(n log n)
 * - Peor caso: O(n log n)
 * 
 * Complejidad espacial:
 * - Mejor caso: O(n)
 * - Caso promedio: O(n)
 * - Peor caso: O(n)
*/
int ordenaMerge(std::vector<int>& numeros) {
    int comparaciones = 0; // Inicializa comparaciones en 0
    if (numeros.size() > 1) { // O(1)
        int mid = numeros.size() / 2; // O(1)
        std::vector<int> left(numeros.begin(), numeros.begin() + mid); // O(n)
        std::vector<int> right(numeros.begin() + mid, numeros.end()); // O(n)
        comparaciones += ordenaMerge(left); // O(n log n)
        comparaciones += ordenaMerge(right); // O(n log n)
        std::vector<int>::size_type i = 0; // O(1)
        std::vector<int>::size_type j = 0; // O(1)
        std::vector<int>::size_type k = 0; // O(1)
        while (i < left.size() && j < right.size()) { // O(n)
            comparaciones++; // O(1)
            if (left[i] <= right[j]) { // O(1)
                numeros[k] = left[i]; // O(1)
                i++; // O(1)
            } else {
                numeros[k] = right[j]; // O(1)
                j++; // O(1)
            }
            k++; // O(1)
        }
        while (i < left.size()) { // O(n)
            numeros[k] = left[i]; // O(1)
            i++; // O(1)
            k++; // O(1)
        }
        while (j < right.size()) { // O(n)
            numeros[k] = right[j]; // O(1)
            j++; // O(1)
            k++; // O(1)
        }
    }
    return comparaciones; // Devuelve el total de comparaciones
}