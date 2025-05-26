from src.cliente import Cliente
from src.modelo import Modelo
from src.carro import Carro
from src.moto import Moto
from src.seguro.Seguro_carro import SeguroCarro
from src.seguro.Seguro_moto import SeguroMoto


def main():
    cliente1 = Cliente("João Silva", "123.456.789-00")
    cliente2 = Cliente("Maria Souza", "987.654.321-00")

    modelo_carro = Modelo("Civic")
    modelo_moto = Modelo("CB500")

    carro1 = Carro(2020, "Honda", modelo_carro, "Preto", "ABC-1234")
    carro2 = Carro(2022, "Toyota", modelo_carro, "Branco", "DEF-5678")

    moto1 = Moto("Honda", modelo_moto.nome, 2021, "GHI-9012")

    print("\n--- Detalhes dos veículos ---")
    carro1.exibir_detalhes()
    carro2.exibir_detalhes()
    moto1.exibir_detalhes()

    print("\n--- Informações dos clientes ---")
    cliente1.exibir_informacoes()
    cliente2.exibir_informacoes()

    seguro_carro = SeguroCarro(cliente1, [carro1, carro2], 5000, "01/01/2025 a 31/12/2025")
    seguro_moto = SeguroMoto(cliente2, moto1, 2000, "01/06/2025 a 31/05/2026")

    print("\n--- Cálculo dos seguros ---")
    valor_seguro_carro = seguro_carro.calcular_valor()
    valor_seguro_moto = seguro_moto.calcular_valor()

    print(f"Valor do seguro de carros: R$ {valor_seguro_carro:.2f}")
    print(f"Valor do seguro da moto: R$ {valor_seguro_moto:.2f}")

    print("\n--- Verificação de vigência ---")
    print(f"Seguro de carro está vigente? {seguro_carro.verificar_vigencia()}")
    print(f"Seguro de moto está vigente? {seguro_moto.verificar_vigencia()}")

    print("\n--- Atualizando cor do carro ---")
    carro1.exibir_detalhes()
    carro1.atualizar_cor("Vermelho")
    carro1.exibir_detalhes()

if __name__ == "__main__":
    main()
