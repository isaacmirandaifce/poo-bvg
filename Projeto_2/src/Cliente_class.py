class Cliente:
    # O construtor inicializa os atributos da classe com as informações do cliente
    def __init__(self, nome, cpf):
        self.__nome = nome
        self.__cpf = cpf

    # Métodos de acesso para obter os valores dos atributos privados
    def get_nome(self):
        return self.__nome
    
    def get_cpf(self):
        return self.__cpf
    
    # Método especial para retornar uma representação textual do objeto
    def __str__(self):
        return f"{self.__nome} (CPF: {self.__cpf})"

    # Método para exibir informações completas do cliente
    def exibir_informacoes(self):
        print(f"O nome do cliente é: {self.__nome}, o CPF do cliente é: {self.__cpf}")
