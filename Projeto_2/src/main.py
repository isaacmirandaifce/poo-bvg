from models .carro import Carro
from models.cliente import Cliente
from models.seguro_carro import SeguroCarro
from models.seguro_moto import SeguroMoto

if __name__ == "__main__":
    carro1 = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")
    cliente = Cliente("João Silva", "123.456.789-00")
    seguro_carro = SeguroCarro(cliente, 0, "01/01/2025", [carro1])
    seguro_moto = SeguroMoto(cliente, 0, "01/01/2026", 200)

    cliente.adicionar_seguro(seguro_carro)
    cliente.adicionar_seguro(seguro_moto)

    carro1.exibir_detalhes()
    cliente.exibir_informacoes()
    print(f"Valor do seguro carro: R${seguro_carro.calcular_valor(1000, 0.1):.2f}")
    print(f"Seguro carro válido: {'Sim' if seguro_carro.verificar_vigencia() else 'Não'}")
    print(f"Valor do seguro moto: R${seguro_moto.calcular_valor(800, 0.08):.2f}")
    print(f"Seguro moto válido: {'Sim' if seguro_moto.verificar_vigencia() else 'Não'}")