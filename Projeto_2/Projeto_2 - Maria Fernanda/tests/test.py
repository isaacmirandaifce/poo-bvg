import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from carro import Carro
from cliente import Cliente 
from seguro import Seguro

if __name__ == "__main__":
    carro1 = Carro(ano=2023, marca="Toyota", modelo="Corolla Cross", cor="Branco", placa="OSS-1193")
    cliente1 = Cliente(nome="Maria", cpf="489.644.156-98")

    seguro1 = Seguro(carro=carro1, cliente=cliente1, valor=0.0, vigencia="2025-12-31")

    seguro1.calcular_valor(base_valor=2000, taxa=0.05)
    seguro1.exibir_informacao()

    carro1.atualizar_cor("Azul")
    seguro1.exibir_informacao()