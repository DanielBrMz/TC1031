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

    return 0;
}
