from scr.carro import Carro
from scr.cliente import Cliente


class Seguro:
    def __init__(self, carro, cliente, valor, vigencia):
        self.carro = carro
        self.cliente = cliente
        self.valor = valor
        self.vigencia = vigencia

    def calcular_valor(self, base_valor, taxa):
        self.valor = base_valor * (1 + taxa)
        return self.valor

    def verificar_vigencia(self):
        from datetime import datetime
        data_atual = datetime.now().date()
        return data_atual <= self.vigencia


class SeguroVeiculo:
    def __init__(self, valor_base, vigencia):
        self.valor_base = valor_base
        self.vigencia = vigencia

    def calcular_valor(self):
        return self.valor_base


class SeguroCarro(SeguroVeiculo):
    def __init__(self, valor_base, vigencia, taxa_carro):
        super().__init__(valor_base, vigencia)
        self.taxa_carro = taxa_carro

    def calcular_valor(self):
        return self.valor_base * (1 + self.taxa_carro)


class SeguroMoto(SeguroVeiculo):
    def __init__(self, valor_base, vigencia, taxa_moto):
        super().__init__(valor_base, vigencia)
        self.taxa_moto = taxa_moto

    def calcular_valor(self):
        return self.valor_base * (1 + self.taxa_moto)


class SeguroEncapsulado:
    def __init__(self, vigencia):
        self.__vigencia = vigencia  

    def verificar_validade(self):
        from datetime import datetime
        data_atual = datetime.now().date()
        return data_atual <= self.__vigencia


if __name__ == "__main__":
    carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
    cliente = Cliente("Joao Silva", "123.456.789-00")
    seguro = Seguro(carro, cliente, 1500.0, "2025-01-01")

    print(carro.exibir_detalhes())
    print(cliente.exibir_informacoes())
    print(f"Valor do Seguro: {seguro.valor}")