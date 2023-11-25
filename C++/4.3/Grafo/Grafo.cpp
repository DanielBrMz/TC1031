#include "Grafo.h"

// Complejidad Temporal: O(1)
// Complejidad Espacial: O(1)
void Grafo::addEdge(string u, string v) { // Añade una arista al grafo
    listaAdy[u].push_back(v); // O(1)
    listaAdy[v].push_back(u); // O(1)
}

// Complejidad Temporal: O(V + E)
// Complejidad Espacial: O(V)
// Donde V es el número de vértices (puertos) y E es el número de aristas (conexiones)
int Grafo::unreachablePorts(string inicio, int MNP) { // Calcula el número de puertos no alcanzables
    map<string, bool> visitados; // Para llevar un registro de los puertos visitados, O(V) en espacio
    queue<pair<string, int>> cola; // Cola para la búsqueda en anchura (BFS), O(V) en espacio
    cola.push({inicio, MNP}); // Empieza desde el puerto inicial con el MNP dado, O(1)

    while (!cola.empty()) { // O(V) en tiempo
        string actual = cola.front().first; // O(1)
        int MNPrestante = cola.front().second; // O(1)
        cola.pop(); // O(1)

        if (!visitados[actual]) { // Si el puerto actual no ha sido visitado, O(log V) en tiempo
            visitados[actual] = true; // Marca el puerto como visitado, O(log V) en tiempo

            if (MNPrestante > 0) { // Si aún puede visitar más puertos, O(1)
                for (string vecino : listaAdy[actual]) { // Para cada puerto vecino, O(E) en tiempo
                    if (!visitados[vecino]) { // Si el puerto vecino no ha sido visitado, O(log V) en tiempo
                        cola.push({vecino, MNPrestante - 1}); // Añade el puerto vecino a la cola con el MNP disminuido en 1, O(1)
                    }
                }
            }
        }
    }

    // El número de puertos no alcanzables es el total de puertos menos los visitados
    return listaAdy.size() - visitados.size(); // O(1)
}
