#include "iostream"
#include "fstream"
#include <vector>
#include <map>
#include "ListaEnlazada/ListaEnlazada.h"
#include "Barco/Barco.h"

/*
 * Este programa utliza la estructura de datos Lista Enlazada para almacenar los datos de los barcos
 * que pasan por el canal de Suez. Luego, utiliza el algoritmo de ordenamiento Merge Sort para ordenar
 * los barcos por su UBI y el algoritmo de búsqueda Secuencial para buscar los barcos que pasaron por
 * el canal de Suez en cada mes.
 *
 * El programa lee un archivo de entrada indicado por el usuario con el siguiente formato:
 * - Fecha: dd/mm/aaaa
 * - Hora: hh:mm
 * - Punto de entrada: M (Mediterráneo) o R (Rojo)
 * - UBI: 3 letras y 3 números
 *
 * El programa ordena los barcos por su UBI y luego busca los barcos que pasaron por cada punto de entrada
 * segun los tres primeros caracteres de su UBI.
 *
 * El programa imprime en pantalla la cantidad de barcos que pasaron por cada punto de entrada en cada mes.
 *
 * Complejidad temporal:
 * - Ordenamiento: O(n log n)
 * - Búsqueda: O(n)
 *
 * Complejidad espacial:
 * - Ordenamiento: O(n)
 * - Búsqueda: O(1)
 *
 * Nota: El programa espera que el archivo de texto tenga el formato correcto.
 *
 * Autor: Daniel Alfredo Barreras Meraz
 * Matricula: A01258405
 * Fecha: 30 de septiembre de 2023
 */

/*
  Pasos para compilar y ejecutar uel programa tilizando make:
    * Compilar: make
    * Ejecutar: make run
*/

int main(){
  std::string nombreArchivo;
  std::cout << "Ingrese el nombre del archivo de entrada: ";
  std::cin >> nombreArchivo;

  std::ifstream archivo(nombreArchivo);
  if (!archivo){
    std::cerr << "No se pudo abrir el archivo." << std::endl;
    return 1;
  }

  ListaEnlazada mediterraneo, rojo;
  std::string fecha, hora, punto_entrada, UBI;

  while (archivo >> fecha >> hora >> punto_entrada >> UBI){
    Barco *barco = new Barco(fecha, hora, punto_entrada, UBI);
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

  std::map<std::string, int> conteoM, conteoR;
  std::vector<std::string> months = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dec"};

  std::map<std::string, std::string> monthCode = {{"01", "jan"}, {"02", "feb"}, {"03", "mar"}, {"04", "apr"},
                                                 {"05", "may"}, {"06", "jun"}, {"07", "jul"}, {"08", "ago"},
                                                 {"09", "sep"}, {"10", "oct"}, {"11", "nov"}, {"12", "dec"}};

  for (int i = 0; i < mediterraneo.length(); i++){
    Barco *barco = mediterraneo.read(i);
    if (barco->UBI.substr(0, 3) == serie)
      conteoM[monthCode[barco->fecha.substr(3, 2)] + " " + barco->fecha.substr(8, 2)]++;
  }

  for (int i = 0; i < rojo.length(); i++){
    Barco *barco = rojo.read(i);
    if (barco->UBI.substr(0, 3) == serie)
      conteoR[monthCode[barco->fecha.substr(3, 2)] + " " + barco->fecha.substr(8, 2)]++;
  }

  for (const auto &month : months){
    std::string keyM = month + " 23";
    std::string keyR = month + " 23";
    if (conteoM[keyM] > 0 || conteoR[keyR] > 0)
        std::cout << month << " 23" << ' ' << conteoM[keyM] << ' ' << conteoR[keyR] << '\n';
  }



  return 0;
}
