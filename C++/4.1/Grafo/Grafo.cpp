#include "Grafo.h"

Grafo::Grafo(int V) {
    this->V = V;
    adjMatrix.resize(V, std::vector<int>(V, 0));
}

void Grafo::loadGraph(int n, int m, std::vector<std::pair<int, int>>& edges) {
    this->V = n;
    adjMatrix.resize(V, std::vector<int>(V, 0));
    for (auto edge : edges) {
        int v = edge.first;
        int w = edge.second;
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1;
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }
}

void Grafo::addEdge(int v, int w) {
    adjMatrix[v][w] = 1;
    adjMatrix[w][v] = 1;
    adjList[v].push_back(w);
    adjList[w].push_back(v);
}

void Grafo::DFS(int start) {
    std::vector<bool> visited(V, false);
    DFSUtil(start, visited);
}

void Grafo::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << v << " ";

    for (int i = 0; i < V; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void Grafo::BFS(int start) {
    std::vector<bool> visited(V, false);
    std::queue<int> queue;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int v = queue.front();
        std::cout << v << " ";
        queue.pop();

        for (auto i : adjList[v]) {
            if (!visited[i]) {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}
