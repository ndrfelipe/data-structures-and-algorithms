#include <iostream>
using namespace std;

int buscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0, fim = tamanho - 1, meio, contador = 0;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor ) {
            return contador;
        }else if (vetor[meio] < valor) {
            inicio = meio + 1;
            contador++;
        }else {
            fim = meio - 1;
            contador++;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int valor = 100;
    int tamanho = 10;
    int resultado = buscaBinaria(vetor, tamanho, valor);

    if ( resultado != -1 ){
        cout << "Valor: " << valor << " encontrado com " << resultado << " comparações. \n";
    }else{
        cout << "Valor não encontrado.\n";
    }

    return 0;
}