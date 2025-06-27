# main.py1

import time
from persistencia import carregar_dados, salvar_dados, dados_em_memoria
from modelos import Aluno
from excecoes import ErroPersistencia
import sinal_handler

def menu_principal():
    """Exibe o menu e gerencia a interação com o usuário."""
    while True:
        print("\n--- Sistema de Gerenciamento Acadêmico Resiliente ---")
        print("Dados Atuais:")
        print("  Alunos:", dados_em_memoria["alunos"])
        print("  Professores:", dados_em_memoria["professores"])
        print("  Disciplinas:", dados_em_memoria["disciplinas"])
        print("\nOpções:")
        print("  1. Adicionar Novo Aluno")
        print("  2. Sair (ou pressione Ctrl+C)")
        
        escolha = input("Escolha uma opção: ")

        if escolha == '1':
            try:
                novo_id = int(input("Digite o ID do novo aluno: "))
                nome_aluno = input("Digite o nome do novo aluno: ")
                
                novo_aluno = Aluno(id=novo_id, nome=nome_aluno)
                dados_em_memoria["alunos"].append(novo_aluno)
                
                print(f"Aluno '{nome_aluno}' adicionado com sucesso!")
                
                # Salva os dados automaticamente após uma modificação relevante 
                salvar_dados()

            except ValueError:
                print("ID inválido. Por favor, insira um número.")
            except ErroPersistencia as e:
                # Exibe mensagens informativas quando erros ocorrem 
                print(f"[ERRO] {e}")

        elif escolha == '2':
            break
        else:
            print("Opção inválida. Tente novamente.")

def main():
    """Função principal da aplicação."""
    # Inicializa o manipulador de sinais [cite: 20]
    sinal_handler.inicializar()

    # Tenta carregar os dados iniciais e trata possíveis erros [cite: 27]
    try:
        carregar_dados() # Carrega dados de alunos, professores e disciplinas 
    except ErroPersistencia as e:
        print(f"Erro crítico ao carregar dados: {e}")
        # Oferece opções ao usuário quando erros ocorrem 
        input("Pressione Enter para continuar com o sistema vazio...")
    
    # Inicia o menu principal
    menu_principal()

    print("\nPrograma finalizado.")

if __name__ == "__main__":
    main()