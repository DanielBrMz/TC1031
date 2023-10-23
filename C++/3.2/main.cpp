#include <iostream>
#include "PriorityQueue/priority_queue.h"

/*
 Este programa utiliza un max_heap para implementar una priority queue
 El programa lee un archivo de entrada dado por el usuario y utiliza
 el input para crear la queue corrrespondiente.
 El programa puede realizar las funciones push, pop, top, empty y size
 y imprimir su resultado en pantalla.
*/

/*
 Complejidad temporal:
 - push: O(logN)
 - pop: O(logN)
 - top: O(1)
 - empty O(1)
 - size O(1)

 Autor: Daniel Alfredo Barreras Meraz / Yair Salvador Beltran Rios
 Matricula: A01254805 / A01254673
 Fecha: 12 de octubre de 2023
*/

/*
 Compilacion:
    make
 Ejecucion:
    make run
*/

int main() {
  /*
   Crearemos el siguiente arbol binario como ejemplo
              85
           /      \
          45      22
         /  \    /
        19  30  9
       /  \
      17   8
*/

  priority_queue queue;

  queue.push(85);
  queue.push(9);
  queue.push(22);
  queue.push(15);
  queue.push(45);
  queue.push(19);
  queue.push(30);
  queue.push(8);
  queue.push(17);

  std::cout << "Fila incial: ";
  queue.print();
  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "Prueba 1" << std::endl;
  std::cout << "Funcion: push" << std::endl;
  std::cout << "Input: " << 516 << std::endl;
  std::cout << "Fila antes: ";
  queue.print();
  queue.push(516);
  std::cout << "Fila despues: ";
  queue.print();
  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "Prueba 2" << std::endl;
  std::cout << "Funcion: pop" << std::endl;
  std::cout << "Fila antes: ";
  queue.print();
  queue.pop();
  std::cout << "Fila despues: ";
  queue.print();
  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "Prueba 3" << std::endl;
  std::cout << "Funcion: top" << std::endl;
  std::cout << "Fila: ";
  queue.print();
  std::cout << "Top: " << queue.top() << std::endl;
  std::cout << "---------------------------------------------" << std::endl;

  std::cout << "Prueba 4" << std::endl;
  std::cout << "Funcion: empty y size" << std::endl;

  std::cout << "Fila: ";
  queue.print();
  std::cout << "Size: " << queue.size() << std::endl;
  std::cout << std::boolalpha;
  std::cout << "Esta vacia?: " << queue.empty() << std::endl;
  std::cout << "---------------------------------------------" << std::endl;

  return 0;
}