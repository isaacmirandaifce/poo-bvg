class Carro:
    def __init__(self, ano, marca, modelo, cor, placa):
        self.__ano = ano
        self.__marca = marca
        self.__modelo = modelo
        self.__cor = cor
        self.__placa = placa

    def exibir_detalhes(self):
        return f"{self.__ano} {self.__marca} {self.__modelo} - {self.__cor}, Placa: {self.__placa}"

    def atualizar_cor(self, nova_cor):
        self.__cor = nova_cor

    def get_placa(self):
        return self.__placa

    def get_modelo(self):
        return self.__modelo

    def get_info(self):
        return {
            "ano": self.__ano,
            "marca": self.__marca,
            "modelo": self.__modelo,
            "cor": self.__cor,
            "placa": self.__placa
        }
