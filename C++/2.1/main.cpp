#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


//TODO: 
// 3.- Realizar analisis de complejidad de los metodos CRUD
// 4.- Casos de prueba 

class Nodo{
    public:
        int data;
        Nodo *next;
        Nodo(int info){
            data = info;
            next = nullptr;
        }
    
};

class LinkedList{
    private:
        // Crear la referencia al primer nodo (head)
        Nodo *head;

    public:

        // Constructor
        LinkedList(){
            head = nullptr;
        }
        
        //Cargar lista desde un fichero
        void cargarLista(){

            //Leer el fichero y almacenar los datos en un vector
            std::ifstream ficheroEntrada;
            ficheroEntrada.open("listaEnlazada.txt");
            std::string linea;
            std::vector<std::string> lista;
            while (getline(ficheroEntrada, linea)){
                lista.push_back(linea);
            }
            ficheroEntrada.close();

            //Crear la lista enlazada con los datos del vector
            for(int i = 0; i < lista.size(); i++){
                std::stringstream ss(lista[i]);
                std::string dato;
                while(getline(ss, dato, ',')){
                    insertarFinal(std::stoi(dato));
                }
            }

        }

        // Guardar la lista enlazada en un fichero
        void guardarLista(){
            std::ofstream ficheroSalida;
            ficheroSalida.open("listaEnlazadaOutput.txt");
            Nodo *temp = head;
            while(temp != nullptr){
                ficheroSalida<<temp->data<<std::endl;
                temp = temp->next;
            }
            ficheroSalida.close();
        }



        // Buscar \ Get
        Nodo* buscar(int data){
            Nodo *temp = head;
            while(temp != nullptr){
                if(temp->data == data){
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        // Insertar \ Crear un nodo al inicio
        void insertarInicio(int data){
            Nodo *newNodo = new Nodo(data);
            newNodo->next = head;
            head = newNodo;
        }

        // Insertar \ Crear un nodo al final
        void insertarFinal(int data){
            Nodo *newNodo = new Nodo(data);
            if(head == nullptr){
                head = newNodo;
            }else{
                Nodo *temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNodo;
            }
        }


        // Este codigo da error debido al delete(temp) 
        // void insertarFinal(int data){
        //     Nodo *newNodo = new Nodo(data);
        //     if(head == nullptr){
        //         head = newNodo;
        //     }else{
        //         Nodo *temp = head;
        //         while(temp->next != nullptr){
        //             temp = temp->next;
                    
        //         }
        //         temp->next = newNodo;
        //         delete(temp);
        //     }    
        // }


        // Insertar \ Crear un nodo despues de un nodo
        void insertarDespues(int data, int nodoData){
            Nodo *nodo = buscar(nodoData);
            if(nodo != nullptr){
                Nodo *newNodo = new Nodo(data);
                newNodo->next = nodo->next;
                nodo->next = newNodo;
            }else{
                std::cout<<"El nodo no existe"<<std::endl;
            }
            // Este bloque de codigo de insertarDespues es de complejidad O(n) debido a que se ejecuta una vez pero
            // como llamamos a la funcion buscar() que es de complejidad O(n) entonces la complejidad de insertarDespues es O(n)
            // Estamos reutilizando y eficientando el codigo de buscar() para insertarDespues() y ahorrar espacio en memoria.
        }


        // updatear un nodo
        void update(int data, int nodoData){
            Nodo *nodo = buscar(nodoData);
            if(nodo != nullptr){
                nodo->data = data;
            }else{
                std::cout<<"El nodo no existe"<<std::endl;
            }
        }

        //borrar un nodo
        bool eliminar(int data){
            Nodo *nodo = buscar(data);
            if(nodo != nullptr){
                if(nodo == head){
                    head = nodo->next;
                    delete(nodo);
                }else{
                    Nodo *temp = head;
                    while(temp->next != nodo){
                        temp = temp->next;
                    }
                    temp->next = nodo->next;
                    delete(nodo);
                }
                return true;
            }else{
                std::cout<<"El nodo no existe"<<std::endl;
                return false;
            }
        }

        // eliminar un nodo del inicio
        bool eliminarInicio(){
            if(head != nullptr){
                Nodo *temp = head;
                head = head->next;
                delete(temp);
                return true;
            }else{
                std::cout<<"La list esta vacia"<<std::endl;
                return false;
            }
        }
        
        // eliminar un nodo del final
        bool eliminarFinal(){
            if(head != nullptr){
                if(head->next == nullptr){
                    delete(head);
                    head = nullptr;
                }else{
                    Nodo *temp = head;
                    while(temp->next->next != nullptr){
                        temp = temp->next;
                    }
                    delete(temp->next);
                    temp->next = nullptr;
                }
                return true;
            }else{
                std::cout<<"La list esta vacia"<<std::endl;
                return false;
            }
        }

        //mostrar la list por consola
        void mostrar(){
            Nodo *temp = head;
            while(temp != nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }

        // Obtener el primer elemento de la lista enlazada
        int getPrimero(){
            return head->data;
        }

        // Saber si la lista esta vacia
        bool listaVacia(){
            return head == nullptr;
        }

        // borrar la lista enlazada (liberar memoria)
        void borrar(){
            Nodo *temp = head;
            while(temp != nullptr){
                head = temp->next;
                delete(temp);
                temp = head;
            }
        }

};


int main(){

    // Crear una lista enlazada
    LinkedList list;

    // Cargar lista desde un fichero si el fichero no esta vacio
    std::ifstream ficheroEntrada;
    ficheroEntrada.open("listaEnlazada.txt");
    std::string linea;
    if(getline(ficheroEntrada, linea)){
        ficheroEntrada.close();
        list.cargarLista();
    }


    int opt = 1;
    // Menu de opciones para probar la Linked List
    while(opt != 0){
        // borrar consola
        system("cls");
        std::cout<<"\n********************************\n1. Insertar\n2. Updatear\n3. Eliminar\n4. Buscar\n5. Mostrar la lista enlazada\n6. Obtener el primer elemento\n7. Saber si la lista esta vacia\n8. Borrar La lista entera\n0. Salir\n********************************\nOpcion: ";
        std::cin>>opt;

        // Crear un nodo en la lista enlazada
        if(opt == 1){
            int data;
            std::cout<<"\nIngrese el dato: ";
            std::cin>>data;

            //preguntar en donde quiere colocar el dato
            int opt2;
            std::cout<<"\n1. Al inicio\n2. Al final\n3. Despues de un nodo\nOpcion: ";
            std::cin>>opt2;

            // Insertar un nodo al inicio
            if(opt2 == 1){
                list.insertarInicio(data);
            // Insertar un nodo al final
            } else if(opt2 == 2){
                list.insertarFinal(data);
            // Insertar un nodo despues de un nodo
            } else if(opt2 == 3){
                int nodoData;
                std::cout<<"\nIngrese el nodo data: ";
                std::cin>>nodoData;
                list.insertarDespues(data, nodoData);
            } else{
                std::cout<<"\nOpcion invalida"<<std::endl;
            }

        // Updatear un nodo en la list
        }else if(opt == 2){
            int data, nodoData;
            std::cout<<"\nIngrese el nodo data a actualizar: ";
            std::cin>>nodoData;
            std::cout<<"\nIngrese el dato actualizado: ";
            std::cin>>data;
            list.update(data, nodoData);

        // eliminar un nodo en la list
        }else if(opt == 3){

            // preguntar en donde quiere eliminar el nodo
            int opt2;
            std::cout<<"\n1. Al inicio\n2. Al final\n3. Dato Exacto\nOpcion: ";
            std::cin>>opt2;

            // Eliminar un nodo al inicio
            if(opt2 == 1){
                list.eliminarInicio();
            // Eliminar un nodo al final
            }else if(opt2 == 2){
                list.eliminarFinal();
            // Eliminar un nodo con dato exacto
            }else if(opt2 == 3){
                int data;
                std::cout<<"\nIngrese el dato a eliminar: ";
                std::cin>>data;
                list.eliminar(data);
            }else{
                std::cout<<"\nOpcion invalida"<<std::endl;
            }

        // Buscar un nodo en la list
        }else if(opt == 4){
            int data;
            std::cout<<"\nIngrese el dato a buscar: ";
            std::cin>>data;
            Nodo *nodo = list.buscar(data);
            if(nodo != nullptr){
                std::cout<<"\nEl nodo existe"<<std::endl;
            }else{
                std::cout<<"\nEl nodo no existe"<<std::endl;
            }

        // Mostrar la list
        }else if(opt == 5){

            //validar si es nullptr
            if(list.listaVacia()){
                std::cout<<"\nLa lista esta vacia"<<std::endl;
            }else{
                std::cout<<"\nlista: "<<std::endl;
                list.mostrar();
            }


        // Obtener el primer elemento de la lista enlazada
        }else if(opt == 6){

            //validar si es nullptr
            if(list.listaVacia()){
                std::cout<<"\nLa lista esta vacia"<<std::endl;
                
            }else{
            std::cout<<"\nEl primer elemento es: "<<list.getPrimero()<<std::endl;
            }
        // Saber si la lista esta vacia
        }else if(opt == 7){
            if(list.listaVacia()){
                std::cout<<"\nLa lista esta vacia"<<std::endl;
            }else{
                std::cout<<"\nLa lista no esta vacia"<<std::endl;
            }

        }else if(opt == 8){
            list.borrar();
            std::cout<<"\nLa lista se borro"<<std::endl;
        // Salir del programa
        }else if(opt == 0){


            // Guardar la lista enlazada en un fichero
            std::cout<<"\nLista Final: "<<std::endl;
            list.mostrar();
            list.guardarLista();
            
        }else{
            std::cout<<"\nOpcion invalida"<<std::endl;

        }

    // Crear funcion de pausa hasta que el usuario ingrese enter
    std::cout<<"\nPresione enter para seguir..."<<std::endl;
    std::cin.ignore();
    std::cin.get();

    }

    return 0;
}