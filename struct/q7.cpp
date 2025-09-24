#include <iostream>
#include <cstring>
#include <string>

typedef struct Agenda{
    char nome[50];
    char telefone[15];
}Agenda;

void exibirInfo(Agenda *agenda, int size_vector, char *name)
{   
    std::cout << "-----------Agenda-------------" << "\n";
    for(int i=0;i < size_vector;i++)
    {
        if(strcmp(agenda[i].nome, name) == 0){
            std::cout << i+1 <<". Nome: " << agenda[i].nome <<" | Telefone: "<< agenda[i].telefone << "\n";
        }
    }
    std::cout << "---------------------------------------------" << "\n";

}


int main()
{
    int qtd_contatos;
    char nome[50];
    
    std::cout << "Digite quantos Contatos você deseja cadastrar: " << std::endl;
    std::cin>>qtd_contatos;
    
    struct Agenda contato[qtd_contatos];

    
    for (int i = 0; i < qtd_contatos; i++)
    {
        std::cin.ignore(); 
        std::cout<<"Digite o nome do contato: " << i+1 <<"\n";
        
        std::cin.getline(contato[i].nome, 50);

        std::cout<<"Digite o telefone do contato: " << i+1 <<"\n";
        std::cin.getline(contato[i].telefone, 15);

    }
    
    std::cout << "Digite o nome do contato que você deseja buscar: " << std::endl;
    std::cin >>nome;
    exibirInfo(contato, qtd_contatos, nome);
    return 0;
}