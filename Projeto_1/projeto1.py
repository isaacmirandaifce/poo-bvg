class Cliente:
    def __init__(self, nome: str, idade: int, saldo: float):
        self.__nome = nome
        self.__idade = idade
        self.__saldo = saldo
    
    def mostrar_informacoes(self) -> None:
        """Exibe as informações do cliente formatadas"""
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: {self.__saldo:.2f}")
    
    def atualizar_saldo(self, valor: float) -> None:
        """Atualiza o saldo do cliente somando o valor fornecido"""
        self.__saldo += valor
    
    # Métodos getters para permitir acesso controlado aos atributos privados
    @property
    def nome(self) -> str:
        return self.__nome
    
    @property
    def idade(self) -> int:
        return self.__idade
    
    @property
    def saldo(self) -> float:
        return self.__saldo


