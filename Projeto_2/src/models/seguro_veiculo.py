from datetime import datetime

class SeguroVeiculo:
    def __init__(self, cliente, valor, vigencia):
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        raise NotImplementedError("Este método deve ser sobrescrito pelas subclasses")

    def verificar_vigencia(self):
        data_atual = datetime.now()
        vigencia_data = datetime.strptime(self.vigencia, "%d/%m/%Y")