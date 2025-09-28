#include <iostream>
#include <string>

using namespace std;
// Array-based Stack

const int MAX_SIZE = 10;

typedef struct Pilha{
    int indice;
    int dados[MAX_SIZE];
}Pilha;

void push(Pilha *pilha, int value){
    if (pilha->indice == MAX_SIZE - 1){
        std::cout << "Stack Overflow" << endl;
        return;
    }

    pilha->indice +=1;
    pilha->dados[pilha->indice] = value;
}

int pop(Pilha *pilha){

    if (pilha->indice == -1){
        std::cout << "Stack Underflow" << endl;
        return 0;
    }

    int valor_topo = pilha->dados[pilha->indice];
    pilha->indice -=1;
    return valor_topo;
}

bool isEmpty(Pilha *pilha){
    return pilha->indice == -1;
}

string to_binary(int number){
    Pilha pilha;
    pilha.indice = -1;

    while (number > 0) {
        int rest = number % 2;
        push(&pilha, rest);
        number /= 2;
    }

    string string_invertida = "";

    while(!isEmpty(&pilha)) {
        string_invertida += (char)(pop(&pilha) + '0');
    }

    return string_invertida;
}

int main(){
    int exp1 = 10;
    int exp2 = 25;

    std::cout << "Original 1: " << exp1 << std::endl;
    std::cout << "Convertida:  " << to_binary(exp1) << "\n" << std::endl;

    std::cout << "Original 2: " << exp2 << std::endl;
    std::cout << "Convertida:  " << to_binary(exp2) << "\n" << std::endl;



    return 0;
}