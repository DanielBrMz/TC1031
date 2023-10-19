#include <iostream>
#include "BST.h"

void BST::visit(int opcion) {
  switch (opcion) {
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

void BST::preorder(Nodo *nodo){
  if (nodo == NULL) return;

  std::cout << nodo->data << " ";
  preorder(nodo->izquierda);
  preorder(nodo->derecha);
}

void BST::inorder(Nodo *nodo){
  if (nodo == NULL)
      return;
  inorder(nodo->izquierda);
  std::cout << nodo->data << " ";
  inorder(nodo->derecha);
}

void BST::postorder(Nodo *nodo){
  if (nodo == NULL)
      return;
  postorder(nodo->izquierda);
  postorder(nodo->derecha);
  std::cout << nodo->data << " ";
}

void BST::levelByLevel(Nodo *raiz){
  if (raiz == NULL) return;

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

int BST::height(Nodo *nodo){
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

bool BST::ancestors(Nodo *raiz, int dato){
  if (raiz == NULL) return false;

  if (raiz->data == dato) return true;

  if (ancestors(raiz->izquierda, dato) || ancestors(raiz->derecha, dato)){
      std::cout << raiz->data << " ";
      return true;
  }

  return false;
}

int BST::whatlevelamI(Nodo *nodo, int data, int nivel){
  if (nodo == NULL) return -1;

  if (nodo->data == data) return nivel;

  int nivelInferior = whatlevelamI(nodo->izquierda, data, nivel + 1);

  if (nivelInferior != -1) return nivelInferior;

  nivelInferior = whatlevelamI(nodo->derecha, data, nivel + 1);

  return nivelInferior;
}