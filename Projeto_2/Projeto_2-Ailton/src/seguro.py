from datetime import datetime

#Classe base para herança
class SeguroVeiculo:
    def __init__(self, carro, cliente, valor, vigencia_inicio, vigencia_fim):
        # Inicializa os atributos do seguro
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia_inicio = vigencia_inicio # string no formato 'DD/MM/YYYY'
        self.vigencia_fim = vigencia_fim

    def calcular_valor(self, base_valor, taxa):
        # Calcula o valor do seguro com base em uma taxa
        self.valor = base_valor * (1 + taxa)
        return self.valor

    def verificar_vigencia(self):
        # Verifica se o seguro está dentro do período de vigência
        hoje = datetime.now()
        inicio = datetime.strptime(self.vigencia_inicio, '%d/%m/%Y')
        fim = datetime.strptime(self.vigencia_fim, '%d/%m/%Y')
        return inicio <= hoje <= fim

    # Seguro specífico para carros
class SeguroCarro(SeguroVeiculo):
    def __init__(self, carro, cliente, valor, vigencia_inicio, vigencia_fim, coberturas=None):
        super().__init__(carro, cliente, valor, vigencia_inicio, vigencia_fim)
        self.coberturas = coberturas or []

    def calcular_valor(self, base_valor, taxa, fator_carro=1.0):
        # Calcula o valor do seguro para carro com um fator adicional
        self.valor = base_valor * (1 + taxa) * fator_carro
        return self.valor

    