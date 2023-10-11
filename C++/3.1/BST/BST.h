#include <iostream>
#include "../Fila/Nodo.h"
#include "../Fila/Fila.h"

#pragma once

class BST{
public:
    Nodo *raiz;

    // Función para visitar los nodos del BST
    void visit(int opcion);

    // Funciones de recorrido
    void preorder(Nodo *nodo);

    void inorder(Nodo *nodo);

    void postorder(Nodo *nodo);
    void levelByLevel(Nodo *raiz);

    // Función para obtener la altura del BST
    int height(Nodo *nodo);

    // Función para desplegar los ancestros de un dato
    bool ancestors(Nodo *raiz, int dato);

    // Función para obtener el nivel de un dato
    int whatlevelamI(Nodo *nodo, int data, int nivel);
};