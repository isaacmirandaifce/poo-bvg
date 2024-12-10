import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from carro import Carro
from cliente import Cliente
from seguro import Seguro
from modelo import Modelo


# Criando um modelo
modelo_sedan = Modelo("Sedan")

# Criando um carro com o modelo
meu_carro = Carro(ano=2022, marca="Toyota", modelo=modelo_sedan, cor="Preto", placa="ABC-1234")

# Exibindo os detalhes do carro
print(meu_carro.exibir_detalhes())

print(meu_carro.atualizar_cor("Azul"))

print(meu_carro.exibir_detalhes())

print(repr(meu_carro))
