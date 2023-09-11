#include <iostream>
#include <fstream>
#include <vector>
#include "ordenamiento/OrdenaBurbuja.h"
#include "ordenamiento/OrdenaIntercambio.h"
#include "ordenamiento/OrdenaMerge.h"
#include "busqueda/searching/BusquedaSecuencial.h"
#include "busqueda/BusquedaBinaria.h"

int main() {
    std::ifstream in("input/in.txt");

    int n, q;
    in >> n;
    std::vector<int> numeros(n);
    for (int& num : numeros) {
        in >> num;
    }

    std::vector<int> intercambio = numeros;
    int intercambioComparaciones = ordenaIntercambio(intercambio);

    std::vector<int> burbuja = numeros;
    int burbujaComparaciones = ordenaBurbuja(burbuja);

    std::vector<int> merge = numeros;
    int mergeComparaciones = ordenaMerge(merge);

    std::cout << intercambioComparaciones << ' ' << burbujaComparaciones << ' ' << mergeComparaciones << '\n';

    in >> q;
    for (int i = 0; i < q; i++) {
        int consulta;
        in >> consulta;

        int secuencialComparaciones;
        busqSecuencial(numeros, consulta, secuencialComparaciones);

        int binariaComparaciones;
        busqBinaria(merge, consulta, binariaComparaciones);

        std::cout << i << ' ' << secuencialComparaciones << ' ' << binariaComparaciones << '\n';
    }

    return 0;
}
