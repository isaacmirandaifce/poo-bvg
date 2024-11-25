class Cliente:
    def __init__(self, nome, idade, saldo):
        """
        Inicializa uma nova instância da classe Cliente.
        :param nome: Nome do cliente (str).
        :param idade: Idade do cliente (int).
        :param saldo: Saldo do cliente (float).
        """
        self.__nome = nome
        self.__idade = idade  
        self.__saldo = saldo  

    def mostrar_informacoes(self):
        """
        Exibe as informações do cliente.
        """
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo:.2f}")

    def atualizar_saldo(self, valor):
        """
        Atualiza o saldo do cliente.
        :param valor: Valor a ser adicionado ao saldo (pode ser negativo).
        """
        self.__saldo += valor