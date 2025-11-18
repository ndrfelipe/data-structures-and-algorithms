#include <iostream>
using namespace std;

int buscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0, fim = tamanho - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor ) {
            return vetor[meio];
        }else if (vetor[meio] < valor) {
            inicio = meio + 1;
        }else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {2, 4, 6, 8, 10, 12, 13, 14, 16, 18};
    int valor = 13;
    int tamanho = 10;
    int resultado = buscaBinaria(vetor, tamanho, valor);

    if ( resultado != -1 ){
        cout << "Valor encontrado: " << resultado << "\n";
    }else{
        cout << "Valor não encontrado.\n";
    }

    return 0;
}