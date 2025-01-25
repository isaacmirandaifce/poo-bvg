from enum import Enum

class TipoUsuario(Enum):
    ALUNO = "Aluno"
    PROFESSOR = "Professor"
    FUNCIONARIO_ADMINISTRATIVO = "Funcionário Administrativo"
    MONITOR = "Monitor"
    DEFAULT = "indefinido"