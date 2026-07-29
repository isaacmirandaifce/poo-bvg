class Cliente:
    """
    Classe que representa um cliente do sistema bancário.

    Aplica os princípios de POO para gerenciar os dados do cliente de forma 
    encapsulada, eliminando o uso de variáveis globais e listas paralelas.
    """

    def __init__(self, nome: str, idade: int, saldo_inicial: float):
        """
        Inicializa um objeto Cliente com atributos privados.

        :param nome: Nome completo do cliente.
        :param idade: Idade do cliente.
        :param saldo_inicial: Valor inicial depositado na conta.
        """
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__status_ativo = True

    @property
    def nome(self) -> str:
        """Retorna o nome do cliente (Acesso de leitura)."""
        return self.__nome

    @property
    def idade(self) -> int:
        """Retorna a idade do cliente (Acesso de leitura)."""
        return self.__idade

    @property
    def saldo(self) -> float:
        """Retorna o saldo atual (Acesso de leitura)."""
        return self.__saldo

    @property
    def status_ativo(self) -> bool:
        """Retorna o status da conta (Acesso de leitura)."""
        return self.__status_ativo

    def depositar(self, valor: float) -> None:
        """
        Adiciona um valor ao saldo do cliente se a conta estiver ativa.

        :param valor: Valor a ser depositado.
        """
        if self.__status_ativo and valor > 0:
            self.__saldo += valor
            print(f"Depósito de R${valor:.2f} realizado com sucesso.")
        else:
            print("Erro: Depósito inválido ou conta inativa.")

    def sacar(self, valor: float) -> None:
        """
        Remove um valor do saldo, impedindo que ele fique negativo.

        :param valor: Valor a ser sacado.
        :raises ValueError: Caso o saldo seja insuficiente.
        """
        if not self.__status_ativo:
            print("Erro: Conta inativa.")
            return

        if valor > self.__saldo:
            # Regra de Negócio: Impede saldo negativo
            print(f"Transação Recusada: Saldo insuficiente para sacar R${valor:.2f}.")
            return
        
        self.__saldo -= valor
        print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")

    def __str__(self) -> str:
        """Retorna uma representação textual do cliente para relatórios."""
        status = "Ativo" if self.__status_ativo else "Inativo"
        return (f"Nome: {self.__nome} | Idade: {self.__idade} | "
                f"Saldo: R${self.__saldo:.2f} | Status: {status}")