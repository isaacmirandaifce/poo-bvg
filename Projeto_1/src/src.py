class Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        # Inicializa os atributos privados do cliente
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self) -> None:
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R${self.__saldo:.2f}")

    def atualizar_saldo(self, valor: float) -> None:
        # Verifica se a operação deixaria o saldo negativo
        if valor + self.__saldo < 0:
            print(f"Operação inválida! Saldo insuficiente.")
        else:
            self.__saldo += valor  
            # Atualiza o saldo com o valor informado
            print(f"Saldo atualizado! Novo saldo: R${self.__saldo:.2f}")
