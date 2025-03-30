from models.usuario import Usuario

class UsuarioAutenticavel(Usuario):
    def __init__(self, nome, email, senha):
        super().__init__(nome, email)
        self.__senha = senha  # Atributo privado

    def autenticar(self, senha):
        return self.__senha == senha
