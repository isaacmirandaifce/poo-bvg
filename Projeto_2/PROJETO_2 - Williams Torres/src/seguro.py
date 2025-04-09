from seguro_veiculo import SeguroVeiculo

class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, carro, valor, vigencia):
        super().__init__(cliente, valor, vigencia)
        self.carro = carro

    def exibir_detalhes(self):
        return f"Seguro do carro: {self.carro.exibir_detalhes()}, Cliente: {self.cliente.exibir_informacoes()}, Valor: R${self.valor:.2f}, Vigência: {self.vigencia}"

class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, moto, valor, vigencia):
        super().__init__(cliente, valor, vigencia)
        self.moto = moto

    def exibir_detalhes(self):
        return f"Seguro da moto: {self.moto.exibir_detalhes()}, Cliente: {self.cliente.exibir_informacoes()}, Valor: R${self.valor:.2f}, Vigência: {self.vigencia}"
