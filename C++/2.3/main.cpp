#include "iostream"
#include "fstream"
#include <map>
#include "ListaEnlazada.h"
#include "Barco.h"

int main(){
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo de entrada: ";
    std::cin >> nombreArchivo;

    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    LinkedList mediterraneo, rojo;
    std::string fecha, hora, punto_entrada, UBI;

    while (archivo >> fecha >> hora >> punto_entrada >> UBI) {
        Barco* barco = new Barco(fecha, hora, punto_entrada, UBI);
        if (punto_entrada == "M")
            mediterraneo.create(barco);
        else if (punto_entrada == "R")
            rojo.create(barco);
    }
    

    mediterraneo.mergeSort(mediterraneo.getHead());
    rojo.mergeSort(rojo.getHead());

    std::string serie;
    std::cout << "Introduce la serie a buscar: ";
    std::cin >> serie;

    // Aquí iría tu código para desplegar mes por mes la cantidad de entrada de buques de esa serie...

    std::map<std::string, int> conteoM = {{"jan", 0}, {"feb", 0}, {"mar", 0}, {"apr", 0}, {"may", 0}, {"jun", 0},
                                          {"jul", 0}, {"ago", 0}, {"sep", 0}, {"oct", 0}, {"nov", 0}, {"dec", 0}};
    std::map<std::string, int> conteoR = {{"jan", 0}, {"feb", 0}, {"mar", 0}, {"apr", 0}, {"may", 0}, {"jun", 0},
                                          {"jul", 0}, {"ago", 0}, {"sep", 0}, {"oct", 0}, {"nov", 0}, {"dec", 0}};

    for (int i = 0; i < mediterraneo.length()-1; i++) {
        Barco* barco = mediterraneo.read(i);
        if (barco->UBI.substr(0, 3) == serie)
            conteoM[barco->fecha.substr(3, 2)]++; // Asume que la fecha está en el formato "DD/MM/AAAA"
    }

    for (int i = 0; i < rojo.length(); i++) {
        Barco* barco = rojo.read(i);
        if (barco->UBI.substr(0, 3) == serie)
            conteoR[barco->fecha.substr(3, 2)]++; // Asume que la fecha está en el formato "DD/MM/AAAA"
    }

    for (const auto& par : conteoM) {
        std::cout << par.first << ' ' << par.second << ' ' << conteoR[par.first] << '\n';
    }

    return 0;
}
