from Usuario import Usuario

class FuncionarioAdm(Usuario):
    def __init__(self, nome, email, departamento, cargo):
        super().__init__(nome, email, "Funcionário Administrativo")
        self.departamento = departamento
        self.cargo = cargo

    def gerar_relatorio(self):
        relatorio = f"Funcionário Administrativo: {self.nome}\nDepartamento: {self.departamento}\nCargo: {self.cargo}"
        print(relatorio)
