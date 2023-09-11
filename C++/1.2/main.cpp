#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// ordenaBurbuja que ordena el vector por referencia y devuelve el número de comparaciones
int ordenaBurbuja(std::vector<int>& numeros) {
    int comparaciones = 0; // Inicializa comparaciones en 0
    for (std::vector<int>::size_type i = 0; i < numeros.size() - 1; i++) { // O(n)
        for (std::vector<int>::size_type j = 0; j < numeros.size() - i - 1; j++) { // O(n)
            comparaciones++; // O(1)
            if (numeros[j] > numeros[j + 1]) { // O(1)
                std::swap(numeros[j], numeros[j + 1]); // O(1)
            }
        }
    }
    return comparaciones; // Devuelve el total de comparaciones
}

// ordenaIntercambio que ordena el vector por referencia y devuelve el número de comparaciones
int ordenaIntercambio(std::vector<int>& numeros) {
    int comparaciones = 0; // Inicializa comparaciones en 0
    for (std::vector<int>::size_type i = 0; i < numeros.size() - 1; i++) { // O(n)
        for (std::vector<int>::size_type j = i + 1; j < numeros.size(); j++) { // O(n)
            comparaciones++; // O(1)
            if (numeros[i] > numeros[j]) { // O(1)
                std::swap(numeros[i], numeros[j]); // O(1)
            }
        }
    }
    return comparaciones; // Devuelve el total de comparaciones
}

// ordenaMerge que ordena el vector por referencia y devuelve el número de comparaciones sin usar algorithm
int ordenaMerge(std::vector<int>& numeros) {
    int comparaciones = 0; // Inicializa comparaciones en 0
    if (numeros.size() > 1) { // O(1)
        int mid = numeros.size() / 2; // O(1)
        std::vector<int> left(numeros.begin(), numeros.begin() + mid); // O(n)
        std::vector<int> right(numeros.begin() + mid, numeros.end()); // O(n)
        comparaciones += ordenaMerge(left); // O(n log n)
        comparaciones += ordenaMerge(right); // O(n log n)
        std::vector<int>::size_type i = 0; // O(1)
        std::vector<int>::size_type j = 0; // O(1)
        std::vector<int>::size_type k = 0; // O(1)
        while (i < left.size() && j < right.size()) { // O(n)
            comparaciones++; // O(1)
            if (left[i] <= right[j]) { // O(1)
                numeros[k] = left[i]; // O(1)
                i++; // O(1)
            } else {
                numeros[k] = right[j]; // O(1)
                j++; // O(1)
            }
            k++; // O(1)
        }
        while (i < left.size()) { // O(n)
            numeros[k] = left[i]; // O(1)
            i++; // O(1)
            k++; // O(1)
        }
        while (j < right.size()) { // O(n)
            numeros[k] = right[j]; // O(1)
            j++; // O(1)
            k++; // O(1)
        }
    }
    return comparaciones; // Devuelve el total de comparaciones
}

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

// busquedaSecuencial que busca el dato en el vector, devuelve la posición del dato y el número de iteraciones por referencia sin usar algorithm
int busquedaSecuencial(std::vector<int>& numeros, int dato, int& iteraciones, int& comparaciones) {
    iteraciones = 0; // Inicializa iteraciones en 0
    for (std::vector<int>::size_type i = 0; i < numeros.size(); i++) { // O(n)
        iteraciones++; // O(1)
        comparaciones++; // O(1)
        if (numeros[i] == dato) { // O(1)
            return i; // O(1)
        }
    }
    return -1; // O(1)
}


// main que lee el input de un arvhibo de texto, el primer número es el tamaño del vector, despues leera el vector hasta llenarlo y los ultimos datos son los datos a buscar. En una linea vendran la cantidad de comparaciones que arrojó el ordenamiento de intercambio, el ordenamiento de burbuja y el ordenamiento de MergeSort, separados por un espacio  Después vendrán q lineas (una por cada consultal con el formato de posición, cantidad de comparaciones por búsqueda secuencial y cantidad de comparaciones por busqueda binaria.
int main() {
    std::ifstream file("input/in.txt"); // Abre el archivo de texto
    std::string line;

    // first line is the number of elements that vector contains
    std::getline(file, line);
    int numeroDeElementos = std::stoi(line);

    std::vector<int> numeros;
    for (int i = 0; i < numeroDeElementos; i++){
        std::getline(file, line);
        numeros.push_back(std::stoi(line));
    }

    int comparacionesBurbuja = ordenaBurbuja(numeros); // O(n^2)
    int comparacionesIntercambio = ordenaIntercambio(numeros); // O(n^2)
    int comparacionesMerge = ordenaMerge(numeros); // O(n log n)
    std::cout << comparacionesIntercambio << " " << comparacionesBurbuja << " " << comparacionesMerge << std::endl; // O(1)
    int q; // Inicializa q
    
    while(std::getline(file, line)) { // O(q)
        q = std::stoi(line); // Lee q
        int iteracionesSecuencial; // Inicializa iteracionesSecuencial
        int comparacionesSecuencial; // Inicializa comparacionesSecuencial
        int posicionSecuencial = busquedaSecuencial(numeros, q, iteracionesSecuencial, comparacionesSecuencial); // O(n)
        int iteracionesBinaria; // Inicializa iteracionesBinaria
        int posicionBinaria = busquedaSecuencial(numeros, q, iteracionesBinaria); // O(log n)
        std::cout << posicionSecuencial << " " << iteracionesSecuencial << " " << comparacionesSecuencial << " " << iteracionesBinaria << std::endl; // O(1)
    }

    //return 0; // O(1)
}