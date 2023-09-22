#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "ordenamiento/OrdenaBurbuja.h"
#include "ordenamiento/OrdenaIntercambio.h"
#include "ordenamiento/OrdenaMerge.h"
#include "busqueda/BusquedaSecuencial.h"
#include "busqueda/BusquedaBinaria.h"

/* 
 * Este programa  utiliza y prueba los algoritmos de ordenamiento y búsqueda
 * implementados en los archivos de cabecera OrdenaBurbuja.h, OrdenaIntercambio.h,
 * OrdenaMerge.h, BusquedaSecuencial.h y BusquedaBinaria.h.
 * 
 * El programa lee un archivo de texto llamado in.txt que contiene:
 * - La primera línea contiene un número entero que indica la cantidad de elementos
 *   que contiene el vector.
 * - Las siguientes líneas contienen los elementos del vector.
 * - La última línea contiene un número entero que indica la cantidad de elementos
 *   que se van a buscar en el vector.
 * - Las siguientes líneas contienen los elementos que se van a buscar en el vector.
 * 
 * El programa imprime en la salida estándar:
 * - El número de comparaciones realizadas por el algoritmo de ordenamiento burbuja.
 * - El número de comparaciones realizadas por el algoritmo de ordenamiento por intercambio.
 * - El número de comparaciones realizadas por el algoritmo de ordenamiento merge.
 * - La posición del elemento buscado en el vector, si se encontró.
 * - El número de iteraciones realizadas por el algoritmo de búsqueda secuencial.
 * - El número de iteraciones realizadas por el algoritmo de búsqueda binaria.
 * 
 * Complejidad temporal:
 * - OrdenaBurbuja: O(n^2)
 * - OrdenaIntercambio: O(n^2)
 * - OrdenaMerge: O(n log n)
 * - BusquedaSecuencial: O(n)
 * - BusquedaBinaria: O(log n)
 * 
 * Complejidad espacial:
 * - OrdenaBurbuja: O(1)
 * - OrdenaIntercambio: O(1)
 * - OrdenaMerge: O(n)
 * - BusquedaSecuencial: O(1)
 * - BusquedaBinaria: O(1)
 * 
 * Nota: El programa espera que el archivo de texto tenga el formato correcto.
 
 * Autor: Daniel Alfredo Barreras Meraz
 * Matrícula: A01254805
 * Fecha: 10 de septiembre de 2023
*/

// Para correr este programa en la terminal se debe ejecutar el siguiente comando: make

// Casos de prueba
int main() {
    std::ifstream file("input/in.txt"); // Abre el archivo de texto
    std::string line;

    // Lee el archivo de texto
    std::getline(file, line);
    int numeroDeElementos = std::stoi(line);

    std::vector<int> numeros;
    for (int i = 0; i < numeroDeElementos; i++){
        std::getline(file, line);
        numeros.push_back(std::stoi(line));
    }

    std::vector<int> originalNumeros = numeros; // Copia el vector original

    int comparacionesBurbuja = ordenaBurbuja(numeros); // O(n^2)
    numeros = originalNumeros; // Restaruar el vector original

    int comparacionesIntercambio = ordenaIntercambio(numeros); // O(n^2)
    numeros = originalNumeros; // Restaurar el vector original

    int comparacionesMerge = ordenaMerge(numeros); // O(n log n)
    
    std::cout << "Comparaciones intercambio, burbuja, merge:" << std::endl; // O(1)
    std::cout << comparacionesIntercambio << " " << comparacionesBurbuja << " " << comparacionesMerge << std::endl << std::endl; // O(1)
    
    std::getline(file, line);
    int q  = std::stoi(line); // Inicializa q
    
    std::cout << "Posicion, iteraciones secuencial, iteraciones binaria:" << std::endl; // O(1)
    for (int j = 0; j < q; j++) { // O(q)
        std::getline(file, line);
        int dato = std::stoi(line); // Lee q
        int iteracionesSecuencial; // Inicializa iteracionesSecuencial
        int posicionSecuencial = busquedaSecuencial(numeros, dato, iteracionesSecuencial); // O(n)
        int iteracionesBinaria; // Inicializa iteracionesBinaria
        busquedaBinaria(numeros, dato, iteracionesBinaria); // O(log n)
        std::cout << posicionSecuencial << " " << iteracionesSecuencial << " " << iteracionesBinaria << std::endl; // O(1)
    }

    return 0; // O(1)
}
