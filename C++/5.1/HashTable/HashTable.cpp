#include "HashTable.h"
#include <cmath>

// Constructor: Complejidad O(n), donde n es el tamaño de la tabla.
HashTable::HashTable(size_t size) : table(size) {} // O(n)

// Función hash: Complejidad O(1), ya que solo realiza una operación de módulo.
size_t HashTable::hash(int key) { // O(1)
    return key % table.size(); // O(1)
}

// Función insert: Complejidad O(1), ya que solo realiza una operación de inserción en la lista.
void HashTable::insert(int key) { // O(1)
    size_t idx = hash(key); // O(1)
    table[idx].push_back(key); // O(1)
}

// Función find: Complejidad O(n), donde n es el número de elementos en la lista en la posición dada.
// En el peor de los casos, podría tener que recorrer toda la lista.
bool HashTable::find(int key) { // O(n)
    size_t idx = hash(key); // O(1)
    for (int i : table[idx]) { // O(n)
        if (i == key) { // O(1)
            return true; // O(1)
        }
    }
    return false; // O(1)
}

// Función quadratic: Complejidad O(n), donde n es el tamaño de la tabla.
// En el peor de los casos, podría tener que recorrer toda la tabla si todos los espacios están ocupados.
void HashTable::quadratic(int key) { // O(n)
    size_t idx = hash(key); // O(1)
    if (table[idx].empty()) { // O(1)
        table[idx].push_back(key); // O(1)
    } else {
        size_t i = 1; // O(1)
        while (!table[(idx + i*i) % table.size()].empty()) { // O(n)
            i++; // O(1)
        }
        table[(idx + i*i) % table.size()].push_back(key); // O(1)
    }
}

// Función chain: Complejidad O(1), ya que solo realiza una operación de inserción en la lista.
void HashTable::chain(int key) { // O(1)
    size_t idx = hash(key); // O(1)
    table[idx].push_back(key); // O(1)
}
