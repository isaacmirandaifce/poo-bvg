class Cliente:
    """
    Classe que representa o titular de um ou mais seguros.
    Mantém os dados do cliente e a coleção de seguros a ele vinculados.
    """
    def __init__(self, nome, cpf):
        """
        Construtor da classe Cliente.
        
        Args:
            nome (str): O nome completo do cliente.
            cpf (str): O CPF do cliente (dado sensível).
        """
        self.nome = nome
        self.__cpf = cpf
        self.__seguros = []  

    @property
    def cpf(self):
        """
        Retorna o CPF mascarado para proteger o dado sensível.
        
        Returns:
            str: CPF no formato '***.456.789-**'
        """
        if len(self.__cpf) >= 11:
            return f"***.{self.__cpf[4:11]}-**"
        return "***.***.***-**"

    def adicionar_seguro(self, seguro):
        """
        Adiciona um objeto Seguro à lista do cliente.
        
        Args:
            seguro (Seguro): A instância do seguro a ser associada.
        """
        self.__seguros.append(seguro)

    @property
    def seguros(self):
        """
        Retorna a lista de seguros associados a este cliente.
        
        Returns:
            list: Lista de objetos Seguro.
        """
        return self.__seguros