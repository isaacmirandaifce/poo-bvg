# A classe Cliente representa um cliente com nome, idade e saldo.

class Cliente:
    
    # Construtor da classe Cliente. 
    # Inicializa um novo cliente com os dados fornecidos.
    # Os atributos são privados para garantir encapsulamento.
    def __init__(self, nome: str, idade: int, saldo: float):

        self.__nome = nome      # Nome do cliente (string)
        self.__idade = idade    # Idade do cliente (inteiro)
        self.__saldo = saldo    # Saldo em conta (float)
    
    #  Métodos de acesso (getters e setters)
    
    def get_nome(self) -> str:
        # Retorna o nome do cliente.
        return self.__nome
    
    def set_nome(self, nome: str) -> None:
        # Define um novo nome para o cliente.
        self.__nome = nome
    
    def get_idade(self) -> int:
        # Retorna a idade do cliente.
        return self.__idade
    
    def set_idade(self, idade: int) -> None:
        # Define uma nova idade para o cliente.
        self.__idade = idade
    
    def get_saldo(self) -> float:
        # Retorna o saldo atual do cliente.
        return self.__saldo
    
    #  Não há setter para saldo, pois ele deve ser modificado
    # apenas através do método atualizar_saldo() para maior controle
    
    # Métodos funcionais
    
    def mostrar_informacoes(self) -> None:
        # Exibe as informações completas do cliente no console.
        # Formata o saldo com 2 casas decimais para exibição em formato monetário.
        print(f"Cliente: {self.__nome}, Idade: {self.__idade}, Saldo: R$ {self.__saldo:.2f}")
    
    def atualizar_saldo(self, valor: float) -> None:
        # Atualiza o saldo do cliente adicionando ou subtraindo um valor.
        # Este método permite depósitos (valor positivo) e saques (valor negativo).
        self.__saldo += valor  # Incrementa ou decrementa o saldo