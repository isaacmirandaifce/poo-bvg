# /Projeto_7/main.py

from models import Aluno, Professor, Disciplina, Matricula
from filtro import Filtro

# --- 1. Configuração do Cenário ---
# Criando disciplinas
d_calculo = Disciplina(nome="Cálculo I", codigo="MAT101")
d_poo = Disciplina(nome="Programação Orientada a Objetos", codigo="COMP102")
d_fisica = Disciplina(nome="Física Clássica", codigo="FIS101")

# Criando alunos e suas matrículas
aluno1 = Aluno(nome="João Silva", matricula_id="2023001")
aluno1.historico.append(Matricula(disciplina=d_calculo, ano=2023, nota_final=8.5))
aluno1.historico.append(Matricula(disciplina=d_poo, ano=2023, nota_final=9.5))

aluno2 = Aluno(nome="Maria Souza", matricula_id="2023002")
aluno2.historico.append(Matricula(disciplina=d_calculo, ano=2023, nota_final=6.5))
aluno2.historico.append(Matricula(disciplina=d_fisica, ano=2024, nota_final=7.5))

aluno3 = Aluno(nome="Pedro Costa", matricula_id="2023003")
aluno3.historico.append(Matricula(disciplina=d_poo, ano=2024, nota_final=6.0))

# Criando professores
prof1 = Professor(nome="Dr. Carlos Andrade", departamento="Matemática", disciplinas_lecionadas=[d_calculo])
prof2 = Professor(nome="Dra. Ana Beatriz", departamento="Computação", disciplinas_lecionadas=[d_poo, d_fisica])

# --- 2. Utilização do Filtro Genérico ---

# Criando filtros para diferentes tipos de objetos
filtro_alunos = Filtro[Aluno]()
filtro_alunos.adicionar_elemento(aluno1)
filtro_alunos.adicionar_elemento(aluno2)
filtro_alunos.adicionar_elemento(aluno3)

filtro_professores = Filtro[Professor]()
filtro_professores.adicionar_elemento(prof1)
filtro_professores.adicionar_elemento(prof2)

print("--- Sistema Genérico de Filtragem e Relatórios Acadêmicos ---")

# REQUISITO: Filtrar alunos com média acima de 7.0 [cite: 10]
print("\n[+] Alunos com média geral acima de 7.0:")
alunos_aprovados = filtro_alunos.filtrar_por_condicao(lambda a: a.calcular_media_geral() > 7.0)
for aluno in alunos_aprovados:
    print(f" - {aluno.nome} (Média: {aluno.calcular_media_geral():.2f})")

# REQUISITO: Listar professores que ministram uma disciplina específica (POO) [cite: 11]
print(f"\n[+] Professores que ministram '{d_poo.nome}':")
profs_poo = filtro_professores.filtrar_por_condicao(
    lambda p: any(d.codigo == d_poo.codigo for d in p.disciplinas_lecionadas)
)
for prof in profs_poo:
    print(f" - {prof.nome}")

# REQUISITO: Listar disciplinas cursadas por um aluno em um determinado ano (Maria, 2024) [cite: 11]
print(f"\n[+] Disciplinas cursadas por {aluno2.nome} em 2024:")
disciplinas_aluno2_2024 = [m.disciplina.nome for m in aluno2.historico if m.ano == 2024]
for disciplina_nome in disciplinas_aluno2_2024:
    print(f" - {disciplina_nome}")

# REQUISITO ADICIONAL: Ordenação Genérica [cite: 12, 21]
print("\n[+] Lista de todos os alunos (ordenados por nome):")
filtro_alunos.ordenar(chave=lambda a: a.nome)
filtro_alunos.aplicar_acao_em_todos(lambda a: print(f" - {a.nome}"))

print("\n[+] Lista de todos os alunos (ordenados por média geral decrescente):")
filtro_alunos.ordenar(chave=lambda a: a.calcular_media_geral(), reverso=True)
filtro_alunos.aplicar_acao_em_todos(
    lambda a: print(f" - {a.nome} (Média: {a.calcular_media_geral():.2f})")
)