from datetime import date
from cliente import Cliente
from carro import Carro
from seguro import SeguroCarro, SeguroMoto

cliente1 = Cliente("Davi Maciel", "123.456.789-00")
cliente2 = Cliente("Nágilla Maria", "987.654.321-00")

carro1 = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
carro2 = Carro(2019, "Honda", "Civic", "Prata", "ABC-5678")
moto1 = Carro(2022, "Yamaha", "MT-07", "Preta", "MOT-9999")

seguro1 = SeguroCarro(cliente1, carro1, 0, date(2024, 1, 1), date(2025, 1, 1))
seguro1.calcular_valor(1500, 0.10)

seguro2 = SeguroCarro(cliente2, carro2, 0, date(2025, 6, 1), date(2026, 6, 1))
seguro2.calcular_valor(1200, 0.08)

seguro3 = SeguroMoto(cliente1, moto1, 0, date(2025, 3, 1), date(2026, 3, 1))
seguro3.calcular_valor(800, 0.12)

print()
seguro1.exibir_detalhes()

print()
seguro2.exibir_detalhes()

print()
seguro3.exibir_detalhes()

print()
print("Atualizando cor do carro de Nágilla para Preto...")
carro1.atualizar_cor("Preto")
carro1.exibir_detalhes()
