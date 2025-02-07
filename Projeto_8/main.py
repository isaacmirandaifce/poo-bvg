import sys
import os

# Adiciona o diretório 'src' ao caminho do sistema para facilitar importações
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

from models.aluno import Aluno
from models.professor import Professor
from models.persistencia import Persistencia
from util.filtro import Filtro
import models.sinalHandler
from models.autenticavel import UsuarioAutenticavel
from models.disciplina import Disciplina

# Carregar dados na inicialização
alunos_dicionarios = Persistencia.carregar_dados("alunos.txt")
alunos = [Aluno.from_dict(dado) for dado in alunos_dicionarios]  # Reconstruir objetos Aluno a partir de dicionários
filtro_alunos = Filtro[Aluno]()  # Criando um filtro genérico

# Se não tiver aluno salvo, a gente adiciona
if not alunos:
    aluno1 = Aluno(UsuarioAutenticavel("Zezim Baiao", "ZezinhoBaiao@email.com", "senha123"), "202301", "ADS")
    aluno1.adicionar_disciplina(Disciplina("POO", 60))
    aluno1.historico[0].set_nota(8.5)
    
    aluno2 = Aluno(UsuarioAutenticavel("Jose Arruda", "MacacoLouco477@email.com", "senha456"), "202302", "ADS")
    aluno2.adicionar_disciplina(Disciplina("POO", 60))
    aluno2.historico[0].set_nota(7.2)
    
    aluno3 = Aluno(UsuarioAutenticavel("Carla Perez", "carlinhasantana@email.com", "senha789"), "202203", "ADS")
    aluno3.adicionar_disciplina(Disciplina("POO", 60))
    aluno3.historico[0].set_nota(6.5)
    
    alunos = [aluno1, aluno2, aluno3]
    Persistencia.salvar_dados("alunos.txt", alunos)  # Salva os dados
else:
    alunos = [Aluno.from_dict(dado) for dado in alunos_dicionarios]  # Reconstruir objetos Aluno
    
# Adicionar alunos ao filtro
for aluno in alunos:
    filtro_alunos.adicionar_elemento(aluno)
    
# Filtrar alunos aprovados
def aluno_aprovado(aluno):
    disciplinas = aluno.listar_disciplinas()
    
    if not disciplinas:  # Se não há disciplinas, não tem como aprovar
        return False
    
    # Calcula a média das disciplinas
    media = sum(disciplina.get_nota() for disciplina in disciplinas) / len(disciplinas)
    return media >= 7.0  # A aprovação só acontece se a média for 7

# Filtrar alunos reprovados
def aluno_reprovado(aluno):
    return not aluno_aprovado(aluno)

# Obter lista de alunos aprovados e reprovados
alunos_aprovados = filtro_alunos.filtrar_por_condicao(aluno_aprovado)
alunos_reprovados = filtro_alunos.filtrar_por_condicao(aluno_reprovado)
     
# Exibir alunos carregados
print("Alunos carregados: ")
for aluno in alunos_aprovados:
    print(f"{aluno.UsuarioAutenticavel.nome} - Curso: {aluno.curso}")
    
# Exibir apenas alunos reprovados
print("\nAlunos Reprovados:")
for aluno in alunos_reprovados:
    print(f"{aluno.UsuarioAutenticavel.nome} - Curso: {aluno.curso}")
    
# Manter o programa rodando até ser interrompido
while True:
    pass
