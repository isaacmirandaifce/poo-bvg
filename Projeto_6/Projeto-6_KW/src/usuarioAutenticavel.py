from abc import ABC, abstractmethod

class UsuarioAutenticavel(ABC):
    def __init__(self, nome: str, senha: str):
        self._nome = nome
        self.__senha = senha  # senha encapsulada

    def _verificar_senha(self, senha: str) -> bool:
        return self.__senha == senha

    @abstractmethod
    def autenticar(self, senha: str) -> bool:
        pass

    @property
    def nome(self):
        return self._nome