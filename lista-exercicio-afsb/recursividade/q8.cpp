#include <iostream>
using namespace std;
int maior_elemento(int vet[], int tamanho){
    int maior_elemento = vet[tamanho/2];
    for (int i = 0 ; i < tamanho ; i++){
        if(maior_elemento < vet[i]){
            maior_elemento = vet[i];
        }
    }

    return maior_elemento;

}

int main(){

    int vetor[]={1,8, 10,4,5};

    int tam = 0;
    tam = sizeof(vetor)/sizeof(vetor[0]);
    
    int elemento = maior_elemento(vetor, tam);
    cout<<"\n\nMaior elemento: "<< elemento << endl;
    return 0;
}