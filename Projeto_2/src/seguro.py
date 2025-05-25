from datetime import date
from cliente import Cliente
from carro import Carro

class SeguroVeiculo:
    def __init__(self, cliente: Cliente, valor: float, vigencia_inicio: date, vigencia_fim: date):
        self._cliente = cliente
        self._valor = valor
        self._vigencia_inicio = vigencia_inicio
        self._vigencia_fim = vigencia_fim

    def get_cliente(self):
        return self._cliente

    def get_valor(self):
        return self._valor

    def get_vigencia(self):
        return self._vigencia_inicio, self._vigencia_fim

    def calcular_valor(self, base_valor, taxa):
        return base_valor + (base_valor * taxa)

    def verificar_vigencia(self):
        hoje = date.today()
        return self._vigencia_inicio <= hoje <= self._vigencia_fim


class SeguroCarro(SeguroVeiculo):
    def __init__(self, cliente: Cliente, carros: list[Carro], valor: float, vigencia_inicio: date, vigencia_fim: date):
        super().__init__(cliente, valor, vigencia_inicio, vigencia_fim)
        self._carros = carros

    def get_carros(self):
        return self._carros

    def calcular_valor(self, base_valor, taxa):
        return super().calcular_valor(base_valor, taxa) + 100.0

    def __str__(self):
        carros_info = "\n".join([carro.exibir_detalhes() for carro in self._carros])
        vigencia = f"{self._vigencia_inicio.strftime('%d/%m/%Y')} a {self._vigencia_fim.strftime('%d/%m/%Y')}"
        return (f"Cliente: {self._cliente}\nCarros:\n{carros_info}\n"
                f"Valor: R${self._valor:.2f} - Vigência: {vigencia}")


class SeguroMoto(SeguroVeiculo):
    def __init__(self, cliente: Cliente, valor: float, vigencia_inicio: date, vigencia_fim: date):
        super().__init__(cliente, valor, vigencia_inicio, vigencia_fim)

    def calcular_valor(self, base_valor, taxa):
        return super().calcular_valor(base_valor, taxa) + 50.0
