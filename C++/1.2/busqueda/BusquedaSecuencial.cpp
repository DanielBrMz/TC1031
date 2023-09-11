#include "BusquedaSecuencial.h"
#include <vector>

// busqeudaSecuencial que busca el dato en el vector, devuelve la posición del dato y el número de iteraciones por referencia
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