#include "BusquedaSecuencial.h"
#include <vector>

/* Este algoritmo tiene unac complejidad de O(n) en tiempo y O(1) en espacio.
 * 
 * Complejidad temporal:
 * - Mejor caso: O(1)
 * - Caso promedio: O(n)
 * - Peor caso: O(n)
 * 
 * Complejidad espacial:
 * - Mejor caso: O(1)
 * - Caso promedio: O(1)
 * - Peor caso: O(1)

*/

int busquedaSecuencial(std::vector<int>& numeros, int dato, int& iteraciones) {
    iteraciones = 0; // Inicializa iteraciones en 0
    for (std::vector<int>::size_type i = 0; i < numeros.size(); i++) { // O(n)
        iteraciones++; // O(1)
        if (numeros[i] == dato) { // O(1)
            return i; // O(1)
        }
    }
    return -1; // O(1)
}