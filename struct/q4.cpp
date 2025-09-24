#include <iostream>
#include <cstring>
#include <string>

typedef struct Carro{
    char modelo[30];
    int ano;
    float preco;
}Carro;

void exibirInfo(Carro *carro)
{
    std::cout << "------------------------" << "\n";
    std::cout << "Modelo do carro: " << carro->modelo <<std::endl;
    std::cout << "Ano do carro: " << carro->ano <<std::endl;
    std::cout << "Preço do carro: " << carro->preco <<std::endl;
    std::cout << "------------------------" << "\n";

}


int main()
{
    struct Carro *ptrCarro;
    
    ptrCarro = (struct Carro *)malloc(sizeof(struct Carro));
    
    if (ptrCarro == NULL)
    {   
        std::cout<<"Erro na alocação de memória. " << "\n";
        return 0;
    }
    
    std::cout<<"Insira o modelo do carro"<<"\n";
    std::cin>>ptrCarro->modelo;
    std::cout << "Insira o ano do carro "<<"\n";
    std::cin>>ptrCarro->ano;
    std::cout << "Insira o preço do carro"<<"\n";
    std::cin>>ptrCarro->preco;
    
    exibirInfo(ptrCarro);
    free(ptrCarro);
    ptrCarro = NULL;
    return 0;
}