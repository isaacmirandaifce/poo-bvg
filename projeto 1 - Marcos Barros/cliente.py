# Definição da classe Cliente usando princípios de POO
class Cliente:
    # Construtor da classe que inicializa nome, idade e saldo do cliente
    def __init__(self, nome: str, idade: int, saldo: float):
        # Atributos privados (encapsulados) com dois underlines (__)
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    # Método para exibir as informações do cliente
    def mostrar_informacoes(self):
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo:.2f}")

    # Método para atualizar o saldo do cliente (adiciona ou subtrai valor)
    def atualizar_saldo(self, valor: float):
        self.__saldo += valor

    # Métodos getters para acessar os atributos privados (encapsulamento)
    def get_nome(self):
        return self.__nome

    def get_idade(self):
        return self.__idade

    def get_saldo(self):
        return self.__saldo

    # Método setter para atualizar o saldo com validação (exemplo de abstração)
    def set_saldo(self, novo_saldo: float):
        if novo_saldo >= 0:
            self.__saldo = novo_saldo
        else:
            print("Saldo inválido. O saldo não pode ser negativo.")
