from models.autenticavel import UsuarioAutenticavel

"""Cria o construtor para funcionario administrativo"""
class FuncionarioAdministrativo(UsuarioAutenticavel):
    def __init__(self, nome, email, senha, departamento, cargo):
        super().__init__(nome, email, senha)
        self.departamento = departamento
        self.cargo = cargo

    """Gera relatorio com as informações dadas"""
    def gerar_relatorio(self):
        super().gerar_relatorio()
        print(f"Departamento: {self.departamento}")
        print(f"Cargo: {self.cargo}")
