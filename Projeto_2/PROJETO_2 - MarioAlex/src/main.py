from datetime import date
from carro import Carro
from cliente import Cliente
from seguro import SeguroCarro

if __name__ == "__main__":
    # Criar objetos
    cliente = Cliente("João Silva", "123.456.789-00")
    carro = Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234")

    # Seguro
    seguro = SeguroCarro(
        cliente=cliente,
        carros=[carro],
        valor=0,
        vigencia_inicio=date(2025, 1, 1),
        vigencia_fim=date(2026, 1, 1)
    )

    seguro.calcular_valor(base_valor=1500, taxa=1.0)

     # Saídas de teste
    print(cliente.exibir_informacoes())
    print(carro.exibir_detalhes())
    print(f"Valor do seguro: R$ {seguro.valor:.2f}")
    print("Seguro válido?", "Sim" if seguro.verificar_vigencia() else "Não")
