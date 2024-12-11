import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from carro import Carro
from cliente import Cliente
from seguro import Seguro

if __name__ == "__main__":
    carro1 = Carro(ano=2020, marca="Honda", modelo="Civic", cor="Preto", placa="ABC-1234")
    
    cliente1 = Cliente(nome="João Silva", cpf="123.456.789-00")

    seguro1 = Seguro(carro=carro1, cliente=cliente1, valor=0.0, vigencia="2025-12-31")

    seguro1.calcular_valor(base_valor=2500, taxa=0.08)
    print("Informações do Seguro (Antes de mudar a cor do carro):")
    seguro1.exibir_informacao()

    carro1.atualizar_cor("Azul")
    
    print("\nInformações do Seguro (Depois de mudar a cor do carro):")
    seguro1.exibir_informacao()
