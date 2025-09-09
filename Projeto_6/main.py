# main.py
from src.aluno import Aluno
from src.professor import Professor
from src.funcionario_administrativo import FuncionarioAdministrativo
from src.tipo_usuario import TipoUsuario

def main():
    """
    Função principal para instanciar e testar o Sistema de Gestão Acadêmica.
    """
    aluno1 = Aluno(nome="Carlos Silva", id_usuario=101, senha="senha123", curso="Análise e Desenvolvimento de Sistemas")
    aluno1.adicionar_disciplina_historico("Programação Orientada a Objetos", 2024, 9.5)

    prof1 = Professor(nome="Dra. Ana Costa", id_usuario=201, senha="prof_abc", departamento="Ciência da Computação")
    func1 = FuncionarioAdministrativo(nome="José Almeida", id_usuario=301, senha="adm_xyz", cargo="Secretário Acadêmico")

    usuarios = [aluno1, prof1, func1]

    print("### Geração de Relatórios e Categorização por Tipo ###")
    for usuario in usuarios:
        if usuario.tipo == TipoUsuario.ALUNO:
            print(f">>> Processando ALUNO: {usuario.nome}")
        elif usuario.tipo == TipoUsuario.PROFESSOR:
            print(f">>> Processando PROFESSOR: {usuario.nome}")
        elif usuario.tipo == TipoUsuario.FUNCIONARIO_ADMINISTRATIVO:
            print(f">>> Processando FUNCIONÁRIO: {usuario.nome}")
        
        usuario.gerar_relatorio()

if __name__ == "__main__":
    main()