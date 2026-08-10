from abc import ABC, abstractmethod

class Usuario:
    def __init__(self, user_id: int, username: str):
        self.id = user_id
        self.username = username

class UsuarioAutenticavel(Usuario, ABC):
    def __init__(self, user_id: int, username: str, senha_sistema: str):
        super().__init__(user_id, username)
        self.__senha_sistema = senha_sistema 

    @abstractmethod
    def autenticar(self, senha: str) -> bool:
        pass
    
    def _verificar_senha(self, senha_tentativa: str) -> bool:
        return self.__senha_sistema == senha_tentativa