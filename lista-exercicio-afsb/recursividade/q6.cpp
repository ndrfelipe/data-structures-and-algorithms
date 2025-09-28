#include <iostream>
#include <string>
using namespace std;

int palindromo(std::string str){
    if (str.length() <= 1){
        return 1;   
    }
    else if (str[0] != str[str.length() - 1]){
        return 0;
    }
    else {
        return palindromo(str.substr(1, str.length() - 2));
    }
}

int main(){
    std::string palavra;
    cout<<"Digite uma palavra: "<<endl;
    cin>>palavra;

    if(palindromo(palavra)){
        cout << "É palíndromo" << endl;
    }else{
        cout << "Não é palíndromo" << endl;
    }
    return 0;
}