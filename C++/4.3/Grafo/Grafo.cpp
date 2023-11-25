#include "Grafo.h"

void Grafo::addEdge(string u, string v) { // Añade una arista al grafo
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int Grafo::unreachablePorts(string start, int MNP) { // Calcula el número de puertos no alcanzables
    map<string, bool> visited; // Para llevar un registro de los puertos visitados
    queue<pair<string, int>> q; // Cola para la búsqueda en anchura (BFS)
    q.push({start, MNP}); // Empieza desde el puerto inicial con el MNP dado

    while (!q.empty()) {
        string current = q.front().first;
        int remainingMNP = q.front().second;
        q.pop();

        if (!visited[current]) {
            visited[current] = true;

            if (remainingMNP > 0) { // Si aún puede visitar más puertos
                for (string neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        q.push({neighbor, remainingMNP - 1});
                    }
                }
            }
        }
    }

    // El número de puertos no alcanzables es el total de puertos menos los visitados
    return adjList.size() - visited.size();
}
