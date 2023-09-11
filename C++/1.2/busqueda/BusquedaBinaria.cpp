#include "BusquedaBinaria.h"
#include <vector>

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