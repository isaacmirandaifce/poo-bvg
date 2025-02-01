from src.models.UsuarioAutenticavel import UsuarioAutenticavel
from src.models.Relatorio import Relatorio
from src.models.TipoUsuario import TipoUsuario

class FuncionarioAdministrativo(UsuarioAutenticavel, Relatorio):
    def __init__(self, 
                 nome='indefinido', 
                 email='indefinido', 
                 tipo=TipoUsuario.FUNCIONARIO_ADMINISTRATIVO, 
                 senha='', 
                 departamento='indefinido', 
                 cargo='indefinido'):
        # Chamando o construtor da classe UsuarioAutenticavel
        super().__init__(nome, email, tipo, senha)

        # Atributos específicos da classe FuncionarioAdministrativo
        self._departamento = departamento
        self._cargo = cargo

    def autenticar(self, senha):
        # Método de autenticação
        return self._senha == senha

    def gerarRelatorio(self):
        # Método para gerar relatório
        return (
            f"Nome: {self._nome}\n"
            f"Departamento: {self._departamento}\n"
            f"Cargo: {self._cargo}"
        )
