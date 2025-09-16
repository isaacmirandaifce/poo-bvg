from aluno import Aluno
from professor import Professor
from funcionario_administrativo import FuncionarioAdministrativo
from filtro import Filtro

# Criando instâncias de alunos, professores e funcionários
aluno1 = Aluno("Kaique", 1, "Engenharia", [7.5, 8.0, 6.5])
aluno2 = Aluno("Maria", 2, "Medicina", [9.0, 8.5, 7.5])
professor1 = Professor("Carlos", 101, "Matemática")
professor2 = Professor("Ana", 102, "Física")
funcionario1 = FuncionarioAdministrativo("João", 201, "Secretaria")

# Criando um filtro para alunos
filtro_alunos = Filtro[Aluno]()
filtro_alunos.adicionar_elemento(aluno1)
filtro_alunos.adicionar_elemento(aluno2)

# Filtrando alunos com média maior que 7.0
alunos_filtrados = filtro_alunos.filtrar_por_condicao(lambda aluno: aluno.media() > 7.0)

# Imprimindo os alunos filtrados
print("Alunos com média acima de 7.0:")
filtro_alunos.imprimir_todos(lambda aluno: print(aluno.nome))

# Criando um filtro para professores
filtro_professores = Filtro[Professor]()
filtro_professores.adicionar_elemento(professor1)
filtro_professores.adicionar_elemento(professor2)

# Filtrando professores do departamento de Matemática
professores_filtrados = filtro_professores.filtrar_por_condicao(lambda professor: professor.departamento == "Matemática")

# Imprimindo os professores filtrados
print("\nProfessores do departamento de Matemática:")
filtro_professores.imprimir_todos(lambda professor: print(professor.nome))
