# funcionario_administrativo.py
from .usuario_autenticavel import UsuarioAutenticavel
from .relatorio import Relatorio
from .tipo_usuario import TipoUsuario

class FuncionarioAdministrativo(UsuarioAutenticavel, Relatorio):
    """
    Representa um funcionário administrativo no sistema.
    """
    def __init__(self, nome: str, id_usuario: int, senha: str, cargo: str):
        super().__init__(nome, id_usuario, TipoUsuario.FUNCIONARIO_ADMINISTRATIVO, senha)
        self._cargo = cargo

    def autenticar(self, senha: str) -> bool:
        """Implementação do método de autenticação."""
        return self._senha == senha

    def gerar_relatorio(self) -> None:
        """Gera um relatório detalhado para o funcionário."""
        print("--- Relatório do Funcionário Administrativo ---")
        print(f"Nome: {self.nome}")
        print(f"ID: {self.id_usuario}")
        print(f"Cargo: {self._cargo}")
        print("-----------------------------------------------\n")