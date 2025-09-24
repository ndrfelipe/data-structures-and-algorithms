#include <iostream>
#include <cstring>
#include <string>

typedef struct Retangulo{
    float base;
    float altura;
}Retangulo;

int calcularArea(Retangulo retangulo){
    int area = retangulo.base * retangulo.altura;
    return area;
}

int calcularPerimetro(Retangulo retangulo){
    int perimetro = (retangulo.base *2) + (retangulo.altura *2);
    return perimetro;
}

void exibirInfo(Retangulo retangulo)
{   
    std::cout << "-----------Valores-------------" << "\n";
   
    std::cout << ". Área: " << calcularArea(retangulo) << "\n";
    std::cout << ". Perímetro: " << calcularPerimetro(retangulo) << "\n";

    std::cout << "---------------------------------------------" << "\n";

}


int main()
{

    struct Retangulo retangulo;

    std::cout<<"Digite a base do retângulo: " <<"\n";
    std::cin>>retangulo.base;
    
    std::cout<<"Digite a altura do retângulo: " <<"\n";
    std::cin>>retangulo.altura;

    exibirInfo(retangulo);
    return 0;
}