from .usuarioAutenticavel import UsuarioAutenticavel
from .relatorio import Relatorio
from .tipoUsuario import TipoUsuario


class FuncionarioAdministrativo(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome: str, senha: str, setor: str):
        super().__init__(nome, senha)
        self.tipo = TipoUsuario.FUNCIONARIO_ADMINISTRATIVO
        self.setor = setor

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def gerar_relatorio(self):
        print(f"Relatório do Funcionário {self.nome}:")
        print(f"Setor: {self.setor}")
