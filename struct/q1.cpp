#include <iostream>
#include <cstring>

typedef struct Pessoa{
    char nome[50];
    int idade;
    float altura;
}Pessoa;

int main()
{
    Pessoa pessoa;
    // é uma forma de trabalhar com Strings utilizando
    // gerenciamento de memória manual.
    strcpy(pessoa.nome, "André");
    pessoa.idade = 20;
    pessoa.altura = 1.7;
    
    std::cout<<pessoa.nome<<"\n";
    std::cout<<pessoa.idade<<"\n";
    std::cout<<pessoa.altura<<"\n";
    
    return 0;
}