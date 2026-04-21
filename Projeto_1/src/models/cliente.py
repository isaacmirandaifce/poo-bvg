class Cliente:
    """
    Representa um cliente do sistema bancário.
    Guarda os dados do cliente e controla operações como saque e depósito.
    """

    def __init__(self, nome: str, idade: int, saldo_inicial: float):
        """
        Cria um novo cliente.
        nome: nome do cliente
        idade: idade do cliente
        saldo_inicial: dinheiro inicial da conta
        """
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__ativo = True

    @property
    def nome(self):
        """Retorna o nome do cliente"""
        return self.__nome
    
    @property
    def idade(self):
        """Retorna a idade do cliente"""
        return self.__idade
    
    @property
    def saldo(self):
        """Retorna o saldo atual da conta"""
        return self.__saldo
    
    @property
    def ativo(self):
        """Retorna se a conta está ativa ou não"""
        return self.__ativo
    
    def depositar(self, valor: float):
        """
        Adiciona dinheiro na conta.
        valor: valor que será depositado
        """
        if not self.__ativo:
            print("Erro: Conta inativa.")
            return
            
        if valor <= 0:
            print("Erro: Valor inválido para depósito.")
            return
        
        self.__saldo += valor
        print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${self.__saldo:.2f}")

    def sacar(self, valor: float): 
        """
        Retira dinheiro da conta.
        Não permite sacar mais do que tem (não deixa saldo negativo).
        valor: valor que será sacado
        """
        if not self.__ativo:
            print("Erro: Conta inativa.")
            return

        if valor <= 0:
            print("Erro: Valor inválido para saque.")
            return
        
        if valor > self.__saldo:
            print("Erro: Saldo insuficiente")
            return
        
        self.__saldo -= valor
        print(f"Saque de R${valor:.2f} realizado com sucesso. Novo saldo: R${self.__saldo:.2f}")

    def desativar(self):
        """
        Desativa a conta do cliente.
        """
        self.__ativo = False

    def exibir_dados(self, id_cliente: int):
        """
        Mostra os dados do cliente no terminal.
        id_cliente: número usado pra identificar o cliente
        """
        print(
            f"ID: {id_cliente} | Nome: {self.__nome} | "
            f"Idade: {self.__idade} | Saldo: R${self.__saldo:.2f} | Ativo: {self.__ativo}"
        )