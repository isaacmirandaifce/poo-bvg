from datetime import datetime

class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        # Calcula o valor do seguro com base no valor base e taxa
        self.valor = base_valor * (1 + taxa)
        return f"O valor do seguro calculado é R${self.valor:.2f}."

    def verificar_vigencia(self):
        # Verifica se o seguro ainda está válido
        data_atual = datetime.now().strftime("%Y-%m-%d")
        if data_atual <= self.vigencia:
            return "O seguro está válido."
        else:
            return "O seguro está vencido."