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
    
    int id_client_one = 101;
    int id_client_two = 102;
    int id_client_three = 103;

    enqueue(&fila, id_client_one);
    enqueue(&fila, id_client_two);
    enqueue(&fila, id_client_three);
    
    front(&fila);
    dequeue(&fila);
    std::cout<<"\nCliente " << id_client_one << " atendido. \n";

    front(&fila);
    dequeue(&fila);
    std::cout<<"\nCliente " << id_client_two << " atendido. \n";

    front(&fila);
    dequeue(&fila);
    std::cout<<"\nCliente " << id_client_three << " atendido. \n";

    std::cout << "A fila esta vazia? " << (isEmpty(&fila) ? "\nSim" : "\nNao") << std::endl;

    return 0;
}
