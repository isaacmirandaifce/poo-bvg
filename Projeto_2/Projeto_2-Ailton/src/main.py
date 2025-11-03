# importação das classes necessárias
from carro import Carro
from cliente import Cliente
from seguro import SeguroCarro

def main():
    # Criação de instâncias de Cliente, Carro e SeguroCarro
    cliente1 = Cliente("João Silva", "123.456.789-00")
    carro1 = Carro(2020, "Toyota", "Corolla", "Prata", "ABC-1234")
    seguro1 = SeguroCarro(carro1, cliente1, 1500, "01/01/2024", "01/01/2025")

    # Exibição das informações e cálculo do seguro
    cliente1.exibir_informacoes()
    carro1.exibir_informacoes()
    
    # Cálculo do valor do seguro com um fator específico para o carro
    valor = seguro1.calcular_valor(1500, 0.5, fator_carro=1.5)
    print(f"Valor calculado do seguro: R$ {valor:.2f}")
    print(f"Seguro válido ?", "Sim" if seguro1.verificar_vigencia() else "Não")

    
    
    
if __name__ == "__main__":
    main()