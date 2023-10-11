#include <iostream>
#include "BST/BST.h"
#include "Fila/Nodo.h"

/*
  * Este programa utiliza un BST para almacenar datos de tipo entero.
  * El programa lee un archivo de entrada indicado por el usuario con los casos de prueba
  * y realiza las operaciones correspondientes.
  * El programa imprime en pantalla el resultado de cada operación.
  * 
  * Complejidad temporal:
  * - visit
  *   - Preorden: O(n)
  *   - Inorden: O(n)
  *   - Postorden: O(n)
  *   - Level by level: O(n)
  * - height: O(n)
  * - ancestors: O(n)
  * - whatlevelamI: O(n)
  * 
  * Complejidad espacial:
  * - visit
  *  - Preorden: O(n)
  *   - Inorden: O(n)
  *   - Postorden: O(n)
  *   - Level by level: O(n)
  * - height: O(n)
  * - ancestors: O(n)
  * - whatlevelamI: O(n)
  * 
  * Nota: El programa espera que el archivo de texto tenga el formato correcto.
  * 
  * Autor: Daniel Alfredo Barreras Meraz
  * Matricula: A01254805
  * Fecha: 11 de octubre de 2023
*/

int main() {
    int s3 = 5;
    BST bst;
    Nodo* raiz = new Nodo();
    raiz->data = 5;
    raiz->izquierda = new Nodo();
    raiz->izquierda->data = 3;
    raiz->derecha = new Nodo();
    raiz->derecha->data = 7;
    bst.raiz = raiz;

    // Test case 1: visitar los nodos en preorden
    std::cout << "Preorden: ";
    bst.visit(1);
    std::cout << std::endl;

    // Test case 2: visitar los nodos en orden
    std::cout << "Inorden: ";
    bst.visit(2);   
    std::cout << std::endl;

    // Test case 3: visitar los nodos en postorden
    std::cout << "Postorden: ";
    bst.visit(3);
    std::cout << std::endl;

    // Test case 4: visitar los nodos nivel por nivel
    std::cout << "Nivel por nivel: ";
    bst.visit(4);
    std::cout << std::endl;

    return 0;
}