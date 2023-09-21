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
void merge(std::vector<Buque>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Buque> leftArr(n1);
    std::vector<Buque> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].ubi + leftArr[i].fecha <= rightArr[j].ubi + rightArr[j].fecha) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Función para realizar Merge Sort
void ordenamientoMerge(std::vector<Buque>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        ordenamientoMerge(arr, left, mid);
        ordenamientoMerge(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}