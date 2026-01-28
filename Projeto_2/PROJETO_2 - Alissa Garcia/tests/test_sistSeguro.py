import sys
sys.path.insert(1, '/workspaces/poo-bvg/Projeto_2/PROJETO_2 - Alissa Garcia/')

import src.Carro_Seguro
import src.Cliente_Seguro
import src.Seguro

from src.Carro_Seguro import Carro
from src.Cliente_Seguro import Cliente
from src.Seguro import Seguro


cliente1 = Cliente("João Silva", "123.456.789-00")
#CRIA O CLIENTE

carro1 = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
#CRIA O CARRO

seguro1 = Seguro(cliente1, [carro1], 1500.0, "01/01/2024", "01/01/2025")
#CRIA O SEGURO 

"""Parte da exibição de dados"""

print("=== TESTE DO SISTSEGUROS ===\n")

print("INFORMAÇÕES DO CLIENTE:")
cliente1.exibir_informacoes()

print("\nINFORMAÇÕES DO CARRO:")
carro1.exibir_detalhes()

print("\nINFORMAÇÕES DO SEGURO:")
valor_final = seguro1.calcular_valor(1500.0, 0.1)
print(f"Valor calculado do seguro: R$ {valor_final:.2f}")

vigente = "Sim" if seguro1.verificar_vigencia() else "Não"
print(f"O seguro está vigente? {vigente}")

print("\n=== FIM DO TESTE ===")