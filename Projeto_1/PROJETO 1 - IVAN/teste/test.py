#from 'C:\Users\ivaan\Downloads\POO1 - IVAN\src.py' import Cliente 
import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

from src import Cliente


# Criação de um objeto da classe Cliente
cliente1 = Cliente("Ivan Magalhães", 19, 15000.0)

cliente1.mostrar_informacoes()  # Exibe os dados do cliente (nome, idade, saldo)

cliente1.atualizar_saldo(500.0)  # Adiciona R$500,00 ao saldo

cliente1.mostrar_informacoes()  # Mostra o saldo atualizado

cliente1.atualizar_saldo(-3000.0)  # Subtrai R$3000,00 do saldo (saque)

cliente1.atualizar_saldo(-100.0)  # Subtrai mais R$100,00 do saldo

cliente1.mostrar_informacoes()  # Exibe o saldo final após as operações
