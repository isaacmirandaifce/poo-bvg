class Cliente:
    """Gerenciador de contas, armazenando os dados do cliente, e saques da conta"""
    def __init__(self, nome_cliente: str, idade_cliente: int, saldo_cliente: float):
        self.__nomeCliente = nome_cliente
        self.__idadeCliente = idade_cliente
        self.__saldoCliente = saldo_cliente
        self.__statusAtivo = True
    
    """Passa todos os dados do cliente para uma "vitrine" onde o código apenas obeserva as informações."""
    @property
    def nome_cliente(self) -> str:
        """Mostra o nome do cliente, apenas para leitura"""
        return self.__nomeCliente
    
    @property
    def idade_cliente(self) -> int:
        """Mostra a idade do cliente, apenas para leitura"""
        return self.__idadeCliente
    
    @property
    def saldo_cliente(self) -> float:
        """Mostra o saldo do cliente, apenas para leitura"""
        return self.__saldoCliente
    
    @property
    def status_cliente(self) -> bool:
        """Mostra o status do cliente, se está ativou ou não, apenas para leitura"""
        return self.__statusAtivo


    def movimentarConta(self, valor: float, is_saque: bool) -> None:
        """Verifica se o cliente está ativo"""
        if self.__statusAtivo:
            if valor <= 0:
                """Verifica se o valor é negativo"""
                print("ERROR: Valor inválido!!")
            elif is_saque == True:
                """Verifica se é saque (True) ou depósito (False)"""
                if valor <= self.__saldoCliente:
                    """Verifica se o valor do saque está de acordo com valor que tem no saldo
                    2000 <= 1000 = False
                    500 <= 1000 = True"""
                    self.__saldoCliente -= valor
                    """Desconta o valor do saque no saldo
                    500 - 1000 = 500"""
                    print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${self.__saldoCliente:.2f}")
                else:
                        print("Saldo Insuficiente!!")
                        """Casp o valor do saque for maior que o saldo disponível"""
            else:
                self.__saldoCliente += valor
                """Se for depósito, ele soma o valor com o saldo
                500 + 1000 = 15000"""
                print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${self.__saldoCliente:.2f}")
        else:
            print("Erro: Conta inativa.")
            

    def exibirRelatorio(self) -> None:
        """"""
        print("--- RELATÓRIO GERAL ---")
        print(f"Nome: {self.__nomeCliente} | Idade: {self.__idadeCliente} | Saldo: R${self.__saldoCliente:.2f} | Ativo: {self.__statusAtivo}")
        """Gera o relatório de cada cliente"""