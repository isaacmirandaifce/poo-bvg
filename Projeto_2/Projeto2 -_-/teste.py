from src.cliente import Cliente
from src.modelo import Modelo
from src.carro import Carro
from src.moto import Moto
from src.seguro_carro import SeguroCarro
from src.seguro_moto import SeguroMoto

def main():
    # Criar cliente
    cliente = Cliente("Paulo Oliveira", "123.456.789-00")
    cliente.exibir_informacoes()

    # Criar modelos
    modelo1 = Modelo("Corolla")
    modelo2 = Modelo("Civic")

    # Criar carros
    carro1 = Carro(2020, "Toyota", modelo1, "Prata", "ABC-1234")
    carro2 = Carro(2021, "Honda", modelo2, "Preto", "XYZ-5678")

    print("\nDetalhes dos carros:")
    carro1.exibir_detalhes()
    carro2.exibir_detalhes()

    print("\nAtualizando cor do carro 1 para Vermelho...")
    carro1.atualizar_cor("Vermelho")
    carro1.exibir_detalhes()

    # Criar moto
    moto = Moto("Yamaha", "Fazer 250", 2022, "MOT-1010")
    print("\nDetalhes da moto:")
    moto.exibir_detalhes()

    # Seguro Carro
    vigencia = "01/01/2024 a 31/12/2026"
    seguro_carro = SeguroCarro(cliente, [carro1, carro2], 3000.0, vigencia)

    print("\nValor do Seguro Carro calculado:", seguro_carro.calcular_valor())
    print("Vigência válida?", "Sim" if seguro_carro.verificar_vigencia() else "Não")

    # Seguro Moto
    seguro_moto = SeguroMoto(cliente, moto, 1500.0, vigencia)

    print("\nValor do Seguro Moto calculado:", seguro_moto.calcular_valor())
    print("Vigência válida?", "Sim" if seguro_moto.verificar_vigencia() else "Não")

    # Verificando placas
    print("\nPlaca do carro 1:", carro1.get_placa())
    print("Placa da moto:", moto.get_placa())

if __name__ == '__main__':
    main()