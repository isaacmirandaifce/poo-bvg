from abc import ABC, abstractmethod
import hashlib

class Usuario:
    """Classe base para todos os usuários do sistema."""
    def __init__(self, nome: str, id_usuario: int):
        self._nome = nome
        self._id_usuario = id_usuario

    @property
    def nome(self):
        return self._nome

class UsuarioAutenticavel(Usuario, ABC):
    """
    Classe abstrata para usuários que podem se autenticar no sistema. 
    Herda de Usuario e exige a implementação de um método de autenticação. 
    """
    def __init__(self, nome: str, id_usuario: int, senha: str):
        super().__init__(nome, id_usuario)
        # Boa prática: nunca armazene senhas em texto plano. [cite: 16]
        # Armazenamos um hash da senha para segurança. [cite: 16]
        self._senha_hash = self._hash_senha(senha)

    def _hash_senha(self, senha: str) -> str:
        """Gera um hash SHA-256 para a senha fornecida."""
        return hashlib.sha256(senha.encode()).hexdigest()

    def autenticar(self, senha: str) -> bool:
        """
        Autentica o usuário comparando o hash da senha fornecida com o hash armazenado. [cite: 11]
        """
        return self._senha_hash == self._hash_senha(senha)