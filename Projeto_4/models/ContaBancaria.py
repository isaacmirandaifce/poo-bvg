class ContaBancaria:
    def __init__(self, titular: str, cpf: str, saldo: float):
        self.__titular = titular 
        self.__cpf = cpf          
        self._saldo = saldo       

    def exibirDaddos(self) -> None:
        print(f"Titular: {self.__titular} | Saldo Atual: R$ {self._saldo:.2f}")