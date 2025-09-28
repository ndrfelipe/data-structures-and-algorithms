#include <iostream>
using namespace std;

void contar_regressivamente_iterativo(int num){
    for(num ; num >= 0; num--){
        cout << num << endl;
    }
}

int main(){
    int n;
    cout<<"Digite um numero para iniciar a contagem regressiva: "<<endl;
    cin>>n;

    cout<<"Contagem regressiva: "<<"\n";
    contar_regressivamente_iterativo(n);    

    return 0;
}