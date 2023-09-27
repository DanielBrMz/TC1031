#include <iostream>
#include <string>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        void create(int value) {
            Node* temp = new Node;
            temp->data = value;
            temp->next = NULL;

            if(head == NULL) {
                head = temp;
                tail = temp;
                temp = NULL;
            }
            else {	
                tail->next = temp;
                tail = temp;
            }
        }

        void display() {
            Node* temp = new Node;
            temp = head;
            while(temp != NULL) {
                std::cout << temp->data << "\t";
                temp = temp->next;
            }
        }  
};

int main() {
    LinkedList list;

    list.create(10);
    list.create(20);
    list.create(30);

    list.display();

    return 0;
}
