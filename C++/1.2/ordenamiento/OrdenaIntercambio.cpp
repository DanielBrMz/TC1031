#include "OrdenaIntercambio.h"
#include <vector>

int ordenaIntercambio(std::vector<int>& numeros) {
    int n = numeros.size(); // O(1)
    int iteraciones = 0; // O(1)
    for(int i = 0; i < n-1; i++) { // O(n)
        for(int j = i+1; j < n; j++) { // O(n)
            iteraciones++; // O(1)
            if(numeros[j] < numeros[i]) { // O(1)
                // Intercambiar numeros[i] y numeros[j]
                int temp = numeros[i]; // O(1)
                numeros[i] = numeros[j]; // O(1)
                numeros[j] = temp; // O(1)
            }
        }
    }
    return iteraciones; // O(1)
}
