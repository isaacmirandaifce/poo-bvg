import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../src')))

from cliente import Cliente
from carro import Carro
from seguro import Seguro

# Criar objetos
cliente = Cliente("Paulin O Bacana", "123.456.789-00")
carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
seguro = Seguro(carro, cliente, 1500.0, "01/01/2024 a 01/01/2025")

# Testes
print(cliente.exibir_informacoes())
print(carro.exibir_detalhes())
print(f"Valor Seguro: {seguro.calcular_valor(1000.0, 0.5)}")
print(f"Vigencia Valida: {seguro.verificar_vigencia()}")
