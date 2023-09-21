#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Buque.h"

/*
    * Este programa utiliza los algoritmos de ordenamiento Merge Sort y búsqueda binaria 
    * implementados en el archivo OrdenamientoBuques.cpp y BusquedaBuques.cpp
    * para ordenar y buscar buques en un archivo de entrada.
    * 
    * El programa lee un archivo de entrada indicado por el usuario con el siguiente formato:
    * - Fecha (formato dd/mm/aaaa)
    * - Hora (formato hh:mm)
    * - Punto de entrada (un caracter)
    * - UBI (formato XXX-NNNNNN-ZZ)
    * 
    * El programa ordena los buques por fecha y hora de entrada, y luego realiza una búsqueda
    * binaria en los buques para encontrar los buques de una serie indicada por el usuario.
    * 
    * El programa imprime los buques de la serie indicada por el usuario en la consola.
    * 
    * Complejidad temporal:
    * Ordenamiento: O(n log n)
    * Búsqueda: O(log n)
    * 
    * Complejidad espacial:
    * Ordenamiento: O(n)
    * Búsqueda: O(1)
    * 
    * Nota: El programa espera que el archivo de texto tenga el formato correcto.
    * 
    * Autor: Daniel Alfredo Barreras Meraz
    * Matrícula: A01254805
    * Fecha: 21 de septiembre de 2023
*/

/*
    Pasos para compilar y ejecutar uel programa tilizando make:
    Compilar: make
    Ejecutar: make run
*/

int main() {
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo de entrada: ";
    std::cin >> nombreArchivo;

    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::vector<Buque> buques;
    Buque buque;

    // Leer datos del archivo
    while (archivo >> buque.fecha >> buque.hora >> buque.puntoEntrada >> buque.ubi) {
        buques.push_back(buque);
    }

    // Ordenar buques usando Merge Sort
    ordenamientoBuques(buques, 0, buques.size() - 1);

    std::string serieABuscar;
    std::cout << "Ingrese la serie a buscar (los primeros tres caracteres del UBI): ";
    std::cin >> serieABuscar;

    // Realizar una búsqueda binaria en los buques
    if (buscarBuque(buques, serieABuscar)) {
        std::cout << "Buques de la serie " << serieABuscar << ":" << std::endl;
        for (const Buque& b : buques) {
            if (b.ubi.substr(0, 3) == serieABuscar) {
                std::cout << b.fecha << " " << b.hora << " " << b.puntoEntrada << " " << b.ubi << std::endl;
            }
        }
    } else {
        std::cout << "No se encontraron buques de la serie " << serieABuscar << "." << std::endl;
    }

    return 0;
}
