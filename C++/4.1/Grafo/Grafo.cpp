#include "Grafo.h"

// Constructor: Tiempo O(V^2), Espacio O(V^2)
Grafo::Grafo(int V) {
    this->V = V; // O(1)
    matrizAdj.resize(V, std::vector<int>(V, 0)); // O(V^2)
}

// loadGraph: Tiempo O(E), Espacio O(V + E)
void Grafo::loadGraph(int n, int m, std::vector<std::pair<int, int>>& edges) {
    this->V = n; // O(1)
    matrizAdj.resize(V, std::vector<int>(V, 0)); // O(V^2)
    for (auto edge : edges) { // O(E)
        int v = edge.first;
        int w = edge.second;
        matrizAdj[v][w] = 1; // O(1)
        matrizAdj[w][v] = 1; // O(1)
        listaAdj[v].push_back(w); // O(1)
        listaAdj[w].push_back(v); // O(1)
    }
}

// addEdge: Tiempo O(1), Espacio O(1)
void Grafo::addEdge(int v, int w) {
    matrizAdj[v][w] = 1; // O(1)
    matrizAdj[w][v] = 1; // O(1)
    listaAdj[v].push_back(w); // O(1)
    listaAdj[w].push_back(v); // O(1)
}

// printGraph: Tiempo O(V^2 + E), Espacio O(1)
void Grafo::printGraph(){
    std::cout << "Matriz de adyacencia:\n"; // O(1)
    for (int i = 0; i < V; i++) { // O(V)
        std::cout << i << ": "; // O(1)
        for (int j = 0; j < V; j++) { // O(V)
            std::cout << matrizAdj[i][j] << " "; // O(1)
        }
        std::cout << "\n"; // O(1)
    }

    std::cout << "\nLista de adyacencia:\n"; // O(1)
    for (auto i : listaAdj) { // O(V)
        std::cout << i.first << ": "; // O(1)
        for (auto j : i.second) { // O(E/V)
            std::cout << j << " "; // O(1)
        }
        std::cout << "\n"; // O(1)
    }
}

// DFS: Tiempo O(V + E), Espacio O(V)
void Grafo::DFS(int inicio) {
    std::vector<bool> visited(V, false); // O(V)
    DFSUtil(inicio, visited); // O(V + E)
}

// DFSUtil: Tiempo O(V + E), Espacio O(V)
void Grafo::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true; // O(1)
    std::cout << v << " "; // O(1)

    for (int i = 0; i < V; i++) { // O(V)
        if (matrizAdj[v][i] == 1 && !visited[i]) { // O(1)
            DFSUtil(i, visited); // O(V + E)
        }
    }
}

// BFS: Tiempo O(V + E), Espacio O(V)
void Grafo::BFS(int inicio) {
    std::vector<bool> visited(V, false); // O(V)
    std::queue<int> queue; // O(1)

    visited[inicio] = true; // O(1)
    queue.push(inicio); // O(1)

    while (!queue.empty()) { // O(V)
        int v = queue.front(); // O(1)
        std::cout << v << " "; // O(1)
        queue.pop(); // O(1)

        for (auto i : listaAdj[v]) { // O(E/V)
            if (!visited[i]) { // O(1)
                queue.push(i); // O(1)
                visited[i] = true; // O(1)
            }
        }
    }
}
