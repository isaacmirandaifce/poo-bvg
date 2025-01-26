from abc import ABC, abstractmethod

class Usuario:
    def __init__(self, nome, senha):
        self.nome = nome
        self._senha = senha  # Senha deve ser protegida e não acessível diretamente
    
    def get_nome(self):
        return self.nome
    
    def get_senha(self):
        return self._senha


class UsuarioAutenticavel(Usuario, ABC):
    @abstractmethod
    def autenticar(self, senha: str) -> bool:
        pass
