class Usuario:
    def __init__(self, nome="", email="", tipo=""):
        self.nome = nome
        self.email = email
        self.tipo = tipo

    def exibir_informacoes(self):
        print(f"Usuário: {self.nome} | Email: {self.email} | Tipo: {self.tipo}")

class FuncionarioAdministrativo(Usuario):
    def __init__(self, nome="", email="", departamento="", cargo=""):
        super().__init__(nome, email, "FuncionarioAdministrativo")
        self.departamento = departamento
        self.cargo = cargo

    def gerar_relatorio(self):
        print("Relatório do Funcionário Administrativo:")
        print(f"Nome: {self.nome}")
        print(f"Departamento: {self.departamento}")
        print(f"Cargo: {self.cargo}")
