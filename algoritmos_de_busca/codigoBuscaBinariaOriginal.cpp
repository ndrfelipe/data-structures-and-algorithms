#include <iostream>
using namespace std;

int buscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0, fim = tamanho - 1, meio;

    while (inicio < fim) {
        if (vetor[meio] == valor ) {
            return meio;
        }else if (vetor[meio] < valor) {
            inicio = meio + 1;
        }else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {3, 6, 9, 12, 15, 18, 21};
    int valor = 15;
    int tamanho = 7;
    int pos = buscaBinaria(vetor, tamanho, valor);
    if ( pos != -1 ){
        cout << "Valor: " << valor << " encontrado na posição " << pos << "\n";
    }else{
        cout << "Valor não encontrado.\n";
    }

    return 0;
}