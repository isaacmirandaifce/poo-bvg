from abc import ABC, abstractmethod

class Usuario:
    def __init__(self, nome, email):
        self.nome = nome
        self.email = email

class UsuarioAutenticavel(Usuario, ABC):
    @abstractmethod
    def autenticar(self, senha: str) -> bool:
        pass