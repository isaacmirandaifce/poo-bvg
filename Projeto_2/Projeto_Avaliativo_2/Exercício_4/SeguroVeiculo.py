class SeguroVeiculo:
    def __init__(self, cliente, valor_base, vigencia):
        self.cliente = cliente
        self.valor_base = valor_base  
        self.vigencia = vigencia

    def calcular_valor(self):
        return self.valor_base

class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, valor_base, vigencia, tipo_carro, cobertura_acidentes):
        super().__init__(cliente, valor_base, vigencia)
        self.tipo_carro = tipo_carro  # Tipo de carro (ex: popular, SUV, esportivo)
        self.cobertura_acidentes = cobertura_acidentes  

    def calcular_valor(self):
        valor = super().calcular_valor()  
        # Se o carro for do tipo esportivo ou se a cobertura de acidentes for contratada, aumenta o valor
        if self.tipo_carro == "esportivo":
            valor *= 1.5  # Aumenta 50% para carros esportivos
        if self.cobertura_acidentes:
            valor *= 1.2  # Aumenta 20% se houver cobertura para acidentes
        return valor

class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, valor_base, vigencia, tipo_moto, cobertura_acidentes):
        super().__init__(cliente, valor_base, vigencia)
        self.tipo_moto = tipo_moto  # Tipo de moto (ex: esportiva, urbana)
        self.cobertura_acidentes = cobertura_acidentes  # Indica se há cobertura para acidentes

    def calcular_valor(self):
        valor = super().calcular_valor() 
        # Se a moto for esportiva ou se houver cobertura para acidentes, aumenta o valor
        if self.tipo_moto == "esportiva":
            valor *= 1.7  # Aumenta 70% para motos esportivas
        if self.cobertura_acidentes:
            valor *= 1.3  # Aumenta 30% se houver cobertura para acidentes
        return valor
    

