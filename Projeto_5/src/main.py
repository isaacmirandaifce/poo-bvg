from aluno import Aluno
from professor import Professor
from funcionario_administrativo import FuncionarioAdministrativo
from monitor import Monitor

# Criando objetos
aluno = Aluno("João", "joao@example.com", "20231001", "Engenharia")
aluno.adicionar_disciplina("Cálculo")
aluno.adicionar_disciplina("Física")

professor = Professor("Dr. Silva", "silva@example.com", "Matemática", ["Cálculo", "Álgebra"])

funcionario = FuncionarioAdministrativo("Maria", "maria@example.com", "Secretaria", "Assistente Administrativo")

# Exibindo relatórios
print("Relatório do Aluno:")
print(aluno.gerar_relatorio())
print("-" * 40)

print("Relatório do Professor:")
print(professor.gerar_relatorio())
print("-" * 40)

print("Relatório do Funcionário Administrativo:")
print(funcionario.gerar_relatorio())
print("-" * 40)

# Exibindo detalhes com notas
print("Detalhes do Aluno com Notas:")
print(aluno.exibir_detalhes(incluir_notas=True))
print("-" * 40)


