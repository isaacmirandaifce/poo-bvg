from usuario import Usuario

# criaçao da class FuncionarioAdministrativo
class  FuncionarioAdministrativo(Usuario):
    def __init__(self, nome: str, email: str, departamento: str, cargo: str):
        super().__init__(nome, email, "Funcionário Administrativo")
        self.departamento = departamento
        self.cargo = cargo

    def gerarRelatorio(self):
        return f"Funcionário: {self.nome}, Departamento: {self.departamento}, Cargo: {self.cargo}"