from models.aluno import Aluno
from models.professor import Professor
from util.filtro import Filtro

# Funções auxiliares para melhorar a legibilidade
def criar_aluno(nome, email, senha, ano_ingresso, curso, disciplinas):
    """Cria e retorna um objeto Aluno com histórico de disciplinas."""
    aluno = Aluno(nome, email, senha, ano_ingresso, curso)
    for disciplina, ano, nota in disciplinas:
        aluno.historico.adicionar_disciplina(disciplina, ano, nota)
    return aluno

def criar_professor(nome, email, senha, departamento, disciplinas):
    """Cria e retorna um objeto Professor com disciplinas ministradas."""
    professor = Professor(nome, email, senha, departamento)
    for disciplina in disciplinas:
        professor.adicionar_disciplina(disciplina)
    return professor

# Criando filtros para alunos e professores
filtro_alunos = Filtro[Aluno]()
filtro_professores = Filtro[Professor]()

# Adicionando alunos ao filtro
alunos = [
    criar_aluno("Zezim Baiao", "ZezinhoBaiao@email.com", "senha123", "202301", "ADS", [
        ("POO", 2025, 8.5),
        ("IHC", 2023, 6.5)
    ]),
    criar_aluno("Jose Arruda", "MacacoLouco477@email.com", "senha456", "202302", "ADS", [
        ("POO", 2023, 7.2),
        ("IHC", 2023, 5.0)
    ]),
    criar_aluno("Carla Perez", "carlinhasantana@email.com", "senha789", "202303", "ADS", [
        ("POO", 2023, 0.0),
        ("IHC", 2023, 0.0)
    ])
]

for aluno in alunos:
    filtro_alunos.adicionar_elemento(aluno)

# Adicionando professores ao filtro
professores = [
    criar_professor("Ze Paulo", "carretafuriosa@email.com", "senha123", "Matemática", ["POO", "Eng. Software"]),
    criar_professor("Beatriz Pessoa", "pessoaB@email.com", "senha456", "História", ["Redes", "Sociologia"])
]

for professor in professores:
    filtro_professores.adicionar_elemento(professor)

# Funções de filtragem
def aluno_aprovado(aluno):
    """Retorna True se o aluno tiver média >= 7.0."""
    disciplinas = aluno.historico.listar_disciplinas()
    if not disciplinas:
        return False
    media = sum(d["nota"] for d in disciplinas) / len(disciplinas)
    return media >= 7.0

def aluno_reprovado(aluno):
    """Retorna True se o aluno tiver média < 7.0."""
    return not aluno_aprovado(aluno)

def disciplinas_por_ano(aluno, ano):
    """Retorna as disciplinas cursadas por um aluno em um determinado ano."""
    return [d["nome"] for d in aluno.historico.listar_disciplinas() if d["ano"] == ano]

def professor_ministra_disciplina(professor, disciplina):
    """Retorna True se o professor ministra a disciplina especificada."""
    return disciplina in professor.disciplinas_ministradas

# Filtrando alunos aprovados e reprovados
alunos_aprovados = filtro_alunos.filtrar_por_condicao(aluno_aprovado)
alunos_reprovados = filtro_alunos.filtrar_por_condicao(aluno_reprovado)

# Filtrando professores por disciplina
disciplina_desejada = "POO"
professores_disciplina = filtro_professores.filtrar_por_condicao(
    lambda prof: professor_ministra_disciplina(prof, disciplina_desejada)
)

# Exibindo resultados
print("Alunos Aprovados:")
for aluno in alunos_aprovados:
    print(f"{aluno.usuario_autenticavel.nome} - Curso: {aluno.curso} - Email: {aluno.usuario_autenticavel.email}")

print("\nAlunos Reprovados:")
for aluno in alunos_reprovados:
    print(f"{aluno.usuario_autenticavel.nome} - Curso: {aluno.curso} - Email: {aluno.usuario_autenticavel.email}")

ano_desejado = 2025
disciplinas_ano = disciplinas_por_ano(alunos[0], ano_desejado)
print(f"\nDisciplinas de {alunos[0].usuario_autenticavel.nome} em {ano_desejado}: {', '.join(disciplinas_ano)}")

print(f"\nProfessores que ensinam {disciplina_desejada}:")
for professor in professores_disciplina:
    print(f"{professor.usuario_autenticavel.nome}")