#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

class Grafo {
private:
    int V; // Número de vértices
    std::vector<std::vector<int>> matrizAdj; // Matriz de adyacencia
    std::map<int, std::list<int>> listaAdj; // Lista de adyacencia

    // Función auxiliar para DFS
    void DFSUtil(int v, std::vector<bool>& visited);

public:
    // Constructor
    Grafo(int V);

    // Función para cargar el grafo
    void loadGraph(int n, int m, std::vector<std::pair<int, int>>& edges);

    // Función para añadir una arista al grafo
    void addEdge(int v, int w);

    // Función para imprimir el grafo
    void printGraph();

    // Función para realizar un recorrido DFS
    void DFS(int inicio);

    // Función para realizar un recorrido BFS
    void BFS(int inicio);
};

#endif // GRAPH_H
