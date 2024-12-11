class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf  

    def obter_cpf(self):
        return self.__cpf

    def atualizar_cpf(self, novo_cpf):
        self.__cpf = novo_cpf


class Carro:
    def __init__(self, marca, modelo, ano, cor, placa):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.cor = cor
        self.__placa = placa  

    def obter_placa(self):
        return self.__placa

    def atualizar_placa(self, nova_placa):
        self.__placa = nova_placa
