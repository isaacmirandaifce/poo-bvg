from src.aluno import Aluno
from src.professor import Professor
from src.funcionarioAdministrativo import FuncionarioAdministrativo
from src.tipoUsuario import TipoUsuario

def teste_aluno():
    aluno = Aluno("Maria", "1234")
    assert aluno.autenticar("1234") is True
    assert aluno.autenticar("errada") is False
    assert aluno.tipo == TipoUsuario.ALUNO
    aluno.historico.adicionar_disciplina("Matemática", 2023, 9.5)
    aluno.historico.adicionar_disciplina("História", 2023, 8.0)
    assert len(aluno.historico.disciplinas) == 2
    aluno.gerar_relatorio()
    print("Teste Aluno OK")

def teste_professor():
    professor = Professor("João", "abcd", "Matemática")
    assert professor.autenticar("abcd") is True
    assert professor.autenticar("errada") is False
    assert professor.tipo == TipoUsuario.PROFESSOR
    assert professor.disciplina == "Matemática"
    professor.gerar_relatorio()
    print("Teste Professor OK")

def teste_funcionario_administrativo():
    funcionario = FuncionarioAdministrativo("Ana", "adm123", "Secretaria")
    assert funcionario.autenticar("adm123") is True
    assert funcionario.autenticar("errada") is False
    assert funcionario.tipo == TipoUsuario.FUNCIONARIO_ADMINISTRATIVO
    assert funcionario.setor == "Secretaria"
    funcionario.gerar_relatorio()
    print("Teste FuncionarioAdministrativo OK")

if __name__ == "__main__":
    teste_aluno()
    teste_professor()
    teste_funcionario_administrativo()