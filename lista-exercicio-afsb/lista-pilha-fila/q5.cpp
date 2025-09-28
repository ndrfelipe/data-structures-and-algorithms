#include <iostream>
using namespace std;
// Array-based Stack

const int max_length = 10;

typedef struct Pilha{
    int indice;
    int dados[max_length];
}Pilha;

void push(Pilha *pilha, int value){
    if (pilha->indice == max_length - 1){
        std::cout << "Stack Overflow" << endl;
        return;
    }

    pilha->indice +=1;
    pilha->dados[pilha->indice] = value;
}

void pop(Pilha *pilha){
    if (pilha->indice == -1){
        std::cout << "Stack Underflow" << endl;
        return;
    }

    pilha->indice -=1;
}

void top(Pilha *pilha){
    if (pilha->indice == -1){
        std::cout << "Stack Underflow" << endl;
        return;
    }

    cout << pilha->dados[pilha->indice] <<endl;
}

bool isEmpty(Pilha *pilha){
    return pilha->indice == -1;
}


int main(){
    Pilha pill;
    pill.indice = -1;

    // Teste de operações
    std::cout << "--- OPERACOES INICIAIS ---\n";
    std::cout << "A pilha esta vazia? " << (isEmpty(&pill) ? "Sim" : "Nao") << std::endl;

    push(&pill, 10);
    push(&pill, 20);
    push(&pill, 30);
    top(&pill);

    std::cout << "\n--- TESTE DE POP ---\n";
    pop(&pill); // Remove 30
    top(&pill); 

    pop(&pill); // Remove 20
    pop(&pill); // Remove 10

    std::cout << "\n--- TESTE DE UNDERFLOW ---\n";
    pop(&pill); // Tenta remover de pilha vazia
    top(&pill);

    return 0;
}