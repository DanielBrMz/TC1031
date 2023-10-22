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

 Autor: Yair Salvador Beltran Rios
 Matricula: A01254673
 Fecha: 12 de octubre de 2023
*/

/*
 Compilacion y ejecucion:
 $ find . -type f -name "*.cpp" | xargs g++ -o output
$ ./output
*/

int main()
{
    /* 
    Crearemos el siguiente arbol binario como ejemplo
               71
            /      \
           31      14
          /  \    /  \
         13  20  7   11
        /  \
       12   7
    */

    priority_queue queue;

    queue.push(71);
    queue.push(7);
    queue.push(14);
    queue.push(11);
    queue.push(31);
    queue.push(13);
    queue.push(20);
    queue.push(7);
    queue.push(12);


    std::cout << "Queue incial: ";
    queue.print();
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Prueba 1" << std::endl;
    std::cout << "Funcion: push" << std::endl;
    std::cout << "Input: " << 918 << std::endl;
    std::cout << "Queue antes: ";
    queue.print();
    queue.push(918);
    std::cout << "Queue despues: ";
    queue.print();
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Prueba 2" << std::endl;
    std::cout << "Funcion: pop" << std::endl;
    std::cout << "Queue antes: ";
    queue.print();
    queue.pop();
    std::cout << "Queue despues: ";
    queue.print();
    std::cout << "---------------------------------------------" << std::endl;
    
    std::cout << "Prueba 3" << std::endl;
    std::cout << "Funcion: top" << std::endl;
    std::cout << "Queue: ";
    queue.print();
    std::cout << "Top: " << queue.top() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "Prueba 4" << std::endl;
    std::cout << "Funcion: empty y size" << std::endl;
    for (int i=0;i < 3;i++){
        queue.pop();
    }
    std::cout << "Queue: ";
    queue.print();
    std::cout << "Size: " << queue.size() << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Esta vacia?: " << queue.empty() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    return 0;
}