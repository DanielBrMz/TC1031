#include "HashTable.h"
#include <sstream>

// Constructor de la clase HashTable
// Complejidad en tiempo: O(1)
// Complejidad en espacio: O(M), donde M es el tamaño de la tabla
HashTable::HashTable() {
    M = 2003;  // Un número primo grande
    tabla.resize(M);  // Redimensiona la tabla al tamaño M. Tiempo: O(M), Espacio: O(M)
}

// Función hash
// Utiliza el método de hashing de multiplicación y adición
// Complejidad en tiempo: O(L), donde L es la longitud de la palabra
// Complejidad en espacio: O(1)
int HashTable::hash(std::string palabra) {
    int valor_hash = 0;
    for (char c : palabra) {  // O(L), recorre cada carácter de la palabra
        valor_hash = (valor_hash * 31 + c) % M;  // O(1), calcula el valor hash utilizando el método de hashing de multiplicación y adición
    }
    return valor_hash;  // O(1), devuelve el valor hash
}

// Función para insertar una palabra y su valor asociado en la tabla
// Complejidad en tiempo: O(L + M), donde L es la longitud de la palabra y M es el tamaño de la tabla
// Complejidad en espacio: O(1)
void HashTable::insertar(std::string palabra, int valor) {
    int h = hash(palabra);  // O(L), calcula el valor hash de la palabra
    for (auto it = tabla[h].begin(); it != tabla[h].end(); ++it) {  // O(M), recorre la lista en la posición h de la tabla
        if (it->first == palabra) {  // O(1), verifica si la palabra ya está en la lista
            it->second = valor;  // O(1), actualiza el valor asociado a la palabra
            return;  // O(1), termina la función
        }
    }
    tabla[h].push_back({palabra, valor});  // O(1), inserta la palabra y su valor en la lista si la palabra no estaba en la lista
}

// Función para calcular el salario basado en la descripción del trabajo
// Complejidad en tiempo: O(N*(L + M)), donde N es el número de palabras en la descripción del trabajo, L es la longitud promedio de las palabras y M es el tamaño de la tabla
// Complejidad en espacio: O(1)
int HashTable::calcularSalario(std::string descripcion_trabajo) {
    std::istringstream iss(descripcion_trabajo);  // O(1), crea un flujo de entrada a partir de la descripción del trabajo
    std::string palabra;  // O(1), almacena la palabra actual
    int salario = 0;  // O(1), almacena el salario total
    while (iss >> palabra) {  // O(N), recorre cada palabra en la descripción del trabajo
        int h = hash(palabra);  // O(L), calcula el valor hash de la palabra
        for (auto it = tabla[h].begin(); it != tabla[h].end(); ++it) {  // O(M), recorre la lista en la posición h de la tabla
            if (it->first == palabra) {  // O(1), verifica si la palabra está en la lista
                salario += it->second;  // O(1), suma el valor asociado a la palabra al salario total
                break;  // O(1), termina el bucle si la palabra está en la lista
            }
        }
    }
    return salario;  // O(1), devuelve el salario total
}
