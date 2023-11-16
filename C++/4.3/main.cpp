#include <fstream>
#include <vector>
#include <utility>
#include "Grafo/Grafo.h"

int main() {
    std::ifstream file("input1.txt");
    if (!file) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }

    int num_conexiones;
    file >> num_conexiones;

    std::vector<std::pair<int, int>> conexiones(num_conexiones);
    for (int i = 0; i < num_conexiones; ++i) {
        file >> conexiones[i].first >> conexiones[i].second;
    }

    Grafo grafo(num_conexiones);
    grafo.loadGraph(num_conexiones, num_conexiones, conexiones);

    int num_consultas;
    file >> num_consultas;

    for (int i = 0; i < num_consultas; ++i) {
        int puerto_inicio, MNP;
        file >> puerto_inicio >> MNP;
        grafo.DFS_MNP(puerto_inicio, MNP);
    }

    return 0;
}
