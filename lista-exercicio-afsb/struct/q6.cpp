#include <iostream>
#include <cstring>
#include <string>

typedef struct Book{
    char title[50];
    char author[50];
    int published_at;
}Book;

void exibirInfo(Book *book, int size_vector, int published_at)
{   
    std::cout << "-----------Books-------------" << "\n";
    for(int i=0;i < size_vector;i++)
    {
        if(book[i].published_at == published_at){
            std::cout << i+1 <<". Título: " << book[i].title <<" | Autor: "<< book[i].author << " | Ano de publicação: "<< book[i].published_at <<"\n";
        }
    }
    std::cout << "---------------------------------------------" << "\n";

}


int main()
{
    int qtd_livros;
    int ano_publicacao;
    
    std::cout << "Digite quantos Livros você deseja cadastrar: " << std::endl;
    std::cin>>qtd_livros;
    
    struct Book book[qtd_livros];

    
    for (int i = 0; i < qtd_livros; i++)
    {
        std::cin.ignore(); 
        std::cout<<"Digite o título do livro: " << i+1 <<"\n";
        
        std::cin.getline(book[i].title, 50);
        //std::cin>>book[i].title;
        
        std::cout<<"Digite o autor do livro: " << i+1 <<"\n";
        std::cin.getline(book[i].author, 50);
        //std::cin>>book[i].author;
        
        std::cout<<"Digite o ano de publicação do livro: " << i+1 <<"\n";
        std::cin>>book[i].published_at;

    }
    
    std::cout << "Digite o ano de publicação do livro que você deseja buscar: " << std::endl;
    std::cin >>ano_publicacao;
    exibirInfo(book, qtd_livros, ano_publicacao);
    return 0;
}