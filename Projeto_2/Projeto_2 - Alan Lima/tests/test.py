import unittest
import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from Carro import Carro
from Cliente import Cliente
from Seguro import Seguro

#teste da classe carro
carro = Carro(2024,'Fiat','Strada','Preta', 'SBK-2024')
carro.exibir_detalhes()
carro.atualizar_cor('branca')
carro.exibir_detalhes()