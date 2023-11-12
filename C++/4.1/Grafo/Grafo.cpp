#include "Grafo.h"

Grafo::Grafo(int V) {
    this->V = V;
    matrizAdj.resize(V, std::vector<int>(V, 0));
}

void Grafo::loadGraph(int n, int m, std::vector<std::pair<int, int>>& edges) {
    this->V = n;
    matrizAdj.resize(V, std::vector<int>(V, 0));
    for (auto edge : edges) {
        int v = edge.first;
        int w = edge.second;
        matrizAdj[v][w] = 1;
        matrizAdj[w][v] = 1;
        listaAdj[v].push_back(w);
        listaAdj[w].push_back(v);
    }
}

void Grafo::addEdge(int v, int w) {
    matrizAdj[v][w] = 1;
    matrizAdj[w][v] = 1;
    listaAdj[v].push_back(w);
    listaAdj[w].push_back(v);
}

void Grafo::DFS(int inicio) {
    std::vector<bool> visited(V, false);
    DFSUtil(inicio, visited);
}

void Grafo::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";

    for (int i = 0; i < V; i++) {
        if (matrizAdj[v][i] == 1 && !visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void Grafo::BFS(int inicio) {
    std::vector<bool> visited(V, false);
    std::queue<int> queue;

    visited[inicio] = true;
    queue.push(inicio);

    while (!queue.empty()) {
        int v = queue.front();
        std::cout << v << " ";
        queue.pop();

        for (auto i : listaAdj[v]) {
            if (!visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}
