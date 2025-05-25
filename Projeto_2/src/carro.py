from modelo import Modelo

class Carro:
    def __init__(self, ano, marca, modelo: Modelo, cor, placa):
        self._ano = ano
        self._marca = marca
        self._modelo = modelo
        self._cor = cor
        self._placa = placa

    def get_ano(self):
        return self._ano

    def get_marca(self):
        return self._marca

    def get_modelo(self):
        return self._modelo

    def get_cor(self):
        return self._cor

    def get_placa(self):
        return self._placa

    def atualizar_cor(self, nova_cor):
        self._cor = nova_cor

    def exibir_detalhes(self):
        return f"{self._marca} {self._modelo} ({self._ano}) - {self._cor} - Placa: {self._placa}"

    def __str__(self):
        return self.exibir_detalhes()
