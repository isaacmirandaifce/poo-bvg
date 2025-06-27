import enum

class TipoUsuario(enum.Enum):
    """
    Define os tipos de usuários no sistema. 
    """
    ALUNO = "Aluno"
    PROFESSOR = "Professor"
    FUNCIONARIO_ADMINISTRATIVO = "Funcionário Administrativo"