from aluno import Aluno
from professor import Professor
from funcionario import FuncionarioAdministrativo

def main():
    """
    Função principal para demonstrar as funcionalidades do sistema de gestão acadêmica.
    """
    # --- Criação dos Usuários ---
    aluno1 = Aluno(nome="Carlos Silva", id_usuario=101, senha="senha123", curso="Análise e Desenvolvimento de Sistemas")
    aluno1.adicionar_disciplina_cursada("Algoritmos", 2023, 8.5)
    aluno1.adicionar_disciplina_cursada("Banco de Dados", 2024, 9.0)

    prof1 = Professor(nome="Dra. Ana Costa", id_usuario=202, senha="prof_abc", departamento="Tecnologia")
    prof1.adicionar_disciplina("Programação Orientada a Objetos")
    prof1.adicionar_disciplina("Engenharia de Software")

    func1 = FuncionarioAdministrativo(nome="Roberto Dias", id_usuario=303, senha="admin#_1", cargo="Coordenador de Cursos")
    
    usuarios = [aluno1, prof1, func1]

    # --- Demonstração da Autenticação --- [cite: 11]
    print("### Teste de Autenticação ###\n")
    senha_aluno = "senha123"
    print(f"Tentando autenticar {aluno1.nome} com a senha '{senha_aluno}': {'Sucesso' if aluno1.autenticar(senha_aluno) else 'Falha'}")

    senha_errada_prof = "senha_errada"
    print(f"Tentando autenticar {prof1.nome} com a senha '{senha_errada_prof}': {'Sucesso' if prof1.autenticar(senha_errada_prof) else 'Falha'}")
    print("\n" + "="*40 + "\n")

    # --- Geração de Relatórios e Uso da Enumeração --- [cite: 13, 18]
    print("### Geração de Relatórios Polimórficos ###\n")
    for usuario in usuarios:
        # Uso da enumeração para categorizar a informação [cite: 13]
        print(f"Processando relatório para o usuário do tipo: {usuario.TIPO.value}") 
        
        # Chamada polimórfica do método da interface Relatorio
        usuario.gerar_relatorio()
        print()

if __name__ == "__main__":
    main()