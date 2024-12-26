import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from carro import Carro
from modelo import Modelo

# Criando um modelo
modelo_sedan = Modelo("Sedan")

# Criando um carro com o modelo
carro1 = Carro(ano=2022, marca="Toyota", modelo=modelo_sedan, cor="Preto", placa="ABC-1234")

# Exibindo os detalhes do carro
print(carro1.exibir_detalhes())

print(carro1.atualizar_cor("Azul"))

print(carro1.exibir_detalhes())

print(repr(carro1))
