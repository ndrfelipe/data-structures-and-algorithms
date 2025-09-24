#include <iostream>
#include <cstring>
#include <string>

typedef struct Funcionario{
    char nome[50];
    char cargo[30];
    float salario;
}Funcionario;

void exibirInfo(Funcionario *funcionarios, int tamanho)
{   
    std::cout << "-----------Lista de Funcionários-------------" << "\n";
    for(int i=0;i < tamanho;i++)
    {
        
        std::cout << i+1 <<". Nome: " << funcionarios[i].nome <<" | Cargo: "<< funcionarios[i].cargo << " | Salário: "<< funcionarios[i].salario <<"\n";

    }
    std::cout << "---------------------------------------------" << "\n";

}

int main()
{
    int qtd_funcionario;
    
    std::cout << "Digite quantos Funcionarios você deseja cadastrar: " << std::endl;
    std::cin>>qtd_funcionario;
    
    struct Funcionario funcionarios[qtd_funcionario];

    
    for (int i = 0; i < qtd_funcionario; i++)
    {
        std::cout<<"Digite o nome do Funcionario: " << i+1 <<"\n";
        std::cin>>funcionarios[i].nome;
        
        std::cout<<"Digite o cargo do Funcionario: " << i+1 <<"\n";
        std::cin>>funcionarios[i].cargo;
        
        std::cout<<"Digite o salário do Funcionario: " << i+1 <<"\n";
        std::cin>>funcionarios[i].salario;

    }
    
    
    
    exibirInfo(funcionarios, qtd_funcionario);
    return 0;
}