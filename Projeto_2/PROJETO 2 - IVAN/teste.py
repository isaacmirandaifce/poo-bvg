# Importações dos módulos necessários
from src.cliente import Cliente
from src.modelo import Modelo
from src.carro import Carro
from src.moto import Moto
from src.seguro.seguro_carro import SeguroCarro
from src.seguro.seguro_moto import SeguroMoto

def main():
    print("\n\n--- Teste de Seguro de Carro ---\n")

    # Criação de um modelo de carro
    modelo_carro = Modelo("Corolla")

    # Instanciação do cliente
    cliente1 = Cliente("Ivan Magalhães", "123.456.789-00")

    # Criação de dois carros associados ao cliente
    carro1 = Carro(2025, "Toyota", modelo_carro, "Branco", "XYZ-1234")
    carro2 = Carro(2019, "Toyota", modelo_carro, "Preto", "ABC-5678")

    # Criação do seguro para os dois carros
    seguro_carro = SeguroCarro(cliente1, [carro1, carro2], 1500.0, "01/01/2025 a 01/01/2026")

    # Exibição das informações do cliente e dos veículos
    cliente1.exibir_informacoes()
    carro1.exibir_detalhes()
    carro2.exibir_detalhes()

    # Cálculo do valor do seguro e verificação de vigência
    print(f"Valor do seguro calculado: {seguro_carro.calcular_valor():.2f}")
    print(f"Seguro está vigente? {'Sim' if seguro_carro.verificar_vigencia() else 'Não'}")

    # Atualização e exibição da cor do segundo carro
    print("Atualizando cor do carro2 para Prata...")
    carro2.atualizar_cor("Prata")
    carro2.exibir_detalhes()

    print("\n\n--- Teste de Seguro de Moto ---\n")

    # Instanciação de outro cliente
    cliente2 = Cliente("Erlano Benevides", "987.654.321-00")

    # Criação de uma moto
    moto = Moto("Honda", "Pop 100", 2024, "MOT-4321")

    # Criação do seguro para a moto
    seguro_moto = SeguroMoto(cliente2, moto, 1000.0, "01/01/2025 a 01/01/2026")

    # Exibição das informações do cliente e da moto
    cliente2.exibir_informacoes()
    moto.exibir_detalhes()

    # Cálculo do valor do seguro e verificação de vigência
    print(f"Valor do seguro calculado: {seguro_moto.calcular_valor():.2f}")
    print(f"Seguro está vigente? {'Sim' if seguro_moto.verificar_vigencia() else 'Não'}")

# Execução principal
if __name__ == "__main__":
    main()