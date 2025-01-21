from Usuario import Usuario

class FuncionarioAdministrativo(Usuario):
    def __init__(self, nome="", email="", departamento="", cargo=""):
        """
        Construtor padrão e parametrizado para a classe FuncionarioAdministrativo.
        """
        super().__init__(nome, email, "Funcionario")
        self.departamento = departamento
        self.cargo = cargo

    def gerar_relatorio(self):
        """
        Sobrescreve o método abstrato da classe base para exibir informações do funcionário administrativo.
        """
        print(f"Nome: {self.nome}\nDepartamento: {self.departamento}\nCargo: {self.cargo}")
