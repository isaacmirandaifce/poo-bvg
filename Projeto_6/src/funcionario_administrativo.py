from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio
from tipo_usuario import TipoUsuario

class FuncionarioAdministrativo(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome, login, senha, departamento):
        super().__init__(nome, login, senha, TipoUsuario.FUNCIONARIO_ADMINISTRATIVO)
        self.departamento = departamento

    def autenticar(self, senha: str) -> bool:
        return self._verificar_senha(senha)

    def gerar_relatorio(self):
        print(f"\nRelatório do Funcionário Administrativo: {self.nome}")
        print(f"Departamento: {self.departamento}")
