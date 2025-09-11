# src/usuario.py
from .tipo_usuario import TipoUsuario

class Usuario:
    def __init__(self, nome: str, id_usuario: int, tipo: TipoUsuario):
        self._nome = nome
        self._id_usuario = id_usuario
        self._tipo = tipo

    @property
    def nome(self) -> str:
        return self._nome

    @property
    def id_usuario(self) -> int:
        return self._id_usuario

    @property
    def tipo(self) -> TipoUsuario:
        return self._tipo
