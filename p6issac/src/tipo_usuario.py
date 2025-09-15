tipo_usuario.py
from enum import Enum, auto

class TipoUsuario(Enum):
    """
    Enumeração que define os tipos de usuários no sistema.
    """
    ALUNO = auto()
    PROFESSOR = auto()
    FUNCIONARIO_ADMINISTRATIVO = auto()