#include <iostream>
using namespace std;


int buscaSequencial(int vetor[], int num, int size) {
    int i;
    int contador = 0;
    for (i = 0; i < size; i++) {
        if (vetor[i] == num) {
            contador++;
        }
    }
    
    if (contador > 0) {
        return contador;
    } else {
        return 0;
    }
}

int main() {
    int vector[]     = {7, 3, 5, 7, 9, 2, 7, 1, 4, 6};
    int sizeVector   = 10;
    int valorBuscado = 7;
    int resultado = buscaSequencial(vector, valorBuscado, sizeVector);
    cout << " Valor: " << valorBuscado << " aparece "<< resultado << " vezes no vetor." << " \n ";
    return 0;
}