#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "ordenamiento/OrdenaBurbuja.h"
#include "ordenamiento/OrdenaIntercambio.h"
#include "ordenamiento/OrdenaMerge.h"
#include "busqueda/BusquedaSecuencial.h"
#include "busqueda/BusquedaBinaria.h"

// Casos de prueba
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
        int posicionSecuencial = busquedaSecuencial(numeros, q, iteracionesSecuencial); // O(n)
        int iteracionesBinaria; // Inicializa iteracionesBinaria
        int posicionBinaria = busquedaBinaria(numeros, q, iteracionesBinaria); // O(log n)
        std::cout << posicionSecuencial << " " << iteracionesSecuencial << " " << iteracionesBinaria << std::endl; // O(1)
    }

    //return 0; // O(1)
}