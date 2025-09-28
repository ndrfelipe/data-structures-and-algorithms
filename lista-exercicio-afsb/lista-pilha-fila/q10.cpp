// fila

#include <iostream>
using namespace std;

const int max_length = 5;

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


int main() {
    FilaCircular fila;
    inicializar(&fila);
    
    // Teste 1: Circularidade (Tamanho total é 5, só cabem 4 elementos)
    enqueue(&fila, 10); // rear = 1
    enqueue(&fila, 20); // rear = 2
    enqueue(&fila, 30); // rear = 3
    enqueue(&fila, 40); // rear = 4
    
    std::cout << "--- TESTE DE INSERCAO ---\n";
    front(&fila); // Esperado: 10
    enqueue(&fila, 50); // Deve dar ERRO: Fila Cheia (rear=4, front=0. (4+1)%5 = 0, que é o front)

    std::cout << "\n--- TESTE DE REMOCAO E REUSO (Circularidade) ---\n";
    dequeue(&fila); // Remove 10. front = 1
    front(&fila);   // Esperado: 20

    enqueue(&fila, 60); // Insere no slot 0 (rear vai para 0). REUSO DE ESPAÇO!
    
    std::cout << "Elemento inserido apos remocao: 60\n";
    front(&fila);   // Esperado: 20 (front continua em 1)
    
    std::cout << "\n--- ESTADO FINAL ---\n";
    
    return 0;
}
