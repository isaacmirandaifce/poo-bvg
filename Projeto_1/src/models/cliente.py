class Cliente:
    """
    classe responsável por gerenciar infos dos clientes.
    """
    
    total_cliente = 0

    def __init__(self, nome, idade, saldo_inicial):
        """
        Inicia o atributo do cliente de forma privada, para o encapsulamento.
        
        Args:
            nome (str): O nome completo do cliente.
            idade (int): A idade do cliente.
            saldo (float): O saldo inicial depositado na abertura da conta.
            
        Raises:
            ValueError: Se o limite máximo de 100 clientes já tiver sido atingido.
        """
        if Cliente.total_cliente >= 100:
             raise MemoryError("Erro Crítico: Limite de memória atingido!")

        self.__nome = nome 
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__status_ativo = True

        self.__id = Cliente.total_cliente
        Cliente.total_cliente += 1
        print(f"Sucesso: Cliente {self.__nome} cadastrado com ID {self.__id}")

    @property 
    def nome(self): 
        """Vai retornar o nome daquele cliente, como somente leitura/consulta."""
        return self.__nome 
    

    @property
    def idade(self):
            """Vai retornar a idade daquele cliente, como somente leitura/consulta."""
            return self.__idade
    @property
    def saldo(self):
            """Vai retornar o saldo daquele cliente, como somente leitura/consulta."""
            return self.__saldo
    @property
    def status_ativo(self):
            """Vai retornar se a conta está ativa daquele cliente, como somente leitura/consulta."""
            return self.__status_ativo

    
    def sacar(self, valor):
        """
        Realiza o saque na conta do cliente.
        
        Entrada: valor (float) que representa a quantia desejada.
        Saída: Subtrai o valor do saldo ou levanta um erro (ValueError) se a conta estiver inativa, sem saldo ou o valor for negativo.
        """

        if self.__status_ativo == False:
             raise ValueError("Erro: Conta inativa!")
        
        if valor <= 0:
            raise ValueError("O valor do saque deve ser POSITIVO e MAIOR que zero.")
            
        if valor > self.saldo:
            raise ValueError("Saldo Insuficiente.")
        self.__saldo -= valor
        print(f"Saque efetuado com sucesso! Seu novo saldo é R${self.__saldo:.2f}")

    
    def depositar(self, valor):
        """
        Realiza um depósito na conta do cliente.
        
        Args:
            valor (float): O valor a ser depositado.
            
        Raises:
            ValueError: Se o valor do depósito for negativo ou zero.
            ValueError: Se a conta estiver inativa.
        """
        if self.__status_ativo == False:
            raise ValueError("Erro: Conta inativa!")
            
        if valor <= 0:
            raise ValueError("O valor do depósito deve ser POSITIVO e MAIOR que zero.")
            
        self.__saldo += valor
        print(f"Depósito efetuado com sucesso! Seu novo saldo é R${self.__saldo:.2f}")


        