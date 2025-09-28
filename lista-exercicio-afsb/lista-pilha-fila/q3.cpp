#include <iostream>
using namespace std;

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* insert_start(Node* head, int value){
   Node* newNode    = new Node;
   newNode->value   = value;
   newNode->next    =  head;
   return newNode;
}

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

Node* insert_ordered(Node* head, int value){
    // Se lista vazia, inserir no começo.
    if (head == nullptr || head->value > value){
        Node* newNode    = new Node;
        newNode->value   = value;
        newNode->next    =  head;
        return newNode;
    }

    Node* current = head;
    Node* prev    = nullptr;

    while (current != nullptr && current->value < value){
        prev    = current;
        current = current->next;
    }

    Node* newNode    = new Node;
    newNode->value   = value;

    prev->next = newNode;
    newNode->next = current;
    return head;
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


void print_list(Node* head){
    Node* actually   = head;

    cout<<"Lista: ";

    while (actually != nullptr){
        cout<<actually->value<<" -> ";
        actually = actually -> next;
    }

    cout<<"NULL \n";
}

int count_elements(Node* head){
    if (head == nullptr){
        return 0;
    }else{
        return 1 + count_elements(head->next);
    }
}

void print_count_elements(Node* head){
    int qtd_elements = count_elements(head);
    cout<<"Quantidade total de elementos: "<<qtd_elements<<"\n";
}

int main(){
    Node* head = nullptr;

    head = insert_ordered(head, 5);
    head = insert_ordered(head, 10);
    head = insert_ordered(head, 20);
    head = insert_ordered(head, 15);
    print_list(head);

    print_count_elements(head);

    head = remove(head, 10);
    print_list(head);
    print_count_elements(head);

    head = remove(head, 20);
    print_list(head);
    print_count_elements(head);

    head = remove(head, 1);
    print_list(head);
    print_count_elements(head);

    return 0;
}