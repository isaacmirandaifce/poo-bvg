from usuario import Usuario

class FuncionarioAdministrativo(Usuario):
    def __init__(self, nome, email, departamento, cargo):
        super().__init__(nome, email, "Funcionário Administrativo")
        self.departamento = departamento
        self.cargo = cargo

    def gerar_relatorio(self):
        return (f"Funcionário Administrativo: {self.nome}\n"
                f"Departamento: {self.departamento}\n"
                f"Cargo: {self.cargo}")
