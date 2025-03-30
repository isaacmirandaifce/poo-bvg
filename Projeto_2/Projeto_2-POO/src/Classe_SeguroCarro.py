from Classe_SeguroVeiculo import SeguroVeiculo

class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia  # Data no formato "AAAA-MM-DD"
    
    def calcular_valor(self, base_valor, taxa):
        """Calcula o valor do seguro com base em um valor base e uma taxa."""
        self.valor = base_valor * (1 + taxa)
        return self.valor
    
    def verificar_vigencia(self, data_atual):
        """Verifica se o seguro está válido com base na data atual."""
        if data_atual <= self.vigencia:
            return "O seguro está válido."
        else:
            return "O seguro está vencido."
        
        
# Subclasse para Carros
class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, valor, vigencia, tipo_combustivel, num_portas):
        super().__init__(cliente, valor, vigencia)
        self.tipo_combustivel = tipo_combustivel
        self.num_portas = num_portas

    def calcular_valor(self, base_valor, taxa):
        """Calcula o valor do seguro para carros com base no tipo de combustível."""
        if self.tipo_combustivel == "Diesel":
            taxa += 0.05  # Taxa adicional para combustível diesel
        self.valor = base_valor * (1 + taxa)
        return self.valor


