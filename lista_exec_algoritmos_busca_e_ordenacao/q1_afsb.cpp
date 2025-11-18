#include <iostream>
using namespace std;

// Encontre o número 25 no vetor: {15, 8, 25, 7, 12, 18, 5, 9, 30, 3}

int buscaSequencial(int vetor[], int num, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (vetor[i] == num) {
            return vetor[i];
        }
    }
    return -1;
}

int main() {
    int vector[] = {15, 8, 25, 7, 12, 18, 5, 9, 30, 3};
    int sizeVector      = 10;
    int valorBuscado    = 25;

    int resultado = buscaSequencial(vector, valorBuscado, sizeVector);

    if ( resultado != -1 ) {
        cout << " Valor buscado: " << resultado << " \n ";
        cout << " Valor encontrado: " << resultado << " \n ";
    } else {
        cout << "Valor não encontrado. \n";
    }

    return 0;
}