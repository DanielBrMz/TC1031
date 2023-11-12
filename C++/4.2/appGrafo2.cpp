#include "Grafo.h"
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
    std::cout << "El grafo 1 es un árbol: " << (g1.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 1 es bipartito: " << (g1.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 1: ";
    g1.topologicalSort();
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
    std::cout << "El grafo 2 es un árbol: " << (g2.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 2 es bipartito: " << (g2.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 2: ";
    g2.topologicalSort();
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
    std::cout << "El grafo 3 es un árbol: " << (g3.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 3 es bipartito: " << (g3.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 3: ";
    g3.topologicalSort();
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
    std::cout << "El grafo 4 es un árbol: " << (g4.isTree() ? "Sí" : "No") << std::endl;
    std::cout << "El grafo 4 es bipartito: " << (g4.bipartiteGraph() ? "Sí" : "No") << std::endl;
    std::cout << "Orden topológico del grafo 4: ";
    g4.topologicalSort();
    std::cout << "\n";

    return 0;
}
