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

void inOrder(Node* node){
    if(node != nullptr){
        inOrder(node->left);
        std::cout<<node->value<<", ";
        inOrder(node->right);
    }
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

    inOrder(node);

    return 0;
}