class Cliente:
    """Classe que representa um cliente."""

    def __init__(self, nome: str, idade: int, saldo: float):
        """Inicializa os atributos do cliente."""
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self):
        """Exibe as informações do cliente."""
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo:.2f}")

    def atualizar_saldo(self, valor: float):
        """Atualiza o saldo do cliente."""
        self.__saldo += valor