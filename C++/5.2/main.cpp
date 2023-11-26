#include "HashTable/HashTable.h"
#include <iostream>
#include <fstream>

int main() {
    for (int t = 1; t <= 4; ++t) {
        std::ifstream archivoEntrada("input" + std::to_string(t) + ".txt");
        if (!archivoEntrada) {
            std::cerr << "No se pudo abrir el archivo " << t << std::endl;
            return 1;
        }
        HashTable tablaHash;
        int m, n;
        archivoEntrada >> m >> n;
        for (int i = 0; i < m; ++i) {
            std::string palabra;
            int valor;
            archivoEntrada >> palabra >> valor;
            tablaHash.insert(palabra, valor);
        }
        archivoEntrada.ignore();  // Ignora el salto de línea después del último valor
        std::cout << "Caso de prueba " << t << ":" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::string descripcionPuesto, linea;
            while (std::getline(archivoEntrada, linea) && linea != ".") {
                descripcionPuesto += linea + " ";
            }
            int salario = tablaHash.calculate_salary(descripcionPuesto);
            std::cout << salario << std::endl;
        }
        std::cout << std::endl;
        archivoEntrada.close();
    }
    return 0;
}
