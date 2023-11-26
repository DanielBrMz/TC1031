#include <vector>
#include <list>
#include <string>

class HashTable {
private:
    std::vector<std::list<std::pair<std::string, int>>> table;
    int M;  // Un número primo grande
    int hash(std::string word);

public:
    HashTable();
    void insert(std::string word, int value);
    int calculate_salary(std::string job_description);
};
