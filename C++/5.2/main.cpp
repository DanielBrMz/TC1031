#include "HashTable/HashTable.h"
#include <iostream>
#include <fstream>

int main() {
    HashTable hash_table;
    std::ifstream input_file("input1.txt");
    if (!input_file) {
        std::cerr << "No se pudo abrir el archivo input1.txt" << std::endl;
        return 1;
    }
    int m, n;
    input_file >> m >> n;
    for (int i = 0; i < m; ++i) {
        std::string word;
        int value;
        input_file >> word >> value;
        hash_table.insert(word, value);
    }
    input_file.ignore();  // Ignora el salto de línea después del último valor
    for (int i = 0; i < n; ++i) {
        std::string job_description, line;
        while (std::getline(input_file, line) && line != ".") {
            job_description += line + " ";
        }
        int salary = hash_table.calculate_salary(job_description);
        std::cout << salary << std::endl;
    }
    input_file.close();
    return 0;
}
