class Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        """
        Construtor da classe Cliente. [cite: 10]
        Inicializa os atributos privados do cliente: nome, idade e saldo. [cite: 13]
        """
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo

    def mostrar_informacoes(self):
        """
        Exibe as informações do cliente (nome, idade e saldo). [cite: 11]
        Este método implementa a abstração, escondendo a forma como os dados são armazenados e apresentados. [cite: 14]
        """
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R${self.__saldo:.2f}")

    def atualizar_saldo(self, valor: float):
        """
        Atualiza o saldo do cliente. [cite: 12]
        Este método também contribui para a abstração da lógica de manipulação do saldo. [cite: 14]
        """
        if isinstance(valor, (int, float)): # Adicionando uma pequena validação para o tipo do valor
            self.__saldo += valor
        else:
            print("Valor inválido para atualização de saldo.")

# Código de teste para a classe Cliente [cite: 19, 20]
if __name__ == "__main__":
    # Criando uma instância da classe Cliente [cite: 20]
    cliente1 = Cliente("João Silva", 30, 1000.0)

    # Exibindo as informações iniciais do cliente [cite: 20]
    print("Informações iniciais do cliente:")
    cliente1.mostrar_informacoes()

    # Atualizando o saldo do cliente [cite: 20]
    print("\nAtualizando saldo em R$500.00...")
    cliente1.atualizar_saldo(500.0)

    # Exibindo as informações do cliente após a atualização do saldo [cite: 20]
    print("Informações do cliente após atualização de saldo:")
    cliente1.mostrar_informacoes()

    # Tentativa de atualização com valor inválido (apenas para demonstrar a validação adicionada)
    print("\nTentando atualizar saldo com valor inválido...")
    cliente1.atualizar_saldo("abc")
    cliente1.mostrar_informacoes()

    # Criando outra instância para demonstrar a modularidade
    cliente2 = Cliente("Maria Oliveira", 25, 1500.50)
    print("\nInformações do Cliente 2:")
    cliente2.mostrar_informacoes()
    cliente2.atualizar_saldo(-200.0) # Atualizando com valor negativo (compra/saque)
    print("Informações do Cliente 2 após débito de R$200.00:")
    cliente2.mostrar_informacoes()