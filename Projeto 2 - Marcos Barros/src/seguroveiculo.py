class SeguroVeiculo:
    def __init__(self, cliente, valor, vigencia):
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        return base_valor * taxa

class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, valor, vigencia, carros):
        super().__init__(cliente, valor, vigencia)
        self.carros = carros

    def calcular_valor(self, base_valor, taxa):
        # Exemplo: acréscimo de 5% por carro
        quantidade_carros = len(self.carros)
        adicional = base_valor * 0.05 * quantidade_carros
        return (base_valor * taxa) + adicional
        
class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, valor, vigencia, cilindradas, marca, modelo):
        super().__init__(cliente, valor, vigencia)
        self.cilindradas = cilindradas
        self.marca = marca
        self.modelo = modelo

    def calcular_valor(self, base_valor, taxa):
        # Exemplo: se for moto de alta cilindrada, aumenta o seguro
        if self.cilindradas > 600:
            adicional = base_valor * 0.10
        else:
            adicional = base_valor * 0.05
        return (base_valor * taxa) + adicional
