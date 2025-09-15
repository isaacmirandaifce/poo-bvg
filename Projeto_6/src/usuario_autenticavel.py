from abc import ABC, abstractmethod
from usuario import Usuario

class UsuarioAutenticavel(Usuario, ABC):
    def __init__(self, nome: str, login: str, senha: str, tipo_usuario):
        super().__init__(nome, login, tipo_usuario)
        self.__senha = senha

    @abstractmethod
    def autenticar(self, senha: str) -> bool:
        pass

    def _verificar_senha(self, senha: str) -> bool:
        return self.__senha == senha
