import sys
import os

# Adicionando o caminho ao sys.path para importar módulos do diretório src
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

# Importando as classes Cliente, Carro e Seguro.
from Cliente_class import Cliente
from Carro_class import Carro
from Seguro_class import Seguro

if __name__ == "__main__":

    # Criação de instâncias dos objetos
    cliente = Cliente("Danilo Nunes", "459.000.563-11")
    carro = Carro("Chevrolet", "Onix", 2016, "Branco", "TRP-7672")
    
    moto = Carro("Yamaha", "Fazer", 2016, "Vermelha", "BKM-87219") # Criando moto usando a classe Carro para moto por simplicidade
    carro_seguro = Seguro(cliente, carro, 1250, "10/12/2024", "10/12/2025")
    
    moto_seguro = Seguro(cliente, moto, 1000, "01/01/2024", "01/01/2025")
    data_atual = "9/12/2024"

    # Acessando os atributos das classes
    print(f"Cliente: {cliente.get_nome()}, CPF: {cliente.get_cpf()}")
    print(f"\nCarro: {carro.get_marca()} {carro.get_modelo()}, Ano: {carro.get_ano()}, Placa: {carro.get_placa()}, Cor: {carro.get_cor()}")
    print(f"\nMoto: {moto.get_marca()} {moto.get_modelo()}, Ano: {moto.get_ano()}, Placa: {moto.get_placa()}, Cor: {moto.get_cor()}")
    print(f"\nValor do seguro do carro: R${carro_seguro.calcular_valor():.2f}")
    print(f"Valor do seguro da moto: R${moto_seguro.calcular_valor():.2f}")
    print(f"\nValidade do seguro do carro: {carro_seguro.verificar_validade(data_atual)}")
    print(f"Validade do seguro da moto: {moto_seguro.verificar_validade(data_atual)}")
