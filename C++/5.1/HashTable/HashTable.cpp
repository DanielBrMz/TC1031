#include "HashTable.h"
#include <cmath>

HashTable::HashTable(size_t size) : table(size) {}

size_t HashTable::hash(int key) {
    return key % table.size();
}

void HashTable::insert(int key) {
    size_t idx = hash(key);
    table[idx].push_back(key);
}

bool HashTable::find(int key) {
    size_t idx = hash(key);
    for (int i : table[idx]) {
        if (i == key) {
            return true;
        }
    }
    return false;
}

void HashTable::quadratic(int key) {
    size_t idx = hash(key);
    if (table[idx].empty()) {
        table[idx].push_back(key);
    } else {
        size_t i = 1;
        while (!table[(idx + i*i) % table.size()].empty()) {
            i++;
        }
        table[(idx + i*i) % table.size()].push_back(key);
    }
}

void HashTable::chain(int key) {
    size_t idx = hash(key);
    table[idx].push_back(key);
}
