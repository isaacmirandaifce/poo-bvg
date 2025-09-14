# src/usuario_autenticavel.py
from abc import ABC, abstractmethod
from .usuario import Usuario
from .tipo_usuario import TipoUsuario

class UsuarioAutenticavel(Usuario, ABC):
    def __init__(self, nome: str, id_usuario: int, tipo: TipoUsuario, senha: str):
        super().__init__(nome, id_usuario, tipo)
        self._senha = senha

    @abstractmethod
    def autenticar(self, senha: str) -> bool:
        pass