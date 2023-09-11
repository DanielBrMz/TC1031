#include "OrdenaMerge.h"
#include <vector>

// La función merge tiene una complejidad de tiempo de O(n)
void merge(std::vector<int>& numeros, int left, int mid, int right, int& comparaciones) {
    int i, j, k;
    int n1 = mid - left + 1; // O(1)
    int n2 = right - mid; // O(1)

    std::vector<int> L(n1), R(n2); // O(n)

    for (i = 0; i < n1; i++) // O(n)
        L[i] = numeros[left + i]; // O(1)
    for (j = 0; j < n2; j++) // O(n)
        R[j] = numeros[mid + 1 + j]; // O(1)

    i = 0; // O(1)
    j = 0; // O(1)
    k = left; // O(1)
    while (i < n1 && j < n2) { // O(n)
        comparaciones++; // O(1)
        if (L[i] <= R[j]) { // O(1)
            numeros[k] = L[i]; // O(1)
            i++; // O(1)
        } else {
            numeros[k] = R[j]; // O(1)
            j++; // O(1)
        }
        k++; // O(1)
    }

    while (i < n1) { // O(n)
        numeros[k] = L[i]; // O(1)
        i++; // O(1)
        k++; // O(1)
    }

    while (j < n2) { // O(n)
        numeros[k] = R[j]; // O(1)
        j++; // O(1)
        k++; // O(1)
    }
}

int ordenaMerge(std::vector<int>& numeros, int left, int right, int& comparaciones) {
    int inversiones = 0; // Inicializa inversiones en 0

    if (left < right) {
        int mid = left + (right - left) / 2;

        inversiones += ordenaMerge(numeros, left, mid, comparaciones);
        inversiones += ordenaMerge(numeros, mid + 1, right, comparaciones);

        merge(numeros, left, mid, right, comparaciones);

        comparaciones += inversiones; // Agrega las inversiones al total de comparaciones
    }

    return inversiones; // Devuelve el total de inversiones
}



int ordenaMergeComparaciones(std::vector<int>& numeros) {
    int comparaciones = 0;
    ordenaMerge(numeros, 0, numeros.size() - 1, comparaciones);
    return comparaciones;
}


