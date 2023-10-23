#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue/priority_queue.h"

int main() {
    std::ifstream inFile("input1.txt");
    if (!inFile) {
        std::cerr << "No se pudo abrir el archivo input1.txt" << std::endl;
        return 1;
    }

    int N;
    inFile >> N;

    priority_queue pq;
    for (int i = 0; i < N; i++) {
        int size;
        inFile >> size;
        pq.push(size);
    }

    int totalComparisons = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        totalComparisons += first + second;
        pq.push(first + second);
    }

    std::cout << totalComparisons << std::endl;

    inFile.close();

    return 0;
}
