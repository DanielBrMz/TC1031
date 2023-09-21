#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Buque.h"

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
    ordenamientoMerge(buques, 0, buques.size() - 1);

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
