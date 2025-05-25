class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.__cpf = cpf  

    def get_cpf(self):
        return self.__cpf

class Carro:
    def __init__(self, marca, placa):
        self.marca = marca
        self.__placa = placa 

    def get_placa(self):
        return self.__placa


#Pseudo código
def verificar_vigencia(self):
    data_fim = self.vigencia.split(" a ")[1]
    if data_fim > data_atual:
        return True
    else:
        return False


