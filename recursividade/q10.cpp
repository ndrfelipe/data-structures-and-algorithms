#include <iostream>
using namespace std;

int somar_consecutivamente(int numeral, int multiplicador){
    int soma = 0;
    for (int i = 0; i < multiplicador; i++){
        soma += numeral;
    }
    return soma;
}

int main(){
    int numeral, multiplicador;

    cout<<"\n\nDigite o numeral: "<<endl;
    cin>>numeral;
    cout<<"\nDigite o multiplicador: "<<endl;
    cin>>multiplicador;

    cout<<"Resultado obtido: "<<somar_consecutivamente(numeral,multiplicador)<<endl;
    
    return 0;
}