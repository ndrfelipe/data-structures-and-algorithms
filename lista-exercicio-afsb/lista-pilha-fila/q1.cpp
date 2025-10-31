// Implementar uma lista encadeada simples com as seguintes operações:
// 1. inserir um elemento no início. 2. Inserir no final. 3. Remover um elemento específico. 4. Exibir todos os elementos da lista.
#include <iostream>
using namespace std;

typedef struct Node{
    int value;
    struct Node* next;
}Node;

// inserir no começo
Node* insert_start(Node* head, int value){
   Node* newNode    = new Node;
   newNode->value   = value;
   newNode->next    =  head;
   return newNode;
}



// inserir no final
Node* insert_end(Node* head, int value){
    Node* newNode    = new Node;
    newNode->value   = value;
    newNode->next    = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    Node* current    = head;
    while (current->next != nullptr) {
        current      = current->next;
    }

    current->next    = newNode;
    return head;
}


void print_list(Node* head){
    cout<<"Lista: ";

    while (head != nullptr){
        cout<<head->value<<" -> ";
        head = head -> next;
    }

    cout<<"NULL \n";
}

Node* remove(Node* head, int value){    
    if (head != nullptr && head->value == value){
        Node* temp  = head;
        head        = head->next;
        delete temp;
        return head;
    }

    Node* current   = head;
    Node* prev      = nullptr;
    
    while (current != nullptr && current->value != value) {
        prev    = current;
        current = current->next;
    }
    if (current == nullptr){
        cout<<"O valor "<<value<<" não foi encontrado na lista."<<endl;
        return head;
    }

    prev->next = current->next;
    delete current;
    return head;
}


int main(){
    Node* head = nullptr;

    head = insert_start(head, 5);
    head = insert_start(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 15);
    print_list(head);

    head = remove(head, 10);
    print_list(head);

    head = remove(head, 20);
    print_list(head);

    head = remove(head, 1);
    print_list(head);

    return 0;
}