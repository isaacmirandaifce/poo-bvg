import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')
from classeCarro import Carro
from classeModelo import Modelo
from classeCliente import Cliente
from classeSeguro import Seguro

# Criando um modelo
modelo_sedan = Modelo("Sedan")

# Criando instâncias de Carro e Cliente
carro = Carro(ano=2022, marca="Toyota", modelo=modelo_sedan, cor="Preto", placa="ABC-1234")
cliente = Cliente("João Silva", "123.456.789-00")

# Criando instância da classe Seguro
seguro = Seguro(carro, cliente, 1500.0, "10-12-2024")

# Testando o método calcular_valor
base_valor = 1000.0
taxa = 0.2
valor_final = seguro.calcular_valor(base_valor, taxa)
print(f"Valor final do seguro: R${valor_final:.2f}")

# Testando o método verificar_vigencia
vigente = seguro.verificar_vigencia()
print(f"Seguro ainda está vigente: {vigente}")  # Esperado: True ou False dependendo da data atual

# Testando o método exibir_detalhes
detalhes = seguro.exibir_detalhes()
print("Detalhes do seguro:")
print(detalhes)