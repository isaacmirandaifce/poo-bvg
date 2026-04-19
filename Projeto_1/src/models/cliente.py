"""
Módulo de modelos do sistema bancário.
Contém a definição da classe Cliente para gerenciamento de contas.
"""

class Cliente:
    """
    Representa um cliente do banco.
    
    A classe gerencia as informações pessoais e financeiras do cliente, 
    garantindo que operações como saque e depósito ocorram de forma segura.
    """

    def __init__(self, nome, idade, saldo_inicial):
        """
        Inicializa uma nova conta de cliente.
        
        Args:
            nome (str): Nome do cliente.
            idade (int): Idade do cliente.
            saldo_inicial (float): Valor inicial depositado na abertura da conta.
        """
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__status = True

    @property
    def nome(self):
        """Retorna o nome do cliente."""
        return self.__nome
    
    @property
    def idade(self):
        """Retorna a idade do cliente."""
        return self.__idade
    
    @property
    def saldo(self):
        """Retorna o saldo atual do cliente."""
        return self.__saldo
    
    @property
    def status(self):
        """Retorna o status da conta (True para ativa, False para inativa)."""
        return self.__status

    def sacar(self, valor):
        """
        Realiza um saque na conta do cliente.
        
        Impede a transação se a conta estiver inativa, se o valor for negativo/zero,
        ou se o valor do saque for maior que o saldo disponível.
        
        Args:
            valor (float): O montante a ser sacado.
        """
        if self.__status:
            if valor < 1:
                print("Erro! O valor de saque tem que ser maior que 0.")
                return
            
            if valor > self.__saldo:
                print("Erro! O valor solicitado é maior que o seu saldo atual.")
            else:
                self.__saldo -= valor 
                print(f"Sucesso! Saque concluído. Novo saldo: {self.__saldo}")
        else:
            print("Erro! Esta conta está inativa.")
    
    def depositar(self, valor):
        """
        Realiza um depósito na conta do cliente.
        
        Args:
            valor (float): O valor a ser depositado.
        """
        if self.__status:
            self.__saldo += valor
            print(f"Sucesso! Depósito realizado. Valor do seu saldo agora: {self.__saldo}")
        else:
            print("Erro! Esta conta está inativa.")
        
    def exibir_relatorio(self):
        """Imprime no terminal um relatório geral com os dados do cliente."""
        print("\n--- RELATÓRIO GERAL ---")
        print(f"Nome: {self.__nome}\nIdade: {self.__idade}\nSaldo: {self.__saldo}")
        if self.__status:
            print("Estado da conta: Ativa")
        else:
            print("Estado da conta: Inativa")