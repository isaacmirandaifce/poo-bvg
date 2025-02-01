from src.models.TipoUsuario import TipoUsuario

class Usuario():
    def __init__(self, nome='indefinido', email='indefinido', tipo=TipoUsuario.DEFAULT):
        # Construtor único e parametrizado com valores padrão
        self._nome = nome
        self._email = email
        self._tipo = tipo
    
