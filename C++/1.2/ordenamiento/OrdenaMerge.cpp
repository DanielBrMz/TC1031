#include "OrdenaMerge.h"

void merge(std::vector<int>& numeros, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = numeros[left + i];
    for (j = 0; j < n2; j++)
        R[j] = numeros[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            numeros[k] = L[i];
            i++;
        } else {
            numeros[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numeros[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        numeros[k] = R[j];
        j++;
        k++;
    }
}

void ordenaMerge(std::vector<int>& numeros, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        ordenaMerge(numeros, left, mid);
        ordenaMerge(numeros, mid + 1, right);

        merge(numeros, left, mid, right);
    }
}

void ordenaMerge(std::vector<int>& numeros) {
    ordenaMerge(numeros, 0, numeros.size() - 1);
}
#include <vector>

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

void ordenaMerge(std::vector<int>& numeros, int left, int right, int& comparaciones) {
    if (left < right) { // O(1)
        int mid = left + (right - left) / 2; // O(1)

        ordenaMerge(numeros, left, mid, comparaciones); // T(n/2)
        ordenaMerge(numeros, mid + 1, right, comparaciones); // T(n/2)

        merge(numeros, left, mid, right, comparaciones); // T(n), donde T(n) es el tiempo de la función merge
    }
}

int ordenaMerge(std::vector<int>& numeros) {
    int comparaciones = 0; // O(1)
    ordenaMerge(numeros, 0, numeros.size() - 1, comparaciones); // T(n), donde T(n) es el tiempo de la función ordenaMerge
    return comparaciones; // O(1)
}
