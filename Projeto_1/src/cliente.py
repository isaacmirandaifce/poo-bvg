class Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        # atributos privados (encapsulamento)
        self.__nome = nome
        self.__idade = idade
        self.__saldo = float(saldo)

    def mostrar_informacoes(self) -> None:
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo}")

    def atualizar_saldo(self, valor: float) -> None:
        # abstração: quem usa a classe só chama o método, sem mexer no atributo direto
        self.__saldo += float(valor)
