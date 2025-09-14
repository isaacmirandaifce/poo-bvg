# main.py
from src.aluno import Aluno
from src.professor import Professor
from src.filtro import Filtro

def imprimir_lista(titulo: str, lista: list):
    """Função auxiliar para imprimir listas com um título formatado."""
    print(f"--- {titulo} ---")
    if not lista:
        print("Nenhum resultado encontrado.")
    else:
        for item in lista:
            print(item)
    print()

def main():
    """
    Função principal para instanciar e testar o Sistema Genérico de Filtragem (Projeto 7).
    """
    # --- Configuração dos Dados ---
    aluno1 = Aluno(nome="Carlos Silva", id_usuario=101, senha="123", curso="ADS")
    aluno1.adicionar_disciplina_historico("Programação Orientada a Objetos", 2024, 9.5)
    aluno1.adicionar_disciplina_historico("Banco de Dados", 2024, 8.0)

    aluno2 = Aluno(nome="Ana Pereira", id_usuario=102, senha="456", curso="Ciência da Computação")
    aluno2.adicionar_disciplina_historico("Estrutura de Dados", 2023, 6.5)
    aluno2.adicionar_disciplina_historico("Cálculo I", 2023, 5.0)

    aluno3 = Aluno(nome="Beatriz Lima", id_usuario=103, senha="789", curso="Ciência da Computação")
    aluno3.adicionar_disciplina_historico("Inteligência Artificial", 2025, 9.8)
    
    prof1 = Professor(nome="Dra. Ana Costa", id_usuario=201, senha="prof", departamento="Computação", 
                      disciplinas_ministradas=["Estrutura de Dados", "Inteligência Artificial"])
                      
    prof2 = Professor(nome="Dr. Mário Andrade", id_usuario=202, senha="prof", departamento="Matemática", 
                      disciplinas_ministradas=["Cálculo I", "Álgebra Linear"])

    # --- Requisitos do Projeto 7: Filtros e Relatórios ---
    print("### Execução dos Filtros e Ordenação do Projeto 7 ###\n")

    # 1. Filtrar alunos com média acima de 7.0
    filtro_alunos = Filtro()
    filtro_alunos.adicionar_elemento(aluno1)
    filtro_alunos.adicionar_elemento(aluno2)
    filtro_alunos.adicionar_elemento(aluno3)

    alunos_media_alta = filtro_alunos.filtrar_por_condicao(lambda a: a.calcular_media() > 7.0)
    imprimir_lista("Alunos com média acima de 7.0", alunos_media_alta)

    # 2. Listar professores que ministram uma disciplina específica ("Cálculo I")
    filtro_professores = Filtro()
    filtro_professores.adicionar_elemento(prof1)
    filtro_professores.adicionar_elemento(prof2)
    
    disciplina_busca = "Cálculo I"
    professores_da_disciplina = filtro_professores.filtrar_por_condicao(
        lambda p: disciplina_busca in p.disciplinas_ministradas
    )
    imprimir_lista(f"Professores que ministram '{disciplina_busca}'", professores_da_disciplina)

    # 3. Listar disciplinas cursadas por um aluno (Carlos) em um determinado ano (2024)
    filtro_historico_aluno = Filtro()
    for disciplina_cursada in aluno1.historico: 
        filtro_historico_aluno.adicionar_elemento(disciplina_cursada)
    
    ano_busca = 2024
    historico_filtrado = filtro_historico_aluno.filtrar_por_condicao(
        lambda item: item.ano_cursado == ano_busca
    )
    imprimir_lista(f"Disciplinas cursadas por {aluno1.nome} em {ano_busca}", historico_filtrado)

    # --- Funcionalidade Adicional: Ordenação Genérica ---
    print("--- Demonstração de Ordenação de Alunos ---")

    filtro_alunos.ordenar(chave=lambda aluno: aluno.nome)
    print("Alunos ordenados por nome (A-Z):")
    filtro_alunos.aplicar_acao(print)
    print()

    filtro_alunos.ordenar(chave=lambda aluno: aluno.calcular_media(), reverso=True)
    print("Alunos ordenados por média (decrescente):")
    filtro_alunos.aplicar_acao(print)

if __name__ == "__main__":
    main()