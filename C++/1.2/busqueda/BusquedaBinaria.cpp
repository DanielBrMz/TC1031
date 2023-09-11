#include "BusquedaBinaria.h"
#include <vector>

/* Este algoritmo tiene una complejidad  de O(log n) en tiempo y O(1) en espacio.
 * 
 * Complejidad temporal:
 * - Mejor caso: O(1)
 * - Caso promedio: O(log n)
 * - Peor caso: O(log n)
 * 
 * Complejidad espacial:
 * - Mejor caso: O(1)
 * - Caso promedio: O(1)
 * - Peor caso: O(1)
*/

int busquedaBinaria(std::vector<int>& numeros, int dato, int& iteraciones) {
    iteraciones = 0; // Inicializa iteraciones en 0
    int inicio = 0; // Inicializa inicio en 0
    int fin = numeros.size() - 1; // Inicializa fin en el tamaño del vector - 1
    while (inicio <= fin) { // O(log n)
        iteraciones++; // O(1)
        int mid = (inicio + fin) / 2; // O(1)
        if (numeros[mid] == dato) { // O(1)
            return mid; // O(1)
        } else if (numeros[mid] < dato) { // O(1)
            inicio = mid + 1; // O(1)
        } else {
            fin = mid - 1; // O(1)
        }
    }
    return -1; // O(1)
}