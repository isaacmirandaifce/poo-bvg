# test/seguro.py

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from datetime import datetime
from carro import Carro  
from cliente import Cliente  
from seguro import Seguro  

# Função de teste para a classe Seguro
def teste_seguro():
    # Criando um cliente
    cliente1 = Cliente("João Silva", "123.456.789-00")
    
    # Criando um carro
    carro1 = Carro("Toyota", "Corolla", 2020, "Branco", "XYZ-1234")
    
    # Criando um seguro com valor base de 1000 e vigência até 01/01/2025
    vigencia = "2025-01-01"  # A data de vigência deve estar no formato YYYY-MM-DD
    seguro1 = Seguro(carro1, cliente1, 0, vigencia)
    
    # Calculando o valor do seguro com base no valor base e uma taxa de 0.2 (20%)
    print("Calculando valor do seguro...")
    base_valor = 1000  # Exemplo de valor base do seguro
    taxa = 0.2  # Exemplo de taxa de 20%
    print(seguro1.calcular_valor(base_valor, taxa))

    # Verificando se o seguro está válido
    print("\nVerificando a vigência do seguro...")
    print(seguro1.verificar_vigencia())

# Executando o teste
if __name__ == "__main__":
    teste_seguro()
