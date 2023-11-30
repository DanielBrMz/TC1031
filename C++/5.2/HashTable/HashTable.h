#include <vector>
#include <list>
#include <string>

class HashTable {
private:
    std::vector<std::list<std::pair<std::string, int>>> tabla;  // Tabla hash que almacena pares de palabras y valores
    int M;  // Tamaño de la tabla hash, un número primo grande

    // Función hash que calcula el valor hash de una palabra
    int hash(std::string word);

public:
    // Constructor de la clase HashTable
    HashTable();

    // Función para insertar una palabra y su valor asociado en la tabla hash
    void insertar(std::string word, int value);

    // Función para calcular el salario basado en la descripción del trabajo
    int calcularSalario(std::string job_description);
};
