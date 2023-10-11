#include <iostream>
#include <Fila/Nodo.h>
#include <Fila/Fila.h>

class BST{
public:
    Nodo *raiz;

    // Función para visitar los nodos del BST
    void visit(int opcion) {
        switch (opcion)
        {
        case 1:
            preorder(raiz);
            break;
        case 2:
            inorder(raiz);
            break;
        case 3:
            postorder(raiz);
            break;
        case 4:
            levelByLevel(raiz);
            break;
        default:
            std::cout << "Opción no válida" << std::endl;
        }
    }

    // Funciones de recorrido
    void preorder(Nodo *nodo)
    {
        if (nodo == NULL)
            return;
        std::cout << nodo->data << " ";
        preorder(nodo->izquierda);
        preorder(nodo->derecha);
    }

    void inorder(Nodo *nodo){
        if (nodo == NULL)
            return;
        inorder(nodo->izquierda);
        std::cout << nodo->data << " ";
        inorder(nodo->derecha);
    }

    void postorder(Nodo *nodo){
        if (nodo == NULL)
            return;
        postorder(nodo->izquierda);
        postorder(nodo->derecha);
        std::cout << nodo->data << " ";
    }

    void levelByLevel(Nodo *raiz){
        if (raiz == NULL)
            return;

        Fila q;
        q.enqueue(raiz);

        while (!q.isEmpty()){
            Nodo *temp = q.getFront();
            std::cout << temp->data << " ";
            q.dequeue();

            if (temp->izquierda != NULL)
                q.enqueue(temp->izquierda);

            if (temp->derecha != NULL)
                q.enqueue(temp->derecha);
        }
    }

    // Función para obtener la altura del BST
    int height(Nodo *nodo){
        if (nodo == NULL){
            return 0;
        }else{
            int lHeight = height(nodo->izquierda);
            int rHeight = height(nodo->derecha);

            if (lHeight > rHeight)
                return (lHeight + 1);
            else
                return (rHeight + 1);
        }
    }

    // Función para desplegar los ancestros de un dato
    bool ancestors(Nodo *raiz, int dato){
        if (raiz == NULL)
            return false;

        if (raiz->data == dato)
            return true;

        if (ancestors(raiz->izquierda, dato) || ancestors(raiz->derecha, dato)){
            std::cout << raiz->data << " ";
            return true;
        }

        return false;
    }

    // Función para obtener el nivel de un dato
    int whatlevelamI(Nodo *Nodo, int data, int level){
        if (Nodo == NULL)
            return -1;

        if (Nodo->data == data)
            return level;

        int downlevel = whatlevelamI(Nodo->izquierda, data, level + 1);

        if (downlevel != -1)
            return downlevel;

        downlevel = whatlevelamI(Nodo->derecha, data, level + 1);

        return downlevel;
    }
};