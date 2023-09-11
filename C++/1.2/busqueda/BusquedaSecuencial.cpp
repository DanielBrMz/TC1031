#include "BusquedaSecuencial.h"
#include <vector>

int busqSecuencial(std::vector<int>& numeros, int dato, int& iteraciones) {
    int n = numeros.size();
    iteraciones = 0;
    for(int i = 0; i < n; i++) { // O(n)
        iteraciones++; // O(1)
        if(numeros[i] == dato) { // O(1)
            return i; // O(1)
        }
    }
    return -1; // O(1)
}
