// fila

#include <iostream>
using namespace std;

const int max_length = 5;

// Funções referentes à Pilha:

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

int get_top_value(Pilha *pilha){
    if (pilha->indice == -1){
        std::cout << "Stack Underflow" << endl;
        return 1;
    }

    int top_value = pilha->dados[pilha->indice];
    return top_value;
}

bool isEmpty_pilha(Pilha *pilha){
    return pilha->indice == -1;
}

// Funções referentes à Fila Circular:

typedef struct FilaCircular{
    int front; // onde o elemento é removido
    int rear; // onde o elemento é inserido
    int dados[max_length];
}FilaCircular;

void inicializar(FilaCircular *filaCircular) {
    filaCircular->front = 0;
    filaCircular->rear = 0;
}

bool isEmpty(FilaCircular *filaCircular){
    return filaCircular->front == filaCircular->rear;
}

bool isFull(FilaCircular *filaCircular){
    int proximo = (filaCircular->rear + 1) % max_length;
    return proximo == filaCircular->front;
}

void enqueue(FilaCircular *filaCircular, int valor){
    if (isFull(filaCircular)){
        std::cout << "Fila Circular cheia\n";
        return;
    }

    filaCircular->rear = (filaCircular->rear + 1) % max_length;
    filaCircular->dados[filaCircular->rear] = valor;
}

void dequeue(FilaCircular* filaCircular){

    if (isEmpty(filaCircular)){
        std::cout<<"Fila Circular vazia \n";
        return;
    }

    filaCircular->front = (filaCircular->front + 1) % max_length;

    if (isEmpty(filaCircular)) {
        filaCircular->front = filaCircular->rear = 0;
    }
}

void front(FilaCircular *FilaCircular){
    if (isEmpty(FilaCircular)){
        std::cout<<"Fila vazia \n";
        return;
    }
    int indice_primeiro = (FilaCircular->front + 1) % max_length;
    std::cout << "Primeiro elemento: " << FilaCircular->dados[indice_primeiro] << "\n";
}

int get_front_value(FilaCircular *FilaCircular){
    if (isEmpty(FilaCircular)){
        std::cout<<"Fila vazia \n";
        return 1;
    }
    int indice_primeiro = (FilaCircular->front + 1) % max_length;
    int valor_front = FilaCircular->dados[indice_primeiro];
    return valor_front;
}

void print_queue(FilaCircular *fila, const char* label) {
    std::cout << label << " [ ";
    if (!isEmpty(fila)) {
        int i = (fila->front + 1) % max_length;
        while( i != (fila->rear +1)%max_length) {
            std::cout << fila->dados[i] << " ";
            i = (i + 1) % max_length;
        }
    }
    std::cout << "]\n";
}

// Função principal do desafio: 

void inverter_fila(FilaCircular* fila){
    Pilha pilha_auxiliar;
    pilha_auxiliar.indice = -1;

    while (!isEmpty(fila)) {
        int valor_transferido = get_front_value(fila);

        dequeue(fila);

        push(&pilha_auxiliar, valor_transferido);
    }

    while (!isEmpty_pilha(&pilha_auxiliar)) {
        int valor = get_top_value(&pilha_auxiliar);

        pop(&pilha_auxiliar);

        enqueue(fila, valor);
    }
}

int main() {
    FilaCircular fila;
    inicializar(&fila);

    // inserção de dados
    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    enqueue(&fila, 40);

    std::cout<< "ESTADO INICIAL: ";
    print_queue(&fila, "");

    // inverte
    inverter_fila(&fila);

    std::cout<< "ESTADO FINAL (INVERTIDO): ";
    print_queue(&fila, "");

    return 0;
}
