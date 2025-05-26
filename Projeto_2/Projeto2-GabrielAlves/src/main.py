from cliente import Cliente
from carro import Carro
from modelo import Modelo
from seguro_veiculo import SeguroCarro, SeguroMoto
from seguro import Seguro

# Criar cliente
cliente1 = Cliente("João Silva", "123.456.789-00")

# Criar modelo e carro
modelo_carro = Modelo("Corolla")
carro1 = Carro(2020, "Toyota", modelo_carro, "Branco", "XYZ-1234")

# Seguro padrão (sem herança)
seguro_padrao = Seguro(carro1, cliente1, 0, "2024-01-01 a 2025-01-01")
valor_final = seguro_padrao.definir_valor(1000, 0.15)
print(f"Valor do seguro padrão: R$ {valor_final:.2f}")
print("Seguro está vigente?", "Sim" if seguro_padrao.esta_vigente() else "Não")

# Seguro de carro com herança
seguro_carro = SeguroCarro(cliente1, 1500, "2024-01-01 a 2025-01-01", carro1)
print(f"Valor do SeguroCarro (com herança): R$ {seguro_carro.calcular_valor():.2f}")

# Seguro de moto
seguro_moto = SeguroMoto(cliente1, 1200, "2024-01-01 a 2025-01-01", 300)
print(f"Valor do SeguroMoto: R$ {seguro_moto.calcular_valor():.2f}")
