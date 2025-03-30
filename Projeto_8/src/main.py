# import sys
# import os

# sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "src")))

# from models.Aluno import Aluno  # Agora as importações devem funcionar
# from src.models.Aluno import Aluno
# from src.models.Filtro import Filtro

# filtro_alunos = Filtro[Aluno]()

# # Adicionando alunos
# filtro_alunos.adicionarElemento(Aluno(nome="Carlos", matricula="123", curso="ADS", disciplinas="Matemática", senha="1234"))
# filtro_alunos.adicionarElemento(Aluno(nome="Ana", matricula="456", curso="ADS", disciplinas="Física", senha="abcd"))
# filtro_alunos.adicionarElemento(Aluno(nome="Marcos", matricula="789", curso="Engenharia", disciplinas="Matemática", senha="xyz"))

# # Filtrar alunos com base em uma condição (ex: curso ADS)
# alunos_ads = filtro_alunos.filtrarPorCondicao(lambda aluno: aluno._curso == "ADS")

# # Imprimir os alunos filtrados
# filtro_alunos.imprimirTodos(lambda aluno: print(aluno.gerarRelatorio()))

# # Ordenar alunos por nome
# filtro_alunos.ordenar(lambda aluno: aluno._nome)
# filtro_alunos.imprimirTodos(lambda aluno: print(aluno.gerarRelatorio()))
