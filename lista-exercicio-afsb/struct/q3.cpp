#include <iostream>
#include <cstring>
#include <string>

const int QTD_ALUNOS = 5;

typedef struct Produto{
    char nome[30];
    int codigo;
    float preco;
}Produto;

void exibirProduto(Produto produto)
{
    std::cout << "------------------------" << "\n";
    std::cout << "Nome do produto: " << produto.nome <<std::endl;
    std::cout << "Codigo do produto: " << produto.codigo <<std::endl;
    std::cout << "Preço do produto: " << produto.preco <<std::endl;
    std::cout << "------------------------" << "\n";

}

int main()
{
    Produto produto;
    std::cout<<"Insira o nome do produto"<<"\n";
    std::cin>>produto.nome;
    std::cout << "Insira o código do produto "<<"\n";
    std::cin>>produto.codigo;
    std::cout << "Insira o preço do produto"<<"\n";
    std::cin>>produto.preco;
    
    exibirProduto(produto);
    
    return 0;
}