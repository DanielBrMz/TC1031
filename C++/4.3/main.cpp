#include <iostream>
#include <fstream>
#include "Grafo/Grafo.h"

/*
  Este programa utiliza la clase Grafo para resolver el problema de la siguiente manera:
    - Para cada caso de prueba:
        - Lee el número de conexiones
        - Lee las conexiones
        - Lee el número de consultas
        - Para cada consulta:
        - Lee el puerto inicial y el MNP
        - Calcula e imprime el número de puertos no alcanzables
  Se utiliza la estructura de datos Grafo para representar el grafo de conexiones y la función unreachablePorts para calcular el número de puertos no alcanzables.
    Complejidad Temporal de algoritmos utilizados:
        - addEdge: O(1)
        - unreachablePorts (BFS): O(V + E)
    Complejidad Espacial de algoritmos utilizados:
        - addEdge: O(1)
        - unreachablePorts: O(V)
    Donde V es el número de vértices (puertos) y E es el número de aristas (conexiones)
*/

/*
  Autor: Daniel Alfredo Barreras Meraz
  Matrícula: A01254805
  Fecha: 13 de noviembre de 2023
*/

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
