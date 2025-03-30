from models.usuario import Usuario

"""Cria o construtor de usuario autenticavel"""
class UsuarioAutenticavel(Usuario):
    def __init__(self, nome, email, senha):
        super().__init__(nome, email)
        self.__senha = senha  # Atributo privado

    """Autentica a senha"""
    def autenticar(self, senha):
        return self.__senha == senha
