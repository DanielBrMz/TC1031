#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Estructura para almacenar la información de los buques
struct Buque {
    std::string fecha;
    std::string hora;
    char puntoEntrada;
    std::string ubi;
};

// Función para combinar dos subarrays ordenados
void merge(std::vector<Buque>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Buque> leftArr(n1);
    std::vector<Buque> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].ubi + leftArr[i].fecha <= rightArr[j].ubi + rightArr[j].fecha) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Función para realizar Merge Sort
void mergeSort(std::vector<Buque>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

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

int main() {
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo de entrada: ";
    std::cin >> nombreArchivo;

    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::vector<Buque> buques;
    Buque buque;

    // Leer datos del archivo
    while (archivo >> buque.fecha >> buque.hora >> buque.puntoEntrada >> buque.ubi) {
        buques.push_back(buque);
    }

    // Ordenar buques usando Merge Sort
    mergeSort(buques, 0, buques.size() - 1);

    std::string serieABuscar;
    std::cout << "Ingrese la serie a buscar (los primeros tres caracteres del UBI): ";
    std::cin >> serieABuscar;

    // Realizar una búsqueda binaria en los buques
    if (buscarBuque(buques, serieABuscar)) {
        std::cout << "Buques de la serie " << serieABuscar << ":" << std::endl;
        for (const Buque& b : buques) {
            if (b.ubi.substr(0, 3) == serieABuscar) {
                std::cout << b.fecha << " " << b.hora << " " << b.puntoEntrada << " " << b.ubi << std::endl;
            }
        }
    } else {
        std::cout << "No se encontraron buques de la serie " << serieABuscar << "." << std::endl;
    }

    return 0;
}
