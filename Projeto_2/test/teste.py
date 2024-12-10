# Importa módulos necessários para configuração do caminho do projeto
import sys
import os

# Adiciona o diretório 'src' ao caminho do sistema para facilitar importações
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

# Importa classes usadas no programa
from classeCliente import Cliente
from classeCarro import Carro
from classeSeguroVeiculo import SeguroVeiculo
from classeSeguroCarro import SeguroCarro
from classeSeguroMoto import SeguroMoto

# Ponto de entrada principal do programa
if __name__ == "__main__":
    # Cria um cliente
    cliente = Cliente("João Silva", "123.456.789-00")
    
    # Cria veículos associados ao cliente
    carro = Carro("Toyota", "Corolla", 2020, "Branco", "XYZ-1234")
    moto = Carro("Honda", "CB500", 2018, "Vermelha", "MOT-5678")
    
    # Cria seguros para os veículos
    seguro_carro = SeguroCarro(cliente, carro, 1500, "01/01/2024", "01/01/2025")
    seguro_moto = SeguroMoto(cliente, moto, 1200.00, "01/01/2024", "01/01/2025")

    # Data de referência para verificação de validade
    dataAtual = "10/12/2024"

    # Exibe informações sobre o seguro do carro
    print(f"Cliente: {cliente.nome}, CPF: {cliente.get_cpf()}")
    print(f"Carro: {carro.marca} {carro.modelo}, Placa: {carro.get_placa()}")
    print(f"Valor do seguro carro: R${seguro_carro.calcularValor():.2f}")  
    print(f"Validade do seguro carro: {seguro_carro.verificarValidade(dataAtual)}") 

    print("\n---\n")

    # Exibe informações sobre o seguro da moto
    print(f"Cliente: {cliente.nome}, CPF: {cliente.get_cpf()}")
    print(f"Moto: {moto.marca} {moto.modelo}, Placa: {moto.get_placa()}")
    print(f"Valor do seguro moto: R${seguro_moto.calcularValor():.2f}")  
    print(f"Validade do seguro moto: {seguro_moto.verificarValidade(dataAtual)}") 
