from datetime import date

class Seguro: #criaçao da classe
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia #string

    def calcular_valor(self, base_valor, taxa): #os metodos
        self.valor = base_valor + (1*taxa)
        return self.valor
    
    def verificar_vigencia(self):
        data_atual = date.today()
        data_fim = date.fromisoformat(self.vigencia)
        return data_atual <= data_fim