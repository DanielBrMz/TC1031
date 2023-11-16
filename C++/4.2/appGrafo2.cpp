#include "Grafo/Grafo.h"
#include <vector>

/*
    Este programa crea cuatro grafos y verifica si son árboles y si son bipartitos.
    El programa implementa la clase Grafo, que se encuentra en la carpeta Grafo.
    Este grafo se forma a partir de una matriz de adyacencia y una lista de adyacencia.
*/

/*
    Complejidad temporal:
        - Grafo (constructor): O(V^2)
        - loadGraph: O(V + E)
        - addEdge: O(1)
        - printGraph: O(V^2)
        - isTree: O(V + E)
        - isCyclicUtil: O(V + E)
        - topologicalSort: O(V + E)
        - topologicalSortUtil: O(V + E)
        - bipartiteGraph: O(V + E)
        - isBipartiteUtil: O(V + E)
    Complejidad espacial:
        - Grafo (constructor): O(V^2)
        - loadGraph: O(V + E)
        - addEdge: O(1)
        - printGraph: O(V^2)
        - isTree: O(V)
        - isCyclicUtil: O(V)
        - topologicalSort: O(V)
        - topologicalSortUtil: O(V)
        - bipartiteGraph: O(V)
        - isBipartiteUtil: O(V)

        Autor: Daniel Alfredo Barreras Meraz
        Matricula: A01254805
        Fecha: 12/11/2023
*/

int main() {
    // Crear el primer grafo (árbol y bipartito)
    // 0---1   2
    //     |   |
    //     3---4
    int numVertices1 = 5;
    std::vector<std::pair<int, int>> arcos1 = {{0, 1}, {1, 3}, {3, 4}, {4, 2}};
    Grafo g1(numVertices1);
    g1.loadGraph(numVertices1, arcos1.size(), arcos1);
    g1.printGraph();
    std::cout << "El grafo 1 es un árbol: " << (g1.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 1 es bipartito: " << (g1.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 1: ";
    g1.topologicalSort();
    std::cout << "\n";

    // Crear el segundo grafo (no árbol y no bipartito)
    // 0---1---2
    // |       |
    // 3-------4
    int numVertices2 = 5;
    std::vector<std::pair<int, int>> arcos2 = {{0, 1}, {1, 2}, {2, 4}, {4, 3}, {3, 0}};
    Grafo g2(numVertices2);
    g2.loadGraph(numVertices2, arcos2.size(), arcos2);
    g2.printGraph();
    std::cout << "El grafo 2 es un árbol: " << (g2.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 2 es bipartito: " << (g2.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 2: ";
    g2.topologicalSort();
    std::cout << "\n";

    // Crear el tercer grafo (no árbol y bipartito)
    // 0---1---2
    // |   |   |
    // 3---4---5
    int numVertices3 = 6;
    std::vector<std::pair<int, int>> arcos3 = {{0, 1}, {1, 2}, {0, 3}, {1, 4}, {2, 5}, {3, 4}, {4, 5}};
    Grafo g3(numVertices3);
    g3.loadGraph(numVertices3, arcos3.size(), arcos3);
    g3.printGraph();
    std::cout << "El grafo 3 es un árbol: " << (g3.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 3 es bipartito: " << (g3.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 3: ";
    g3.topologicalSort();
    std::cout << "\n";

    // Crear el cuarto grafo (no árbol y bipartito)
    // 0---1
    // |   |
    // 2---3---4
    //     |   |
    //     5---6
    int numVertices4 = 7;
    std::vector<std::pair<int, int>> arcos4 = {{0, 1}, {1, 3}, {0, 2}, {2, 3}, {3, 4}, {3, 5}, {4, 6}, {5, 6}};
    Grafo g4(numVertices4);
    g4.loadGraph(numVertices4, arcos4.size(), arcos4);
    g4.printGraph();
    std::cout << "El grafo 4 es un árbol: " << (g4.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 4 es bipartito: " << (g4.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 4: ";
    g4.topologicalSort();
    std::cout << "\n";

    return 0;
}
