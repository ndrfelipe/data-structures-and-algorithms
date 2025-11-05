#include <iostream>
using namespace std;

int buscaSequencial(int vetor[], int tamanho, int chave)
{
    int contador = 0;
    for(int i = 0; i < tamanho; i++ ) {
        if (chave == vetor[i])
        {
            contador++;
        }
    }
    return contador;
}

int main()
{
    int vetor[] = {1, 5, 8, 5, 2};
    int tamanho = 5;

    int valor = buscaSequencial(vetor, tamanho, 5);

    cout<<valor;
    return 0;
}