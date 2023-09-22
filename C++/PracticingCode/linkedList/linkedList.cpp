#include <iostream>

class Nodo{
    public:
        int dato;
        Nodo *siguiente;
};

class linkedList{
    public:
        Nodo *head;
        linkedList(){
            head = NULL;
        }
        void insertar(int dato){
            Nodo *nuevo = new Nodo();
            nuevo->dato = dato;
            nuevo->siguiente = head;
            head = nuevo;
        }

        Nodo* buscar(int dato){
            Nodo *temp = head;
            while(temp != NULL){
                if(temp->dato == dato){
                    return temp;
                }
                temp = temp->siguiente;
            }
            return NULL;
        }

        void mostrar(){
            Nodo *temp = head;
            while(temp != NULL){
                std::cout<<temp->dato<<" ";
                temp = temp->siguiente;
            }
            std::cout<<std::endl;
        }
};



int main(){

    linkedList lista;
    lista.insertar(5);
    lista.insertar(10);
    lista.insertar(15);
    lista.insertar(20);
    lista.insertar(25);
    lista.insertar(30);
    lista.insertar(35);
    lista.insertar(40);

    lista.mostrar();

    Nodo *buscado = lista.buscar(20);
    if(buscado != NULL){
        std::cout<<"El dato fue encontrado"<<std::endl;
    }else{
        std::cout<<"El dato no fue encontrado"<<std::endl;
    }


    return 0;
}