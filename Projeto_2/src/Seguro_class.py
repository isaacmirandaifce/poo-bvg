class Seguro:
    # O construtor inicializa os atributos da classe com as informações do seguro
    def __init__(self, cliente, carro, valor_base, vigencia_inicio, vigencia_fim):
        # Atributos privados para armazenar os dados do seguro
        self.__cliente = cliente
        self.__carro = carro
        self.__valor_base = valor_base
        self.__vigencia_inicio = vigencia_inicio
        self.__vigencia_fim = vigencia_fim

    # Métodos de acesso para obter os valores dos atributos privados
    def get_cliente(self):
        return self.__cliente

    def get_carro(self):
        return self.__carro

    def get_valor_base(self):
        return self.__valor_base

    def get_vigencia_inicio(self):
        return self.__vigencia_inicio

    def get_vigencia_fim(self):
        return self.__vigencia_fim

    # Calcular o valor do seguro
    def calcular_valor(self):
        return self.__valor_base

    # Verifica se o seguro está dentro do período de vigência
    def verificar_validade(self, data_atual):
        if self.__vigencia_inicio <= data_atual <= self.__vigencia_fim:
            return "Seguro válido"
        else:
            return "Seguro expirado"

