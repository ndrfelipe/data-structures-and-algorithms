#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int value){
    Node* newNode   =   new Node;
    newNode->value  =   value;
    newNode->left   =   newNode->right = nullptr;
    
    return newNode;
}

Node* insert(Node* node, int value){
    
    if(node == NULL){
        return newNode(value);
    }

    if(value < node->value){
        node->left = insert(node->left, value);
    }else if(value > node->value){
        node->right = insert(node->right, value);
    }

    return node;
}

Node* search(Node* node, int value){
    if (node == nullptr){
        std::cout<<"Node don't found. "<<"\n";
        return node;
    }

    if(value < node->value){
        node->left = search(node->left, value);
    }else if(value > node->value){
        node->right = search(node->right, value);
    }else{
        std::cout<<"\nNode found: "<< node->value<<"\n";
    }
    return node;
}

int main(){
    Node* node = nullptr;

    node = insert(node, 50);
    insert(node, 30);
    insert(node, 70);
    insert(node, 20);
    insert(node, 40);
    insert(node, 60);
    insert(node, 80);

    search(node, 40);
    search(node, 1);
    delete(node);

    return 0;
}