
#codigo A 
class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf  # privado

    def get_cpf(self):
        return self.__cpf

class Carro:
    def __init__(self, placa):
        self.__placa = placa  # privado

    def get_placa(self):
        return self.__placa

"""
#codigo B
Função verificar_vigencia():
    se data_atual < data_fim_vigencia:
        retornar True
    senão:
        retornar False
"""
