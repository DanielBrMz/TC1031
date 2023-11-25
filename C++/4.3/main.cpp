#include <iostream>
#include <fstream>
#include "Grafo/Grafo.h"

void processFile(std::ifstream& inputFile, int i) {
    if (!inputFile.is_open()) {
        std::cout << "Unable to open file input" + std::to_string(i) + ".txt" << std::endl;
        return;
    }

    std::cout << "Caso de prueba " << i << ":" << std::endl;

    Grafo grafo;
    int NC, NQ;
    std::string u, v;

    inputFile >> NC; // Lee el número de conexiones
    for (int j = 0; j < NC; j++) { // Lee las conexiones
        inputFile >> u >> v;
        grafo.addEdge(u, v);
    }

    inputFile >> NQ; // Lee el número de consultas
    for (int j = 0; j < NQ; j++) { // Realiza las consultas
        int MNP;
        inputFile >> u >> MNP;

        // Calcula e imprime el número de puertos no alcanzables
        int unreachable = grafo.unreachablePorts(u, MNP);
        std::cout << "Case " << j+1 << ": " << unreachable << " ports not reachable from port " << u << " with MNP = " << MNP << "." << std::endl;
    }

    std::cout << std::endl;

    inputFile.close(); // Cierra el archivo de entrada
}

int main() {
    for (int i = 1; i <= 4; i++) { // Para cada archivo de entrada
        std::ifstream inputFile("input" + std::to_string(i) + ".txt"); // Abre el archivo de entrada
        processFile(inputFile, i);
    }

    return 0;
}
