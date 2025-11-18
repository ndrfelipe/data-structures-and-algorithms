#include <iostream>
using namespace std;


int buscaSequencial(int vetor[], int num, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (vetor[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    int vector[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int sizeVector      = 10;
    int valorBuscado    = 55;

    int resultado = buscaSequencial(vector, valorBuscado, sizeVector);

    if ( resultado != -1 ) {
        cout << " Valor buscado: " << valorBuscado << " \n ";
        cout << " Valor encontrado: " << resultado << " \n ";
    } else {
        cout << "Valor não encontrado. \n";
    }

    return 0;
}