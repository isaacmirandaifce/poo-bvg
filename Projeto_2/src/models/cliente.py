from typing import List
from .seguro_veiculo import SeguroVeiculo

class Cliente:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.cpf = cpf
        self.seguros: List[SeguroVeiculo] = []

    def adicionar_seguro(self, seguro):
        self.seguros.append(seguro)

    def exibir_informacoes(self):
        print(f"Nome: {self.nome}, CPF: {self.cpf}")
        print("Seguros:")
        for seguro in self.seguros:
            print(f"  - Seguro com vigência até {seguro.vigencia}")
