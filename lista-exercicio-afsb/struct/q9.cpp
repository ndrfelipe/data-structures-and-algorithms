#include <iostream>
#include <cstring>
#include <string>

typedef struct Paciente{
    char nome[50];
    int idade;
    char diagnostico[100];
}Paciente;

void exibirInfo(Paciente *paciente, int tamanho)
{   
    std::cout << "-----------Valores-------------" << "\n";
    for(int i=0; i<tamanho;i++){
        if(paciente[i].idade > 60){
            std::cout << "\nPaciente " << i+1 << "\n";

            std::cout << ". Nome: " << paciente[i].nome << "\n";
            std::cout << ". Idade: " << paciente[i].idade << "\n";
            std::cout << ". Diagnóstico: " << paciente[i].diagnostico << "\n";

        }
    }
    
    std::cout << "---------------------------------------------" << "\n";

}


int main()
{
    int qtd_paciente;
    std::cout<<"Digite a quantidade de pacientes: "<<"\n";
    std::cin>>qtd_paciente;
    
    Paciente paciente[qtd_paciente];
    
        for(int i = 0; i < qtd_paciente; i++){
            std::cin.ignore();
            std::cout<<"Digite o nome do paciente: " <<"\n";
            std::cin.getline(paciente[i].nome, 50);
            
            std::cout<<"Digite a idade do paciente: " <<"\n";
            std::cin>>paciente[i].idade;
            
            std::cin.ignore(); 
            std::cout<<"Digite o diagnóstico do paciente: " <<"\n";
            std::cin.getline(paciente[i].diagnostico, 100);
        }
        

    exibirInfo(paciente, qtd_paciente);
    return 0;
}