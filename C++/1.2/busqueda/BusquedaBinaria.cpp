#include "BusquedaBinaria.h"
#include <vector>

int busqBinaria(std::vector<int>& numeros, int dato, int& iteraciones) {
    int left = 0;
    int right = numeros.size() - 1;
    iteraciones = 0;
    while (left <= right) { // O(log n) porque se divide el problema a la mitad en cada iteración
        iteraciones++; // O(1)
        int mid = left + (right - left) / 2; // O(1)
        if (numeros[mid] == dato) { // O(1)
            return mid; // O(1)
        }
        if (numeros[mid] < dato) { // O(1)
            left = mid + 1; // O(1)
        } else {
            right = mid - 1; // O(1)
        }
    }
    return -1; // O(1)
}
