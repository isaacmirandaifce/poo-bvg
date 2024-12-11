import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from classeCarro import Carro
from classeModelo import Modelo

# Criação do modelo
modelo_sedan = Modelo("Sedan")

# Criação do carro com o modelo
carro1 = Carro(ano=2022, marca="Toyota", modelo=modelo_sedan, cor="Preto", placa="ABC-1234")

# Exibe os detalhes do carro
print(carro1.exibir_detalhes())
print(carro1.atualizar_cor("Azul"))
print(carro1.exibir_detalhes())
print(repr(carro1))