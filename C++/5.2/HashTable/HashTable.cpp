#include "HashTable.h"
#include <sstream>

HashTable::HashTable() {
    M = 2003;  // Un número primo grande
    table.resize(M);
}

int HashTable::hash(std::string word) {
    int hash_value = 0;
    for (char c : word) {
        hash_value = (hash_value * 31 + c) % M;
    }
    return hash_value;
}

void HashTable::insert(std::string word, int value) {
    int h = hash(word);
    for (auto it = table[h].begin(); it != table[h].end(); ++it) {
        if (it->first == word) {
            it->second = value;
            return;
        }
    }
    table[h].push_back({word, value});
}

int HashTable::calculate_salary(std::string job_description) {
    std::istringstream iss(job_description);
    std::string word;
    int salary = 0;
    while (iss >> word) {
        int h = hash(word);
        for (auto it = table[h].begin(); it != table[h].end(); ++it) {
            if (it->first == word) {
                salary += it->second;
                break;
            }
        }
    }
    return salary;
}
