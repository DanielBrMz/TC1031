#include <iostream>

class Nodo{
    public:
        int data;
        Nodo *next;
        // Nodo(int info){
        //     data = info;
        //     next = nullptr;
        // }
    
};

class LinkedList{
    public:

        // Crear la referencia al primer nodo (head)
        Nodo *head;
        LinkedList(){
            head = NULL;
        }

        //crear un nodo
        void create(int data){
            Nodo *nodo = new Nodo();
            nodo->data = data;
            nodo->next = head;
            head = nodo;
        }

        // updatear un nodo
        void update(int data, int nodoData){
            Nodo *temp = head;
            while(temp != NULL){
                if(temp->data == data){
                    temp->data = nodoData;
                    return;
                }
                temp = temp->next;
            }
        }

        //borrar un nodo
        void del(int data){
            Nodo *temp = head;
            Nodo *temp2 = head;
            while(temp != NULL){
                if(temp->data == data){
                    temp2->next = temp->next;
                    delete temp;
                    return;
                }
                temp2 = temp;
                temp = temp->next;
            }
        }

        //buscar un nodo
        Nodo* read(int data){
            Nodo *temp = head;
            while(temp != NULL){
                if(temp->data == data){
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }

        //mostrar la list por consola
        void mostrar(){
            Nodo *temp = head;
            while(temp != NULL){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }
};


int main(){

    // Crear una list en cadena
    LinkedList list;
    int opt;

    // Menu de opciones para probar la Linked List
    while(opt != 0){

        std::cout << "1. Crear un nodo\n2. Actualizar un nodo\n3. Borrar un nodo\n4. Buscar un nodo\n5. Mostrar la list\n0. Salir\nOpcion: ";
        std::cin>>opt;

        // Crear un nodo en la list
        if(opt == 1){
            int data;
            std::cout<<"Ingrese el dato: ";
            std::cin>>data;
            list.create(data);

        // Updatear un nodo en la list
        }else if(opt == 2){
            int data, nodoData;
            std::cout<<"Ingrese el dato a actualizar: ";
            std::cin>>data;
            std::cout<<"Ingrese el nodo data: ";
            std::cin>>nodoData;
            list.update(data, nodoData);

        // Borrar un nodo en la list
        }else if(opt == 3){
            int data;
            std::cout<<"Ingrese el dato a borrar: ";
            std::cin>>data;
            list.del(data);

        // Buscar un nodo en la list
        }else if(opt == 4){
            int data;
            std::cout<<"Ingrese el dato a buscar: ";
            std::cin>>data;
            Nodo *searched = list.read(data);
            if(searched != NULL){
                std::cout<<"El dato fue encontrado"<<std::endl;
            }else{
                std::cout<<"El dato no fue encontrado"<<std::endl;
            }

        // Mostrar la list
        }else if(opt == 5){
            list.mostrar();

        // Salir del programa
        }else if(opt == 0){
            std::cout<<"list Final: "<<std::endl;
            
        }else{
            std::cout<<"Opcion invalida"<<std::endl;

        }

    }

    list.mostrar();

    return 0;
}