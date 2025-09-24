#include <iostream>

int contar_digito(int digito){
    if(digito/10 == 0){
        return 1;
        //caso base
    }else{
        return 1 + contar_digito(digito/10);
        //chamada recursiva
    }
}

int main(){
    int digito;
    std::cout<<"Digite um número: "<<"\n";
    std::cin>>digito;

    int resultado = contar_digito(digito);
    std::cout<<"O número "<< digito <<" possui "<< resultado <<" dígitos."<<"\n";
    return 0;
}