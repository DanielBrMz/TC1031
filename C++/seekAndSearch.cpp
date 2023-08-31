#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "crow.h"

std::vector<int> ordenamientoIntercambio(std::vector<int> vector){
  int aux;
  for (int i = 0; i < vector.size() - 1; i++){
    for (int j = i + 1; j < vector.size(); j++){
      if (vector[i] > vector[j]){
        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }
  return vector;
}

std::vector<int> ordenamientoBurbuja(std::vector<int> vector){
  int aux;
  for (int i = 0; i < vector.size() - 1; i++){
    for (int j = 0; j < vector.size() - 1; j++){
      if (vector[j] > vector[j + 1]){
        aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
      }
    }
  }
  return vector;
}

std::vector<int> ordenamientoInsercion(std::vector<int> vector){
  int aux, j;
  for (int i = 1; i < vector.size(); i++){
    aux = vector[i];
    j = i - 1;
    while (j >= 0 && vector[j] > aux){
      vector[j + 1] = vector[j];
      j--;
    }
    vector[j + 1] = aux;
  }
  return vector;
}


// 
std::vector<int> ordenamientoMerge(std::vector<int> vector){
  if (vector.size() == 1)
    return vector;
  else{
    std::vector<int> vector1, vector2, vector3;
    for (int i = 0; i < vector.size() / 2; i++)
      vector1.push_back(vector[i]);

    for (int i = vector.size() / 2; i < vector.size(); i++)
      vector2.push_back(vector[i]);

    vector1 = ordenamientoMerge(vector1);
    vector2 = ordenamientoMerge(vector2);

    int i = 0, j = 0;

    while (i < vector1.size() && j < vector2.size()){
      if (vector1[i] < vector2[j]){
        vector3.push_back(vector1[i]);
        i++;
      } else{
        vector3.push_back(vector2[j]);
        j++;
      }
    }
    while (i < vector1.size()){
      vector3.push_back(vector1[i]);
      i++;
    }
    while (j < vector2.size()){
      vector3.push_back(vector2[j]);
      j++;
    }
    return vector3;
  }
}

int busquedaSecuencial(std::vector<int> vector, int dato){
  for (int i = 0; i < vector.size(); i++){
    if (vector[i] == dato)
      return i;
  }
  return -1;
}

int busquedaBinaria(std::vector<int> vector, int dato){
  int inicio = 0, fin = vector.size() - 1, medio;
  while (inicio <= fin){
    medio = (inicio + fin) / 2;
    if (vector[medio] == dato)
      return medio;
    else if (vector[medio] < dato)
      inicio = medio + 1;
    else
      fin = medio - 1;
  }
  return -1;
}



int main() {
  // read in.txt
  std::ifstream file("in.txt");
  std::string line;

  // first line is the number of elements that vector contains
  std::getline(file, line);
  int numberOfElements = std::stoi(line);

  // vector to store the elements read until the number of elements is equal to numberOfElements
  std::vector<int> vector;
  for (int i = 0; i < numberOfElements; i++){
    std::getline(file, line);
    vector.push_back(std::stoi(line));
  }
  
  // show unsorted vector
  std::cout << "Vector sin ordenar: ";
  for (int i = 0; i < vector.size(); i++)
    std::cout << vector[i] << " ";
  std::cout << std::endl;

  // use insertion sort to sort the vector
  vector = ordenamientoInsercion(vector);

  // show the sorted vector
  std::cout << "Vector ordenado: ";
  for (int i = 0; i < vector.size(); i++)
    std::cout << vector[i] << " ";

  return 0;
}