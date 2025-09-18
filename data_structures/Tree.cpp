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
    if (node == nullptr || node->value == value){
        if(node != nullptr){
            std::cout<< "\n Found: " << node->value << "\n";
        }else{
            std::cout<<"Node don't found. "<<"\n";
        }
        return node;
    }

    if(value < node->value){
        return search(node->left, value);
    }

    return search(node->right, value);
}

Node* findMinimalLeftValue(Node* node){
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

Node* remove(Node* node, int value){
    if (node == nullptr){
        return node;
    }

    if(value < node->value){
        node->left = remove(node->left, value);
    }else if(value > node->value){
        node->right = remove(node->right, value);
    }else{

        if(node->left == NULL && node->right == NULL){
            delete(node);
            return NULL;
        }

        if(node->left == NULL){
            Node* temp = node->right;
            delete(node);
            return temp;
        }else if (node->right == NULL){
            Node* temp = node->left;
            delete(node);
            return temp;
        }
        Node* temp = findMinimalLeftValue(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
    }
    return node;
}


// ---------------

void inOrder(Node* node){
    if(node != nullptr){
        inOrder(node->left);
        std::cout<<node->value<<", ";
        inOrder(node->right);
    }
}

void preOrder(Node* node){
    if(node != nullptr){
        std::cout<<node->value<<", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void posOrder(Node* node){
    if(node != nullptr){
        posOrder(node->left);
        posOrder(node->right);
        std::cout<<node->value<<", ";
    }
}

void deleteTree(Node* node){
    if (node == nullptr){
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main(){
    Node* node = nullptr;
    int input, option;
    bool state = true;

    while (state)
    {
        std::cout << "Menu de navegação\n";
        std::cout << "1 - Inserir valor\n";
        std::cout << "2 - Remover valor\n";
        std::cout << "3 - Buscar valor\n";
        std::cout << "4 - Exibir em ordem\n";
        std::cout << "5 - Sair\n";

        std::cout << "Digite o valor que deseja: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            std::cout << "\nDigite o valor que deseja inserir: ";
            std::cin >> input;

            std::cout << "\nInserindo nó << " << input << "... \n";
            node = insert(node, input);
            break;
        case 2:
            if (node == NULL){
                std::cout << "\n Para remover você precisa inserir um valor antes. \n";
                break;
            }
            std::cout << "\nDigite o valor que deseja remover: ";
            std::cin >> input;

            std::cout << "\nRemovendo nó << " << input << "... \n";
            node = remove(node, input);
            break;

        case 3:
            if (node == NULL){
                std::cout << "\n Para buscar você precisa inserir um valor antes. \n";
                break;
            }
            std::cout << "\nDigite o valor que deseja buscar: ";
            std::cin >> input;

            std::cout << "\nBuscando nó << " << input << "... \n";
            search(node, input);
            break;
        case 4:
            if (node == NULL){
                std::cout << "\n Para exibir você precisa inserir um valor antes. \n";
                break;
            }
            std::cout << "\n Exibindo em ordem... \n";
            inOrder(node);
            break;
        case 5:
            std::cout << "\n Saindo... \n";
            state = false;
            break;
            
        
        default:
            std::cout << "\n Opção inválida! Tente novamente... \n";
            continue;;
        }

    }
    
    
    deleteTree(node);
    return 0;
}


