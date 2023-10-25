#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "PriorityQueue/priority_queue.h"

int main() {
    for (int i = 1; i <= 4; i++) {
        std::stringstream ss;
        ss << "input" << i << ".txt";
        std::string filename = ss.str();

        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "No se pudo abrir el archivo " << filename << std::endl;
            continue;
        }

        int N;
        inFile >> N;

        priority_queue pq;
        for (int j = 0; j < N; j++) {
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

        std::cout << "Total de comparaciones para " << filename << ": " << totalComparisons << std::endl;

        inFile.close();
    }

    return 0;
}
