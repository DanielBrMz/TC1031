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

/*
  * Compilar y ejecutar con make: 
  * Compilar: make
  * Ejecutar: make run
*/

int main() {
    BST bst;
    Nodo* raiz = new Nodo();
    raiz->data = 6;
    raiz->izquierda = new Nodo();
    raiz->izquierda->data = 3;
    raiz->derecha = new Nodo();
    raiz->derecha->data = 8;
    raiz->derecha->derecha = new Nodo();
    raiz->derecha->derecha->data = 9;
    bst.raiz = raiz;

    // Llamada a las funciones para cada nodo
    int nodos[] = {3, 6, 8, 9};
    for (int i = 0; i < 4; i++) {
        std::cout << "Nodo: " << nodos[i] << std::endl;
        std::cout << "Altura: " << bst.height(bst.raiz) << std::endl;
        std::cout << "Ancestros: ";
        bst.ancestors(bst.raiz, nodos[i]);
        std::cout << std::endl;
        std::cout << "Nivel: " << bst.whatlevelamI(bst.raiz, nodos[i], 1) << std::endl;

        // Llamada a la función visit
        std::cout << "Preorden: ";
        bst.visit(1);
        std::cout << std::endl;

        std::cout << "Inorden: ";
        bst.visit(2);   
        std::cout << std::endl;

        std::cout << "Postorden: ";
        bst.visit(3);
        std::cout << std::endl;

        std::cout << "Nivel por nivel: ";
        bst.visit(4);
        std::cout << std::endl;

        std::cout << "------------------------" << std::endl;
    }

    return 0;
}