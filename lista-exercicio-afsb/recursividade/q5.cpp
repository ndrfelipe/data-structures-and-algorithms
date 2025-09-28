#include <iostream>
using namespace std;

void contar_regressivamente(int num){
    if (num == 0){
        cout << 0 << endl;
        return;
    }else{
        cout << num << endl;
        contar_regressivamente(num - 1);
    }
}

int main(){
    int n;
    cout<<"Digite um numero para iniciar a contagem regressiva: "<<endl;
    cin>>n;

    cout<<"Contagem regressiva: "<<"\n";
    contar_regressivamente(n);    

    return 0;
}