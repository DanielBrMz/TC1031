#include "../Buque.h"

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

void merge(std::vector<Buque>& arr, int inicio, int mid, int fin) {
    int n1 = mid - inicio + 1; // O(1)
    int n2 = fin - mid; // O(1)

    std::vector<Buque> inicioArray(n1); // O(n)
    std::vector<Buque> finalArray(n2); // O(n)

    for (int i = 0; i < n1; i++) { // O(n)
        inicioArray[i] = arr[inicio + i]; // O(1)
    }
    for (int i = 0; i < n2; i++) { // O(n)
        finalArray[i] = arr[mid + 1 + i]; // O(1)
    }

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) { // O(n)
        if (inicioArray[i].ubi + inicioArray[i].fecha <= finalArray[j].ubi + finalArray[j].fecha) { // O(1)
            arr[k] = inicioArray[i]; // O(1)
            i++;
        } else {
            arr[k] = finalArray[j]; // O(1)
            j++;
        }
        k++;
    }

    while (i < n1) { // O(n)
        arr[k] = inicioArray[i]; // O(1)
        i++;
        k++;
    }

    while (j < n2) { // O(n)
        arr[k] = finalArray[j]; // O(1)
        j++;
        k++;
    }
}

void ordenamientoBuques(std::vector<Buque>& arr, int inicio, int fin) {
    if (inicio < fin) { // O(1)
        int mid = inicio + (fin - inicio) / 2; // O(1)
        ordenamientoBuques(arr, inicio, mid); // T(n/2)
        ordenamientoBuques(arr, mid + 1, fin); // T(n/2)
        merge(arr, inicio, mid, fin); // O(n)
    }
}

// Suma de complejidades: O(n log n) porque T(n) = 2T(n/2) + O(n) = O(n log n)