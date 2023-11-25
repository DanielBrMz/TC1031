#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Grafo {
private:
    map<string, vector<string>> adjList; // Lista de adyacencia para representar el grafo

public:
    void addEdge(string u, string v); // Añade una arista al grafo
    int unreachablePorts(string start, int MNP); // Calcula el número de puertos no alcanzables
};

#endif // GRAFO_H
