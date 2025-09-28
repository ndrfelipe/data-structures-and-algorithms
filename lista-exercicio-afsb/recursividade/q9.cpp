#include <iostream>
using namespace std;

int somar_digitos(int num){
    int soma_digitos = 0;
    int ultimo_digito;
    while (num > 0)
    {   
        ultimo_digito = num % 10;
        soma_digitos = soma_digitos + ultimo_digito;

        num = num/10;
    }
    return soma_digitos;
}

int main(){
    int n;
    cout<<"Digite um número inteiro: "<<endl;
    cin>>n;

    cout<<"Soma dos dígitos: "<<somar_digitos(n)<<endl;
    return 0;
}