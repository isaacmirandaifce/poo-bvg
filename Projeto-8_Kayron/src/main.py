from .aluno import Aluno
from .relatorio import Relatorio
from .usuarioAutenticavel import UsuarioAutenticavel
from persistencia import salvar_dados_csv, carregar_dados_csv
from sinais import registrar_sinais

def main():
    registrar_sinais()
    # Exemplo de uso das classes e funções
    try:
        dados = carregar_dados_csv("dados.csv")
        for linha in dados:
            aluno = Aluno(linha["nome"], linha["senha"])
            print(aluno)
            print(aluno.gerar_relatorio())
            if aluno.autenticar(linha["senha"]):
                print("Usuário autenticado com sucesso.")
            else:
                print("Falha na autenticação do usuário.")
        
    except Exception as e:
        print(f"Ocorreu um erro: {e}")

if __name__ == "__main__":
    main()
