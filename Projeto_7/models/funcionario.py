from models.autenticavel import UsuarioAutenticavel

    #Inicia o construtor de Funcionario Administrativo, utilizando Usuario Autenticavel
class FuncionarioAdministrativo(UsuarioAutenticavel):
    def __init__(self, nome, email, senha, departamento, cargo):
        super().__init__(nome, email, senha)
        self.departamento = departamento
        self.cargo = cargo

    #Cria a função "gerar_relatorio"
    def gerar_relatorio(self):
        super().gerar_relatorio()
        print(f"Departamento: {self.departamento}")
        print(f"Cargo: {self.cargo}")
