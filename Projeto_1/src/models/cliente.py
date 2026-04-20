#cliente do banco
class Cliente:
    def __init__(self, nome: str, idade: int, saldo_inicial: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo_inicial
        self.__status_ativo = True

    @property
    def nome(self):
        return self.__nome
    

    @property
    def saldo(self):
        return self.__saldo
    
    @property
    def status_ativo(self):
        return self.__status_ativo
    

    def depositar(self, valor: float):
        if self.__status_ativo and valor >0:
            self.__saldo += valor
            print(f"Deposito de R${valor:.2f} realizado com sucesso")

        else: 
            print("Erro: Operação inválida ou conta inativa")

    def sacar(self, valor: float):
        if not self.__status_ativo:
            print("Erro: conta inativa")
            return
        
        if valor > self.__saldo:
            print(f"Erro: salfo insuficiente para sacar R${valor:2f}")
            return
        
        self.__saldo -= valor
        print(f"Saque de R${valor:.2f} realizado. Seu novo saldo: R${self.__saldo:.2f}")

    def exibir_dados(self):
        status = "Ativo" if self.__status_ativo else "Inativo"
        return f"Nome: {self.__nome} | Idade: {self.__idade} | Saldo: R${self.__saldo:.2f} | Status:{status}"