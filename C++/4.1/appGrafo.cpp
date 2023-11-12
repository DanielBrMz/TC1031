#include "Grafo/Grafo.h"
#include <vector>

/*
    Este programa crea dos grafos y realiza un recorrido DFS y BFS a partir de un nodo inicial.
    El programa implementa la clase Grafo, que se encuentra en la carpeta Grafo.
    Este grafo se forma a partir de una matriz de adyacencia y una lista de adyacencia.
*/

/*
    Complejidad temporal:
        - Grafo (constructor): O(V^2)
        - loadGraph: O(V + E)
        - addEdge: O(1)
        - printGraph: O(V^2)
        - DFS: O(V + E)
        - BFS: O(V + E)
    Complejidad espacial:
        - Grafo (constructor): O(V^2)
        - loadGraph: O(V + E)
        - addEdge: O(1)
        - printGraph: O(V^2)
        - DFS: O(V)
        - BFS: O(V)

        Autor: Daniel Alfredo Barreras Meraz
        Matricula: A01254805
        Fecha: 12/11/2023
*/

#include "Grafo/Grafo.h"
#include <vector>

int main() {
    // Crear el primer grafo
    // 0---1   2
    // |       |
    // 3---4---5
    // |   |   |
    // 6---7---8
    int numVertices1 = 9;
    std::vector<std::pair<int, int>> arcos1 = {{0, 1}, {3, 4}, {4, 5}, {6, 7}, {7, 8}, {0, 3}, {1, 4}, {2, 5}, {3, 6}, {4, 7}, {5, 8}};
    Grafo g1(numVertices1);
    g1.loadGraph(numVertices1, arcos1.size(), arcos1);
    g1.printGraph();
    std::cout << "Recorrido DFS a partir del nodo 0: ";
    g1.DFS(0);
    std::cout << "\nRecorrido BFS a partir del nodo 0: ";
    g1.BFS(0);

    std::cout << "\n";

    // Crear el segundo grafo
    // 0   1---2
    // |   |   |
    // 3---4---5
    //     |   |
    //     6---7
    int numVertices2 = 8;
    std::vector<std::pair<int, int>> arcos2 = {{0, 3}, {1, 2}, {1, 4}, {2, 5}, {4, 5}, {4, 6}, {5, 7}, {6, 7}};
    Grafo g2(numVertices2);
    g2.loadGraph(numVertices2, arcos2.size(), arcos2);
    g2.printGraph();
    std::cout << "Recorrido DFS a partir del nodo 0: ";
    g2.DFS(0);
    std::cout << "\nRecorrido BFS a partir del nodo 0: ";
    g2.BFS(0);

    std::cout << "\n";

    // Crear el tercer grafo
    // 0---1---2
    // |   |   |
    // 3---4---5
    int numVertices3 = 6;
    std::vector<std::pair<int, int>> arcos3 = {{0, 1}, {1, 2}, {0, 3}, {1, 4}, {2, 5}, {3, 4}, {4, 5}};
    Grafo g3(numVertices3);
    g3.loadGraph(numVertices3, arcos3.size(), arcos3);
    g3.printGraph();
    std::cout << "Recorrido DFS a partir del nodo 0: ";
    g3.DFS(0);
    std::cout << "\nRecorrido BFS a partir del nodo 0: ";
    g3.BFS(0);

    std::cout << "\n";

    // Crear el cuarto grafo
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
    std::cout << "Recorrido DFS a partir del nodo 0: ";
    g4.DFS(0);
    std::cout << "\nRecorrido BFS a partir del nodo 0: ";
    g4.BFS(0);

    return 0;
}
