from usuario import Usuario

class FuncionarioAdministrativo(Usuario):
    def __init__(self, nome, email, departamento, cargo):
        # Inicializa com atributos do usuário e os específicos de funcionário administrativo
        super().__init__(nome, email)
        self.departamento = departamento
        self.cargo = cargo
        self.tipo = "Funcionário Administrativo"  # Define o tipo diretamente na classe

    def gerar_relatorio(self):
        # Gera um relatório com os dados do funcionário administrativo
        print(f"Nome: {self.nome}")
        print(f"Email: {self.email}")
        print(f"Departamento: {self.departamento}")
        print(f"Cargo: {self.cargo}")
