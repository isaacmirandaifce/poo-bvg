from usuario_autenticavel import UsuarioAutenticavel
from relatorio import Relatorio

class FuncionarioAdministrativo(UsuarioAutenticavel, Relatorio):
    def __init__(self, nome: str, email: str, senha: str, departamento: str, cargo: str):
        super().__init__(nome, email, senha)  # Inicializa o usuário autenticável
        self.departamento = departamento  # Define o departamento do funcionário
        self.cargo = cargo  # Define o cargo do funcionário

    def gerar_relatorio(self):
        """
        Gera um relatório com o departamento e cargo do funcionário.
        """
        print(f"Relatório do Funcionário Administrativo: {self.nome}")
        print(f"Departamento: {self.departamento}")
        print(f"Cargo: {self.cargo}")
