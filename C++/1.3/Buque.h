#ifndef BUQUE_H
#define BUQUE_H

#include <string>
#include <vector>

// Estructura para almacenar la información de los buques
struct Buque {
    std::string fecha;
    std::string hora;
    char puntoEntrada;
    std::string ubi;
};

void ordenamientoBuques(std::vector<Buque>& arr, int left, int right);
bool buscarBuque(const std::vector<Buque>& buques, const std::string& serieABuscar);

#endif // BUQUE_H
