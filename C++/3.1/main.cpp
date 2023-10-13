#include <iostream>
#include "BST/BST.h"
#include "Fila/Nodo.h"

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