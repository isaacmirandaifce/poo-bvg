from src.models.Filtro import Filtro

# Classe de exemplo para testar o Filtro
class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def __repr__(self):
        return f"Pessoa(nome={self.nome}, idade={self.idade})"

# Criando o filtro para armazenar objetos do tipo Pessoa
filtro = Filtro[Pessoa]()

# Adicionando algumas pessoas ao filtro
filtro.adicionarElemento(Pessoa("Alice", 25))
filtro.adicionarElemento(Pessoa("Bob", 30))
filtro.adicionarElemento(Pessoa("Carlos", 22))
filtro.adicionarElemento(Pessoa("Diana", 28))

# Teste 1: Filtrar pessoas com idade maior que 25
print("\n🔎 Pessoas com mais de 25 anos:")
mais_de_25 = filtro.filtrarPorCondicao(lambda p: p.idade > 25)
for p in mais_de_25:
    print(p)

# Teste 2: Ordenar pessoas por idade
print("\n📌 Pessoas ordenadas por idade:")
filtro.ordenar(lambda p: p.idade)
filtro.imprimirTodos(print)

# Teste 3: Aplicar uma ação (exibir todas as pessoas)
print("\n📋 Lista de todas as pessoas:")
filtro.imprimirTodos(lambda p: print(f"{p.nome} tem {p.idade} anos"))
