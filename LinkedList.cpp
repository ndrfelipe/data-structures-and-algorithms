#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Function to add an element to the Linked List
Node* addElement(Node* head, int value)
{
    Node* new_list = new Node();
    new_list->data = value;
    new_list->next = head;
    return new_list;

}
// Function to display the Linked List
void displayList(Node* head)
{
    Node* currentList = head;
    while (currentList != nullptr)
    {
        cout<<"Value: "<< currentList->data <<"\n";
        currentList = currentList->next;
    }
    cout<<"NULL\n";
}

// Function to add an element at the end of the Linked List
Node* addElementEnd(Node* head, int value)
{
    Node* temp = head;

    // If list is empty, create a new node and return it
    if(temp == nullptr)
    {   
        cout<<"Attention! List is empty!"<<endl;
        cout<<"Creating a new list..."<<endl;

        Node* new_list  = new Node();
        new_list-> data = value;
        new_list-> next = nullptr;
        return new_list;
    }

    while(temp->next != nullptr)
        temp = temp->next;

    Node* final_list    = new Node();
    final_list-> data   = value;
    final_list-> next   = nullptr;
    temp->next          = final_list;

    return head;
}

// Function to delete an element from the Linked List
Node* deleteElement(Node* head, int value)
{
    Node* temp = head;
    Node* prev = nullptr;

    // If list is empty
    if(temp == nullptr)
    {
        cout<<"Attention! List is empty!"<<endl;
        return head;
    }
    // If head node itself holds the key to be deleted
    if(temp != nullptr && temp->data == value)
    {
        head = temp->next; // Changed head
        delete temp;       // Free old head
        return head;
    }

    // Search for the key to be deleted, keep track of the previous node
    while(temp != nullptr && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    delete temp; // Free memory
    return head;

}

// Function to add element in the middle of the Linked List
Node* addElementMiddle(Node* head, int value, int position)
{
    Node* temp = head;

    // If list is empty, create a new node and return it
    if(temp == nullptr)
    {   
        cout<<"Attention! List is empty!"<<endl;
        cout<<"Creating a new list..."<<endl;

        Node* new_list  = new Node();
        new_list-> data = value;
        new_list-> next = nullptr;
        return new_list;
    }

    // If position is 0, add at the beginning
    if(position == 0)
    {
        return addElement(head, value);
    }

    // Traverse to the position where the new node is to be inserted
    for(int i = 0; temp != nullptr && i < position - 1; i++)
    {
        temp = temp->next;
    }

    // If the position is more than the number of nodes, add at the end
    if(temp == nullptr)
    {
        cout<<"Position is greater than the number of nodes. Adding at the end."<<endl;
        return addElementEnd(head, value);
    }

    Node* new_list = new Node();
    new_list->data = value;
    new_list->next = temp->next;
    temp->next = new_list;

    return head;
}

int main()
{
    Node* head = nullptr;

    head = addElement(head, 10);
    head = addElement(head, 20);
    head = addElement(head, 30);

    displayList(head);

    head = addElementEnd(head, 40);
    head = addElementEnd(head, 50);
    displayList(head);

    head = deleteElement(head, 20);
    displayList(head);

    head = addElementMiddle(head, 25, 2);
    displayList(head);
    return 0;
}