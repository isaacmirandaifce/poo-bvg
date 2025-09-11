# professor.py
from .usuario_autenticavel import UsuarioAutenticavel
from .relatorio import Relatorio
from .tipo_usuario import TipoUsuario
class Professor(UsuarioAutenticavel, Relatorio):
    """
    Representa um professor no sistema.
    """
    def __init__(self, nome: str, id_usuario: int, senha: str, departamento: str):
        super().__init__(nome, id_usuario, TipoUsuario.PROFESSOR, senha)
        self._departamento = departamento

    def autenticar(self, senha: str) -> bool:
        """Implementação do método de autenticação para Professor."""
        return self._senha == senha

    def gerar_relatorio(self) -> None:
        """Gera um relatório detalhado para o professor."""
        print("--- Relatório do Professor ---")
        print(f"Nome: {self.nome}")
        print(f"ID: {self.id_usuario}")
        print(f"Departamento: {self._departamento}")
        print("-----------------------------\n")