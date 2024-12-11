# test/cliente.py

import sys
import os

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../src')

# Importando a classe Cliente
from cliente import Cliente  

# Função de teste
def teste_cliente():
    # Criando um cliente com nome e CPF
    cliente1 = Cliente("João Silva", "123.456.789-00")

    # Exibindo as informações iniciais do cliente
    print("Informações iniciais do cliente:")
    cliente1.exibir_informacoes()

    # Modificando o CPF do cliente
    print("\nModificando o CPF do cliente...")
    cliente1.set_cpf("987.654.321-00")

    # Exibindo as informações após a modificação
    print("\nInformações após a modificação do CPF:")
    cliente1.exibir_informacoes()

# Executando o teste
if __name__ == "__main__":
    teste_cliente()
