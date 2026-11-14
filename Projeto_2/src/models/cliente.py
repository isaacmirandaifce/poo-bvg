class Cliente:
    """
    Classe que representa o titular de um ou mais seguros.
    Aplica encapsulamento para proteger os dados sensíveis do cliente.
    """
    def __init__(self, nome, cpf):
        """
        Método construtor da classe Cliente.
        
        Args:
            nome (str): O nome completo do cliente.
            cpf (str): O CPF do cliente (dado sensível protegido).
        """
        self.__nome = nome
        self.__cpf = cpf  
        
    @property
    def nome(self):
        """Retorna o nome do cliente."""
        return self.__nome

    @property
    def cpf(self):
        """Retorna o CPF do cliente. Acesso apenas para leitura (segurança)."""
        return self.__cpf