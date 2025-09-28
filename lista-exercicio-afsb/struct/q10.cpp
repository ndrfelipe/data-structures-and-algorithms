#include <iostream>
#include <cstring>
#include <string>

typedef struct ContaBancaria{
    char nome_titular[50];
    int numero_da_conta;
    float saldo;
}ContaBancaria;

int sacar(ContaBancaria& conta){
    int sacar;
    std::cout<<"---------- Sacando ----------"<<"\n";
    std::cout<<"Digite o valor que você deseja sacar"<<"\n";
    std::cin>>sacar;
    
    if (sacar > conta.saldo){
        std::cout<<"Saldo insuficiente!"<<"\n";
        std::cout<<"Digite algo para voltar ao menu..."<<"\n";
        std::cin.ignore();
        return 0;
    } else if(sacar < 0){
        std::cout<<"Valor inválido!"<<"\n";
        std::cout<<"Digite algo para voltar ao menu..."<<"\n";
        std::cin.ignore();
        return 0;
    }
    else {
        conta.saldo -= sacar;
        std::cout<<"Saque realizado com sucesso!"<<"\n";
        std::cout<<"Seu saldo atual é: "<< conta.saldo <<"\n";

        
        std::cout<<"Digite algo para voltar ao menu..."<<"\n";
        std::cin.ignore();
        return 1;
    }
}

int depositar(ContaBancaria& conta){
    int depositar;
    std::cout<<"---------- Depositando ----------"<<"\n";
    std::cout<<"Digite o valor que você deseja depositar"<<"\n";
    std::cin>>depositar;
    
    if (depositar < 0){
        std::cout<<"Valor inválido!"<<"\n";
        std::cout<<"Digite algo para voltar ao menu..."<<"\n";
        std::cin.ignore();
        return 0;
    } else {
        conta.saldo += depositar;
        std::cout<<"Depósito realizado com sucesso!"<<"\n";
        std::cout<<"Seu saldo atual é: "<< conta.saldo <<"\n";

        std::cout<<"Digite algo para voltar ao menu..."<<"\n";
        std::cin.ignore();
        return 1;
    }
}

int exibir_saldo(ContaBancaria& conta){
    std::cout<<"Seu saldo atual é: "<< conta.saldo <<"\n";
    std::cout<<"Digite algo para voltar ao menu..."<<"\n";
    std::cin.ignore();
    return 1;
}

int main()
{
    ContaBancaria conta;
    // std::cin.ignore();
    
    std::cout<<"\n\nPara iniciar o programa, \n digite o nome do titular da conta: "<<"\n";
    std::cin.getline(conta.nome_titular, 50);
    std::cout<<"\n\nAperte ""Enter"<<" para continuar..."<<"\n";
    std::cin.ignore();
    
    conta.numero_da_conta = 120;
    conta.saldo = 10.0;
    
    std::cout<<"Conta criada: "<<"\n";
    std::cout<<"Nome do titular: "<< conta.nome_titular <<"\n";
    std::cout<<"Número da conta: " << conta.numero_da_conta << "\n";
    std::cout<<"Saldo atual: " << conta.saldo<<"\n";
    
    while (true){
        int opcao;
        std::cout<<"---------- Menu ----------"<<"\n";
        std::cout<<"1. sacar"<<"\n";
        std::cout<<"2. depositar"<<"\n";
        std::cout<<"3. exibir saldo"<<"\n";
        std::cout<<"4. sair"<<"\n";
        
        std::cout<<"\n\nDigite a sua opção desejada: "<<"\n";
        std::cin>>opcao;
        std::cin.ignore();

        
        switch (opcao){
            case 1:
                sacar(conta);
                break;
            case 2:
                depositar(conta);
                break;
            case 3:
                exibir_saldo(conta);
                break;
            case 4:
                std::cout<<"Saindo..."<<"\n";
                return 0;
                break;
            default:
                std::cout<<"Opção inválida!"<<"\n";
                std::cout<<"Digite algo para voltar ao menu..."<<"\n";
                std::cin.ignore();
                break;

        }

    }
    
    return 0;
}