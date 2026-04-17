from datetime import date

class SeguroVeiculo:
    def __init__(self, cliente, valor_base, fim_vigencia):
        self.cliente = cliente
        self.valor_base = valor_base
        self.fim_vigencia = fim_vigencia

    def verificar_vigencia(self):
        hoje = date.today()
        if hoje <= self.fim_vigencia:
            return "Válido"
        else:
            return "Vencido"
    
    def calcular_valor(self):
        return self.valor_base
        

class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, valor_base, fim_vigencia, carro):
        super().__init__(cliente, valor_base, fim_vigencia)
        self.carro = carro
    
    def calcular_valor(self):
        taxa_risco = 1.2
        return self.valor_base * taxa_risco
    
class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, valor_base, fim_vigencia, moto):
        super().__init__(cliente, valor_base, fim_vigencia)
        self.moto = moto

    def calcular_valor(self):
        taxa_risco = 1.5
        return self.valor_base * taxa_risco
