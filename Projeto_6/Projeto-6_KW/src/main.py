from .aluno import Aluno
from .relatorio import Relatorio
from .usuarioAutenticavel import UsuarioAutenticavel

nome = input("Digite o nome do aluno: ")
cenha = input("Digite a senha do aluno: ")
aluno1 = ("Maria", "1234")
professor1 = ("João", "abcd")
Aluno = Aluno(nome, cenha)
if Aluno.autenticar(cenha):
    print(f"Bem-vindo, {Aluno.nome}!")
    Aluno.historico.adicionar_disciplina("Matemática", 2023, 9.5)
    Aluno.historico.adicionar_disciplina("História", 2023, 8.0)
    Aluno.gerar_relatorio()
else:
    print("Senha incorreta. Acesso negado.")

