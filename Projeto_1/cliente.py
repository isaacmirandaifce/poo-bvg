class Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R$ {self.__saldo:.2f}")

    def atualizar_saldo(self, valor: float):
        self.__saldo += valor
        print(f"Saldo atualizado! Novo saldo: R$ {self.__saldo:.2f}")


# Teste da classe
if __name__ == "__main__":
    cliente1 = Cliente("João Silva", 30, 1000.0)
    cliente1.mostrar_informacoes()
    cliente1.atualizar_saldo(500.0)
    cliente1.mostrar_informacoes()