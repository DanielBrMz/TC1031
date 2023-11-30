#include "HashTable/HashTable.h"
#include <iostream>
#include <fstream>

/*
  Este programa utiliza la clase HashTable para calcular el salario de un trabajador basado en la descripción de su trabajo
  Utiliza la estructura de datos HashTable para representar la tabla de dispersión y el calcularSalario() utilizando el metodo de hashing por multiplicación y adición
  Funciona de la siguiente manera:
    - Lee el número de palabras en la tabla de dispersión y el número de descripciones de trabajo
    - Lee cada palabra y su valor asociado y las inserta en la tabla de dispersión
    - Lee cada descripción de trabajo y calcula el salario basado en la descripción del trabajo
    - Imprime el salario
  Complejidad temporal por metodo:
    - main(): O(T*(M + N*(L + M))), donde T es el número de casos de prueba, M es el tamaño de la tabla de dispersión, N es el número de palabras en la descripción del trabajo y L es la longitud promedio de las palabras
    - HashTable(): O(M), donde M es el tamaño de la tabla de dispersión
    - hash(): O(L), donde L es la longitud de la palabra
    - insertar(): O(L + M), donde L es la longitud de la palabra y M es el tamaño de la tabla de dispersión
    - calcularSalario(): O(N*(L + M)), donde N es el número de palabras en la descripción del trabajo, L es la longitud promedio de las palabras y M es el tamaño de la tabla de dispersión
  Complejidad espacial por metodo:
    - main(): O(1)
    - HashTable(): O(M), donde M es el tamaño de la tabla de dispersión
    - hash(): O(1)
    - insertar(): O(1)
    - calcularSalario(): O(1)
*/

int main() {

    // Lee el número de casos de prueba
    for (int t = 1; t <= 4; ++t) {
        std::ifstream archivoEntrada("input" + std::to_string(t) + ".txt");
        if (!archivoEntrada) {
            std::cerr << "No se pudo abrir el archivo " << t << std::endl;
            return 1;
        }
        HashTable tablaHash;
        int m, n;
        archivoEntrada >> m >> n;

        // Lee cada palabra y su valor asociado y las inserta en la tabla de dispersión
        for (int i = 0; i < m; ++i) {
            std::string palabra;
            int valor;
            archivoEntrada >> palabra >> valor;
            tablaHash.insertar(palabra, valor);
        }

        // Lee cada descripción de trabajo y calcula el salario basado en la descripción del trabajo
        archivoEntrada.ignore();  // Ignora el salto de línea después del último valor
        std::cout << "Caso de prueba " << t << ":" << std::endl;

        // Imprime el salario
        for (int i = 0; i < n; ++i) {
            std::string descripcionPuesto, linea;
            while (std::getline(archivoEntrada, linea) && linea != ".") {
                descripcionPuesto += linea + " ";
            }
            int salario = tablaHash.calcularSalario(descripcionPuesto);
            std::cout << salario << std::endl;
        }
        std::cout << std::endl;
        archivoEntrada.close();
    }
    return 0;
}