class Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        # Atributos privados (encapsulamento)
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self):
        # Exibe as informações do cliente.
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R${self.__saldo:.2f}")

    def atualizar_saldo(self, valor: float):
        # Atualiza o saldo do cliente com o valor informado.
        # Pode ser tanto depósito (valor positivo) quanto saque (valor negativo).  
        self.__saldo += valor
