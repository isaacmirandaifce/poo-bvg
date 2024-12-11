# test/carro.py

import sys
import os

# Adicionando o diretório src ao caminho de módulos
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from carro import Carro

# Criando um cliente e um carro

carro1 = Carro("Toyota", "Corolla", 2020, "Branco", "XYZ-1234")

# Exibindo as informações do cliente e do carro

carro1.exibir_detalhes()

# Modificando o CPF e a placa com os setters

carro1.set_placa("ABC-5678")

# Exibindo as informações após modificação
print("\nApós modificação:")
carro1.exibir_detalhes()
