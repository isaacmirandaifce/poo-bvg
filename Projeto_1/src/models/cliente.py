class Cliente:
    """Representa um cliente do Core Bancário com seus dados pessoais e financeiros.

    Todos os atributos são privados (prefixo __) e só podem ser lidos por meio
    de propriedades. O estado do objeto (saldo) só é alterado pelos métodos da
    própria classe, que aplicam as regras de negócio.

    Args:
        nome (str): Nome do cliente.
        idade (int): Idade do cliente.
        saldo_inicial (float): Saldo inicial da conta.
        status (bool): Indica se a conta está ativa. O padrão é True.

    Raises:
        ValueError: Se o nome estiver vazio, ou se a idade ou o saldo inicial
            forem negativos."""

    def __init__(self, nome, idade, saldo_inicial, status=True):
        if not str(nome).strip():
            raise ValueError("O nome do cliente não pode ser vazio.")
        if idade < 0:
            raise ValueError("A idade não pode ser negativa.")
        if saldo_inicial < 0:
            raise ValueError("O saldo inicial não pode ser negativo.")

        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__status = status

    @property
    def nome(self):
        """Retorna o nome do cliente.

        Returns:
            str: Nome armazenado no objeto."""
        return self.__nome

    @property
    def idade(self):
        """Retorna a idade do cliente.

        Returns:
            int: Idade armazenada no objeto."""
        return self.__idade

    @property
    def saldo(self):
        """Retorna o saldo atual da conta.

        Returns:
            float: Saldo atual do cliente."""
        return self.__saldo

    @property
    def status(self):
        """Retorna o estado atual da conta.

        Returns:
            bool: True se a conta estiver ativa; False caso contrário."""
        return self.__status

    def __validar_conta_ativa(self):
        """Garante que a conta está ativa antes de uma operação.

        Raises:
            ValueError: Se a conta estiver inativa."""
        if not self.__status:
            raise ValueError(f"A conta do cliente {self.__nome} está inativa!")

    def sacar(self, valor):
        """Retira um valor da conta, desde que haja saldo suficiente.

        Args:
            valor (float): Valor que será retirado da conta.

        Returns:
            bool: True se o saque for realizado.

        Raises:
            ValueError: Se a conta estiver inativa, o valor for inválido
                ou o saldo for insuficiente (o saldo nunca fica negativo)."""
        self.__validar_conta_ativa()
        if valor <= 0:
            raise ValueError("O valor do saque deve ser maior que zero!")
        if valor > self.__saldo:
            raise ValueError(
                f"Saldo insuficiente. Saldo atual: R$ {self.__saldo:.2f}"
            )

        self.__saldo -= valor
        return True

    def depositar(self, valor):
        """Adiciona um valor positivo ao saldo da conta.

        Args:
            valor (float): Valor que será depositado.

        Returns:
            bool: True se o depósito for realizado.

        Raises:
            ValueError: Se a conta estiver inativa ou o valor for inválido."""
        self.__validar_conta_ativa()
        if valor <= 0:
            raise ValueError("O valor do depósito deve ser maior que zero!")

        self.__saldo += valor
        return True

    def transferir(self, destino, valor):
        """Transfere dinheiro desta conta para outra conta ativa.

        Args:
            destino (Cliente): Cliente que receberá o dinheiro.
            valor (float): Valor que será transferido.

        Returns:
            bool: True se a transferência for realizada.

        Raises:
            ValueError: Se as contas forem a mesma, alguma estiver inativa,
                o valor for inválido ou o saldo for insuficiente."""
        if destino is self:
            raise ValueError("A conta de origem e a de destino devem ser diferentes!")

        # Valida as duas contas antes de mexer em qualquer saldo.
        self.__validar_conta_ativa()
        destino.__validar_conta_ativa()

        self.sacar(valor)
        destino.depositar(valor)
        return True