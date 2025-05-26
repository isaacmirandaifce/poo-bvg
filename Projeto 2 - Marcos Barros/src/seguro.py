class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.__carro = carro  # objeto Carro
        self.__cliente = cliente  # objeto Cliente
        self.__valor = valor
        self.__vigencia = vigencia  # Ex: '2025-12-31'
  
    def calcular_valor(self, base_valor, taxa):
        self.__valor = base_valor * (1 + taxa)
        return self.__valor

    def verificar_vigencia(self):
        from datetime import datetime
        data_vigencia = datetime.strptime(self.__vigencia, '%Y-%m-%d')
        return datetime.now() <= data_vigencia