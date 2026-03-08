'''
Grafo é um conjunto de conexões formadas por vértices e arestas.
Pesquisa em largura é um algoritmo utilizado em Grafos para responder as seguintes perguntas:
1. Existe caminho de A até B?
2. Qual o caminho mais curto de A até B?

Nesse exemplo, criarei a classe Pessoa, que possui nome, faculdade como atributos. Nesse sentido, utilizarei um grafo para 
criar uma rede social e encontrar a pessoa mais próxima de mim que estuda na mesma faculdade que eu.
Essa implementação envolve a utilização de tabelas hashs e filas. 
'''
from collections import deque


class Pessoa:
    '''
        Define o nome e a faculdade de uma Pessoa.
    '''
    def __init__(self, nome, faculdade):
        self.nome = nome
        self.faculdade = faculdade

# Definindo os objetos
p1 = Pessoa('André', 'Cesar School')
p2 = Pessoa('Ana Clara', 'Uninassau')
p3 = Pessoa('Dayvid Cristano', 'Uninassau')
p4 = Pessoa('Luiz Henrique', 'UFPE')
p5 = Pessoa('Guilherme Godoy', 'UFRPE')
p6 = Pessoa('Matheus', 'FICR')
p7 = Pessoa('Lucas', 'UFPE')
p8 = Pessoa('Murilo', 'UFPE')
p9 = Pessoa('Rebeca', 'UPE')
p10 = Pessoa('Jeniffer', 'Cesar School')

# Criando o grafo

grafo = {}
grafo[p1] = [p2, p3, p4]
grafo[p2] = [p5, p7]
grafo[p3] = [p7, p6, p9]
grafo[p4] = [p8, p10]
grafo[p5] = []
grafo[p6] = [p10]
grafo[p7] = []
grafo[p8] = []
grafo[p9] = []
grafo[p10] = []

def verifica_faculdade(pessoa, faculdade):
    '''
        Verifica se alguém do grafo faz parte da faculdade enviada.
    '''
    return pessoa.faculdade == faculdade

def pesquisar(pessoa, faculdade):
    '''
        Recebe um grafo e encontra a pessoa mais próxima que estuda na faculdade enviada. 
    '''
    # 1. Criando uma fila
    fila = deque()
    fila += grafo[pessoa]
    verificadas = [] # lista de pessoas verificadas, evitando loop infinito

    while fila: # 5. repetindo o processo.
        
        pessoa = fila.popleft() # 2. Retirando a primeira pessoa da fila.

        if not pessoa in verificadas:
            
            if verifica_faculdade(pessoa, faculdade): # 3. Verificando se estuda na faculdade desejada.
                # 4. Se sim, busca concluida
                print(pessoa.nome + " é a mais próxima que estuda na " + faculdade)
                return True
            
            else:
                # 4. Se não, adicionando todos os vizinhos dessa pessoa ao final da fila.
                fila += grafo[pessoa]
                verificadas.append(pessoa)
                print(f'Passando por {pessoa.nome}')
        # Caso a fila fique vazia, não existem pessoas na sua rede que atendam àquele critério.
    return False


pesquisar(p1, 'Cesar School')