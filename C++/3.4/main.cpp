#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "PriorityQueue/priority_queue.h"

/*
 Este programa utiliza un min_heap para implementar una priority queue
 El programa lee varios archivos de entrada con los casos de prueba
 los archivos de texto contienen un numero N que indica el numero de
 elementos que se deben insertar en la priority queue, seguido de N
 numeros que se insertaran en la priority queue.
 El programa puede realizar las funciones push, pop, top, empty y size
 y calcular el numero de comparaciones que se realizaron para insertar
 toodos los elementos en la priority queue.
*/

/*
 Complejidad temporal:
 - push: O(logN)
 - pop: O(logN)
 - top: O(1)
 - empty O(1)
 - size O(1)

 Autor: Daniel Alfredo Barreras Meraz
 Matricula: A01254805
 Fecha: 14 de octubre de 2023
*/

/*
 Compilacion:
    make
 Ejecucion:
    make run
*/

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
