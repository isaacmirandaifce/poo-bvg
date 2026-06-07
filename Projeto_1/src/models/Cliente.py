class Cliente:
    """
    Classe que representa um Cliente no sistema.
    Responsabilidades:
    - Armazenar informações de forma segura (encapsulada).
    - Validar operações de saque para impedir saldo negativo
    - Gerenciar movimentações de conta (saque e depósito)
    - Controlar o estado da conta (ativo/inativo)
    
    Atributos Privados:
    - __nome (str): Nome completo do cliente
    - __idade (int): Idade do cliente
    - __saldo (float): Saldo atual da conta
    - __ativo (bool): Status da conta
    """
    
    def __init__(self, nome, idade, saldo_inicial: float = 0.0):
        """
        Inicializa um novo cliente com dados fornecidos.
        
        Args: 
        nome (str): Nome completo do cliente
        idade (int): Idade do cliente
        saldo (float): Saldo inicial da conta
        
        Raises:
        ValueError: Se saldo_inicial for negativo
        """
        if saldo_inicial < 0:
            raise ValueError("O saldo inicial não pode ser negativo")
        
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__ativo = True
        
    def __str__(self):
        """
        Retorna uma representação em string legivel do obj Cliente
        """
        status = "Ativo" if self.__ativo else "Inativo"
        return f"Cliente: {self.__nome} | Saldo: R${self.__saldo:.2f} | Status: {status}"
        
# GETTERS 
    @property
    def nome(self):
        """
        Retorna o nome do cliente.
        
        Return:
        str: Nome completo do cliente
        """
        return self.__nome
    
    @property
    def idade(self):
        """
        Retorna a idade do cliente.
        
        Return:
        int: Idade do cliente
        """
        return self.__idade
    
    @property
    def saldo(self):
        """
        Retorna o saldo atual da conta.
        
        Return:
        float: Saldo em reais
        """
        return self.__saldo
    
    @property
    def ativo(self):
        """
        Retorna o status da conta.
        
        Return:
        bool: True e ativa, False se inativa 
        """
        return self.__ativo
    
# Métodos de operação

    def sacar(self, valor):
        """
        Realiza um saque na conta do cliente.

        Args:
            valor (float): Valor a ser sacado.

        Raises:
            RuntimeError: Se a conta estiver inativa.
            ValueError: Se o valor for inválido ou saldo insuficiente.
        """
        if not self.__ativo:
            raise RuntimeError("Operação recusada: Conta Inativa")
        if valor <= 0:
            raise ValueError("O valor deve ser positivo")
        if valor > self.__saldo:
            raise ValueError(
                f"Saldo Insuficiente. "
                f"Disponível: R${self.__saldo:.2f}, "
                f"Solicitado: R${valor:.2f}"
            )
        self.__saldo -= valor
        print(f"Saque de R${valor:.2f} realizado. Novo Saldo: R${self.__saldo:.2f}")


    def depositar(self, valor):
        """
        Realiza um depósito na conta do cliente.

        Args:
            valor (float): Valor a ser depositado.

        Raises:
            RuntimeError: Se a conta estiver inativa.
            ValueError: Se o valor for inválido.
        """
        if not self.__ativo:
            raise RuntimeError("Operação recusada: Conta Inativa")
        if valor <= 0:
            raise ValueError("O valor do depósito deve ser positivo")
        self.__saldo += valor
        print(f"Depósito de R${valor:.2f} realizado. Novo saldo R${self.__saldo:.2f}")
        
    def exibir_dados(self):
        """Exibe os dados do cliente alinhados."""
        status = "Sim" if self.__ativo else "Não"
        print(f"Nome: {self.__nome:<15} | Idade: {self.__idade:<5} | Saldo: R${self.__saldo:>8.2f} | Ativo: {status}")

    def desativar_conta(self):
        """Desativa a conta do cliente."""
        self.__ativo = False
        print(f"Conta de '{self.__nome}' desativada.")