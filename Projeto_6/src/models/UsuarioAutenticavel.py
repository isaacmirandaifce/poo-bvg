from src.models.Usuario import Usuario
from abc import ABC, abstractmethod
from src.models.TipoUsuario import TipoUsuario

class UsuarioAutenticavel (Usuario, ABC):
    def __init__(self, nome='indefinido', email='indefinido', tipo=TipoUsuario.DEFAULT,senha=''):
        # Chamando o construtor da classe Usuario
        super().__init__(nome, email, tipo)

        self._senha = senha

    @abstractmethod
    def autenticar(self, senha) -> bool:
        """
        Método abstrato que será implementado nas subclasses.
        Verifica se a senha passada é válida.
        """
        pass