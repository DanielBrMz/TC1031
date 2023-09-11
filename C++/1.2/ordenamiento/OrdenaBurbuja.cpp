#include "OrdenaBurbuja.h"
#include <vector>

int ordenaBurbuja(std::vector<int>& numeros) {
    int n = numeros.size();
    int iteraciones = 0;
    for(int i = 0; i < n-1; i++) { // O(n)
        for(int j = 0; j < n-i-1; j++) { // O(n)
            iteraciones++; // O(1)
            if(numeros[j] > numeros[j+1]) { // O(1)
                // Intercambiar numeros[j] y numeros[j+1]
                int temp = numeros[j]; // O(1)
                numeros[j] = numeros[j+1]; // O(1)
                numeros[j+1] = temp; // O(1)
            }
        }
    }
    return iteraciones; // O(1)
}
