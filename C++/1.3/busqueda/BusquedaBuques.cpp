#include "../Buque.h"

// Función para realizar una búsqueda binaria en el vector de buques
bool buscarBuque(const std::vector<Buque>& buques, const std::string& serieABuscar) {
    int left = 0;
    int right = buques.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (buques[mid].ubi.substr(0, 3) == serieABuscar) {
            return true;
        } else if (buques[mid].ubi < serieABuscar) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}