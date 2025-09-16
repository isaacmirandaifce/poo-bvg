from usuario import Usuario

class FuncionarioAdministrativo(Usuario):
    def __init__(self, nome: str, id_usuario: int, cargo: str):
        super().__init__(nome, id_usuario)
        self.cargo = cargo
