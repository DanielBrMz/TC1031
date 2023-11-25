// HashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>

class HashTable {
public:
    HashTable(size_t size);

    void insert(int key);
    bool find(int key);
    void quadratic(int key);
    void chain(int key);

private:
    std::vector<std::list<int>> table;

    size_t hash(int key);
};

#endif // HASHTABLE_H
