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

string inverter_string(string expressao){
    Pilha pilha;
    pilha.indice = -1;

    for(int i = 0; expressao[i] != '\0'; i++) {
        push(&pilha, expressao[i]);
    }

    string string_invertida = "";

    while(!isEmpty(&pilha)) {
        string_invertida += (char)pop(&pilha);
    }

    return string_invertida;
}

int main(){
    std::string exp1 = "andre";
    std::string exp2 = "felipe";
    std::string exp3 = "braga";


    std::cout << "Original 1: " << exp1 << std::endl;
    std::cout << "Invertida:  " << inverter_string(exp1) << "\n" << std::endl;

    std::cout << "Original 2: " << exp2 << std::endl;
    std::cout << "Invertida:  " << inverter_string(exp2) << "\n" << std::endl;

    std::cout << "Original 3: " << exp3 << std::endl;
    std::cout << "Invertida:  " << inverter_string(exp3) << "\n" << std::endl;



    return 0;
}