#include <iostream>
#include <cstring>

const int QTD_ALUNOS = 5;

typedef struct Aluno{
    char nome[50];
    int matricula;
    float nota;
}Aluno;

int main()
{
    Aluno aluno[QTD_ALUNOS];
    double soma_notas = 0.0;
   
    
    for(int i = 0; i < QTD_ALUNOS; i++)
    {
        std::cout<<"Insira o nome do aluno "<< i+1<<"\n";
        std::cin>>aluno[i].nome;
        std::cout << "Insira a matricula do aluno "<< i+1 <<"\n";
        std::cin>>aluno[i].matricula;
        std::cout << "Insira a nota do aluno "<< i+1 <<"\n";
        std::cin>>aluno[i].nota;
        
        soma_notas = soma_notas + aluno[i].nota;
    }
    
    double media = soma_notas / QTD_ALUNOS;
    std::cout<<"Média das notas é: "<< media << "\n";
    return 0;
}