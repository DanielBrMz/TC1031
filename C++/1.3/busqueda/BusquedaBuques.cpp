#include "../Buque.h"

/* Este algoritmo tiene una complejidad  de O(log n) en tiempo y O(1) en espacio.
 * 
 * Complejidad temporal:
 * - Mejor caso: O(1)
 * - Caso promedio: O(log n)
 * - Peor caso: O(log n)
 * 
 * Complejidad espacial:
 * - Mejor caso: O(1)
 * - Caso promedio: O(1)
 * - Peor caso: O(1)
*/
// Función para realizar una búsqueda binaria en el vector de buques
bool buscarBuque(const std::vector<Buque>& buques, const std::string& serieABuscar) {
    int inicio = 0;
    int fin = buques.size() - 1;

    while (inicio <= fin) {
        int mid = inicio + (fin - inicio) / 2;
        if (buques[mid].ubi.substr(0, 3) == serieABuscar) {
            return true;
        } else if (buques[mid].ubi < serieABuscar) {
            inicio = mid + 1;
        } else {
            fin = mid - 1;
        }
    }

    return false;
}