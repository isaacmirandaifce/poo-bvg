# main.py
from src.sistema_academico import SistemaAcademico
from src.sinal_handler import SinalHandler
from src.professor import Professor # Importe a classe Professor

def exibir_menu():
    """Exibe o menu de opções atualizado."""
    print("\n--- Sistema de Gestão Acadêmica v8.0 ---")
    print("1. Listar todos os Alunos")
    print("2. Adicionar novo Aluno")
    print("3. Listar todos os Professores")
    print("4. Adicionar novo Professor")
    print("5. Forçar Falha de Segmentação (Teste SIGSEGV)")
    print("6. Sair (ou pressione Ctrl+C)")
    return input("Escolha uma opção: ")

def main():
    """Função principal que orquestra a aplicação."""
    
    SinalHandler.inicializar()

    # A variável 'sistema' é criada aqui, no início da função main.
    sistema = SistemaAcademico()
    sistema.carregar_dados_iniciais()
    # -------------------

    # Loop interativo para testar a aplicação
    while True:
        opcao = exibir_menu()
        
        if opcao == '1':
            print("\n--- Lista de Alunos ---")
            if not sistema.alunos:
                print("Nenhum aluno cadastrado.")
            for aluno in sistema.alunos:
                print(aluno)
        
        elif opcao == '2':
            print("\n--- Adicionar Novo Aluno ---")
            try:
                nome = input("Nome: ")
                id_usuario = int(input("ID do Usuário: "))
                senha = input("Senha: ")
                curso = input("Curso: ")
                sistema.adicionar_aluno(nome, id_usuario, senha, curso)
            except ValueError:
                print("ERRO: O ID do usuário deve ser um número.")
        
        elif opcao == '3':
            print("\n--- Lista de Professores ---")
            if not sistema.professores:
                print("Nenhum professor cadastrado.")
            for prof in sistema.professores:
                print(prof)
        
        elif opcao == '4':
            print("\n--- Adicionar Novo Professor ---")
            try:
                nome = input("Nome: ")
                id_usuario = int(input("ID do Usuário: "))
                senha = input("Senha: ")
                departamento = input("Departamento: ")
                disciplinas_str = input("Disciplinas (separadas por vírgula): ")
                disciplinas = [d.strip() for d in disciplinas_str.split(',')]
                sistema.adicionar_professor(nome, id_usuario, senha, departamento, disciplinas)
            except ValueError:
                print("ERRO: O ID do usuário deve ser um número.")

        elif opcao == '5':
            print("\nAVISO: O programa irá forçar uma falha de segmentação para testar o handler SIGSEGV.")
            print("Isso irá encerrar a aplicação.")
            import ctypes
            ctypes.string_at(0) # Causa uma falha de segmentação
        
        elif opcao == '6':
            sistema.salvar_todos_os_dados()
            break
        
        else:
            print("Opção inválida. Tente novamente.")

    print("Programa encerrado.")

# Garante que a função main() seja chamada quando o script é executado
if __name__ == "__main__":
    main()