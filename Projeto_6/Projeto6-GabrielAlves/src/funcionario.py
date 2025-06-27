from usuario import UsuarioAutenticavel
from interfaces import Relatorio
from enums import TipoUsuario

class FuncionarioAdministrativo(UsuarioAutenticavel, Relatorio):
    """
    Representa um funcionário administrativo, que pode se autenticar e
    gerar um relatório sobre sua função. 
    """
    TIPO = TipoUsuario.FUNCIONARIO_ADMINISTRATIVO

    def __init__(self, nome: str, id_usuario: int, senha: str, cargo: str):
        super().__init__(nome, id_usuario, senha)
        self._cargo = cargo

    def gerar_relatorio(self) -> None: # Implementação da interface Relatorio [cite: 12]
        """
        Gera um relatório com os detalhes do funcionário e seu cargo. [cite: 12]
        """
        print("--- Relatório do Funcionário Administrativo ---")
        print(f"Nome: {self.nome}")
        print(f"ID: {self._id_usuario}")
        print(f"Cargo: {self._cargo}")
        print("-" * 45)