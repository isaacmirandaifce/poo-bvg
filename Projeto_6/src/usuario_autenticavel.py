from usuario import Usuario

class UsuarioAutenticavel(Usuario):
    def __init__(self, nome: str, email: str, senha: str):
        super().__init__(nome, email)  # Inicializa os atributos do usuário
        self.__senha = senha  # Atributo privado para a senha

    def autenticar(self, senha_tentativa: str) -> bool:
        """
        Verifica se a senha fornecida está correta.
        Retorna True se a senha estiver correta, caso contrário, False.
        """
        return self.__senha == senha_tentativa
