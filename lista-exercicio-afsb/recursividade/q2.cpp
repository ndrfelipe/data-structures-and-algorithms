#include <iostream>
using namespace std;
int maior_elemento(int vet[], int tamanho){
    //o que posso fazer para encontrar o maior elemento?
    if (tamanho == 1){
        return vet[0];
    }else{
        // return sizeof(vet[tamanho-1]) / maior_elemento(vet, tamanho-1);
        int maior = maior_elemento(vet, tamanho-1);
        return (vet[tamanho-1] > maior) ? vet[tamanho-1] : maior;
    }

}

int main(){

    int vetor[]={1,8,3,4,5};

    int tam = 0;
    // sizeof retorna o numero de bytes do vetor completo. sizeof de um único valor, retorna o
    //número de bytes de apenas um valor. 

    tam = sizeof(vetor)/sizeof(vetor[0]);
    
    int elemento = maior_elemento(vetor, tam);
    cout<<"Maior elemento: "<< elemento << endl;
    return 0;
}