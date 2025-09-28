#include <iostream>
using namespace std;

int somar_digitos(int num){
    if (num == 0){
        return 0;
    }else{
        return (num%10) + somar_digitos(num / 10);
    }

}

int main(){
    int n;
    cout<<"Digite um número inteiro: "<<endl;
    cin>>n;

    cout<<"Soma dos dígitos: "<<somar_digitos(n)<<endl;
    return 0;
}