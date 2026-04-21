from seguro_veiculo import SeguroVeiculo

class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente, carro, valor, data_inicio, data_fim):
        super().__init__(cliente, valor, data_inicio, data_fim)
        self.carro = carro

    def calcular_valor(self, base_valor, taxa):
        taxa_extra = 0.05
        self.valor = base_valor * (1 + taxa + taxa_extra)
        return self.valor

    def exibir_detalhes(self):
        print("=== Seguro de Carro ===")
        self.cliente.exibir_informacoes()
        self.carro.exibir_detalhes()
        print(f"Valor: R$ {self.valor:.2f}")
        print(f"Vigência: {self.data_inicio} até {self.data_fim}")
        print(f"Seguro válido: {self.verificar_vigencia()}")


class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente, moto, valor, data_inicio, data_fim):
        super().__init__(cliente, valor, data_inicio, data_fim)
        self.moto = moto

    def calcular_valor(self, base_valor, taxa):
        taxa_extra = 0.10
        self.valor = base_valor * (1 + taxa + taxa_extra)
        return self.valor

    def exibir_detalhes(self):
        print("=== Seguro de Moto ===")
        self.cliente.exibir_informacoes()
        self.moto.exibir_detalhes()
        print(f"Valor: R$ {self.valor:.2f}")
        print(f"Vigência: {self.data_inicio} até {self.data_fim}")
        print(f"Seguro válido: {self.verificar_vigencia()}")
