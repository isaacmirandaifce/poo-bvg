from usuario import Usuario

class Professor(Usuario):
    def __init__(self, nome: str, id_usuario: int, departamento: str):
        super().__init__(nome, id_usuario)
        self.departamento = departamento
