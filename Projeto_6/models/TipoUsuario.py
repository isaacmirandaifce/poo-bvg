from enum import Enum

class TipoUsuario(Enum):
    ADMIN = "ADMIN"
    AUDITOR = "AUDITOR"
    OPERADOR = "OPERADOR"