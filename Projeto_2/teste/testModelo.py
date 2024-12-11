import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

from classeModelo import Modelo


modelo = Modelo("esportivo")

# Testando o método get_nome
print(modelo.get_nome())  # Esperado: 'Exemplo de Modelo'
# Testando o método __repr__
print(modelo)  # Esperado: "Modelo(nome='Exemplo de Modelo')"