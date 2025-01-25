from src.models.Professor import Professor


def test_professor_autenticacao():
    """
    Testa a autenticação do professor com senha válida e inválida.
    """
    professor = Professor(
        nome="Carlos Silva",
        email="carlos@universidade.com",
        tipo="Professor",
        senha="12345",
        areaDeAtuacao="Matemática",
        disciplinasMinistradas=["Cálculo I", "Álgebra Linear"]
    )

    # Teste de autenticação com senha correta
    assert professor.autenticar("12345"), "Autenticação deveria ser válida com a senha correta."

    # Teste de autenticação com senha incorreta
    assert not professor.autenticar("54321"), "Autenticação não deveria ser válida com uma senha incorreta."


def test_professor_gerar_relatorio():
    """
    Testa a geração de relatório do professor.
    """
    professor = Professor(
        nome="Ana Paula",
        email="ana@universidade.com",
        tipo="Professor",
        senha="senha123",
        areaDeAtuacao="Física",
        disciplinasMinistradas=["Física I", "Física II"]
    )
    print('Relatório: ')
    print(professor.gerarRelatorio())

    relatorio = professor.gerarRelatorio()
    
    # Verifica se o relatório contém as informações corretas
    assert "Nome: Ana Paula" in relatorio, "O relatório deveria conter o nome do professor."
    assert "Área de Atuação: Física" in relatorio, "O relatório deveria conter a área de atuação do professor."
    assert "Disciplinas Ministradas: Física I, Física II" in relatorio, "O relatório deveria conter as disciplinas ministradas."


def test_professor_gerar_relatorio_sem_disciplinas():
    """
    Testa a geração de relatório do professor sem disciplinas cadastradas.
    """
    professor = Professor(
        nome="Lucas Pereira",
        email="lucas@universidade.com",
        tipo="Professor",
        senha="lucas123",
        areaDeAtuacao="Química"
    )

    relatorio = professor.gerarRelatorio()

    # Verifica se o relatório lida corretamente com a ausência de disciplinas
    assert "Disciplinas Ministradas: Nenhuma disciplina cadastrada" in relatorio, (
        "O relatório deveria indicar que nenhuma disciplina foi cadastrada."
    )


if __name__ == "__main__":
    print("Testando autenticação do professor...")
    test_professor_autenticacao()
    print("Autenticação: OK!")

    print("Testando geração de relatório com disciplinas...")
    test_professor_gerar_relatorio()
    print("Relatório com disciplinas: OK!")

    print("Testando geração de relatório sem disciplinas...")
    test_professor_gerar_relatorio_sem_disciplinas()
    print("Relatório sem disciplinas: OK!")
