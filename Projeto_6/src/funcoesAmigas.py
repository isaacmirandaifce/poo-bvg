def verificarAprovacao(disciplina):
    """
    Verifica se o aluno foi aprovado em uma disciplina.
    Aprovado com nota >= 6.0.
    """
    nota = disciplina.get_nota()
    return nota >= 6.0
