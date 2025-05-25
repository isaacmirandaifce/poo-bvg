from datetime import date
from modelo import Modelo
from carro import Carro
from cliente import Cliente
from seguro import SeguroCarro

def exemplo_uso():
    modelo_corolla = Modelo("Corolla")
    carro1 = Carro(2020, "Toyota", modelo_corolla, "Branco", "XYZ-1234")
    carro2 = Carro(2018, "Toyota", Modelo("Etios"), "Prata", "ABC-9876")

    cliente1 = Cliente("João Silva", "123.456.789-00")

    seguro_carro = SeguroCarro(
        cliente=cliente1,
        carros=[carro1, carro2],
        valor=1500.00,
        vigencia_inicio=date(2024, 1, 1),
        vigencia_fim=date(2025, 1, 1)
    )

    print(seguro_carro)
    print("\nValor calculado:", seguro_carro.calcular_valor(1200.0, 0.1))
    print("Vigente?:", "Sim" if seguro_carro.verificar_vigencia() else "Não")

if __name__ == "__main__":
    exemplo_uso()
