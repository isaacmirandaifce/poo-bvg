from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio
from tipo_usuario import TipoUsuario

class FuncionarioAdministrativo(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome, email, senha):
        super().__init__(nome, email)
        self._senha = senha

    def autenticar(self, senha: str) -> bool:
        return self._senha == senha

    def gerar_relatorio(self) -> str:
        return f"Relatório do Funcionário Administrativo: {self.nome}"