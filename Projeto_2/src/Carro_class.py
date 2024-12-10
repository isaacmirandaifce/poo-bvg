class Carro:
    # O construtor inicializa os atributos da classe com as informações do carro
    def __init__(self, marca, modelo, ano, cor, placa):
        # Atributos privados para armazenar os dados do carro
        self.__marca = marca
        self.__modelo = modelo
        self.__ano = ano
        self.__cor = cor
        self.__placa = placa

    # Métodos de acesso para obter os valores dos atributos privados
    def get_marca(self):
        return self.__marca

    def get_modelo(self):
        return self.__modelo

    def get_ano(self):
        return self.__ano

    def get_cor(self):
        return self.__cor

    def get_placa(self):
        return self.__placa

    # Exibi os detalhes do carro de forma legível
    def exibir_detalhes(self):
        print(f"A marca do carro: {self.__marca}, A cor do carro: {self.__cor}, "
              f"O modelo do carro: {self.__modelo}, A placa do carro {self.__placa}")

    # Atualiza a cor do carro
    def atualizar_cor(self, nova_cor: str):
        self.__cor = nova_cor
        print(f"Nova cor: {self.__cor}")

    # Transforma o objeto em string
    def __str__(self):
        return f"{self.__marca} {self.__ano} {self.__modelo} {self.__placa} {self.__cor}"
