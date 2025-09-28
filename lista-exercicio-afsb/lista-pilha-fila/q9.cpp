// fila

#include <iostream>
using namespace std;

const int max_length = 10;

typedef struct Fila{
    int front; // onde o elemento é removido
    int rear; // onde o elemento é inserido
    int dados[max_length];
}Fila;

void inicializar(Fila *fila) {
    fila->front = -1;
    fila->rear = -1;
}

bool isEmpty(Fila *fila){
    return fila->rear == -1 || fila->front > fila->rear;
}

void front(Fila *fila){
    if (isEmpty(fila)){
        cout<<"Fila vazia \n";
        return;
    }

    cout << "Primeiro elemento: " << fila->dados[fila->front] << "\n";
}

void enqueue(Fila* fila, int valor){
    if (fila->rear == max_length - 1){
        cout<<"Fila cheia \n";
        return;
    }

    if (fila->front == -1){
        fila->front += 1;
    }

    fila->rear += 1;
    fila->dados[fila->rear] = valor;
}

void dequeue(Fila* fila){

    if (isEmpty(fila)){
        cout<<"Fila vazia \n";
        return;
    }

    if (fila->front == fila->rear) {
        fila->front = fila->rear = -1;
        return;
    }

    fila->front += 1;
}


int main(){
    Fila fila;
    inicializar(&fila);

    cout<<"\n --- TESTES DE OPERAÇÕES --- \n";
    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    front(&fila);

    cout<<"\n Dequeue: removendo 10 \n";
    dequeue(&fila);
    front(&fila);

    cout<<"\n Dequeue: removendo 20 \n";
    dequeue(&fila);
    front(&fila);

    cout<<"\n Dequeue: removendo 30 \n";
    dequeue(&fila);
    front(&fila);
    
    cout << "A fila esta vazia? " << (isEmpty(&fila) ? "Sim" : "Nao") << std::endl;


    return 0;
}