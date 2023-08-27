#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Este algortimo tiene una complejidad de O(n) ya que el for se ejecuta n veces y cada vez que se ejecuta se hace una operacion constante (suma += i) por lo que la complejidad es O(n) * O(1) = O(n)
// Explicacion con ecuaciones recurrentes (recurrence equations):
// T(n) = T(n - 1) + 1
// T(n - 1) = T(n - 2) + 1
// T(n - 2) = T(n - 3) + 1
// ...
// T(2) = T(1) + 1
// T(1) = 1
// T(n) = T(n - 1) + 1 = T(n - 2) + 1 + 1 = T(n - 3) + 1 + 1 + 1 = ... = T(1) + 1 + 1 + ... + 1 = 1 + (n - 1) = n


// Este algoritmo tiene una complejidad de O(n) ya que la funcion se llama a si misma n veces y cada vez que se llama se hace una operacion constante (n + sumatoriaRecursiva(n - 1)) por lo que la complejidad es O(n) * O(1) = O(n)
// Explicacion con ecuaciones recurrentes (recurrence equations):
// T(n) = T(n - 1) + 1
// T(n - 1) = T(n - 2) + 1
// T(n - 2) = T(n - 3) + 1
// ...
// T(2) = T(1) + 1
// T(1) = 1
// T(n) = T(n - 1) + 1 = T(n - 2) + 1 + 1 = T(n - 3) + 1 + 1 + 1 = ... = T(1) + 1 + 1 + ... + 1 = 1 + (n - 1) = n
int sumatoriaRecursiva(int n){
  if (n == 1)
    return 1;
  else
    return n + sumatoriaRecursiva(n - 1);
}

// Este algoritmo tiene una complejidad de O(1) ya que solo se hace una operacion constante (n * (n + 1)) / 2 por lo que la complejidad es O(1)
// Explicacion con ecuaciones recurrentes (recurrence equations):
// T(n) = 1
// T(n - 1) = 1
// T(n - 2) = 1
// ...
// T(2) = 1
// T(1) = 1
// T(n) = 1 = 1 = 1 = ... = 1 = 1
int sumatoriaDirecta(int n){
  return (n * (n + 1)) / 2;
}


int main(){
  std::ifstream file("example.txt");
  std::string line;

  std::vector<int> iterativeResults, recursiveResults, directResults;

  while (std::getline(file, line)){
    int n = std::stoi(line);
    iterativeResults.push_back(sumatoriaIterativa(n));
    recursiveResults.push_back(sumatoriaRecursiva(n));
    directResults.push_back(sumatoriaDirecta(n));
  }

  file.close();

  std::cout << "Casos de prueba, algoritmo iterativo: " << std::endl;
  for (int result : iterativeResults)
    std::cout << result << std::endl;

  std::cout << "\n" << "Casos de prueba, algoritmo recursivo: " << std::endl;
  for (int result : recursiveResults)
    std::cout << result << std::endl;

  std::cout << "\n" << "Casos de prueba, algoritmo directo: " << std::endl;
  for (int result : directResults) 
    std::cout << result << std::endl;

  return 0;
}