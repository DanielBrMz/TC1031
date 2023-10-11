#include <iostream>
#include <Fila/Nodo.h>
#include <BST/BST.h>

int main() {
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
