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

void pop(Pilha *pilha){
    if (pilha->indice == -1){
        std::cout << "Stack Underflow" << endl;
        return;
    }

    pilha->indice -=1;
}

bool isEmpty(Pilha *pilha){
    return pilha->indice == -1;
}

bool check_balance(const char expressao[]){
    Pilha pilha;
    pilha.indice = -1;

    for (int i = 0; expressao[i] != '\0'; i++){
        if (expressao[i] == '(') {
            push(&pilha, 1);
        }else if(expressao[i] == ')') {
            if (isEmpty(&pilha)) {
                return false;
            }

            pop(&pilha);
        }
    }

    return isEmpty(&pilha);
        
}

int main(){
    std::string exp1 = "(())()";
    std::string exp2 = "(()";
    std::string exp3 = ")(";
    std::string exp4 = "()(())";

    auto test_expression = [&]( const std::string& exp ){
        bool valid = check_balance( exp.c_str() );
        cout<<"Expressao: \"" << exp << "\" -> resultado: " << (valid ? "Válido (1)" : "Inválido (2)") << endl;
    };

    cout << "\n--- TESTE DE BALANCEAMENTO --- \n";
    test_expression(exp1);
    test_expression(exp2);
    test_expression(exp3);
    test_expression(exp4);

    return 0;
}