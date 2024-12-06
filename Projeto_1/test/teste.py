#Mostra pro python onde localizar o arquivo cliente.py
import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

#Importando do arquivo `cliente` a classe `Cliente`
from cliente import Cliente

#Criando uma instancia para manipular as informações da classe
cliente_1 = Cliente(nome="Carolina", idade=19, valor=2100)
cliente_1.mostrar_informacoes()  #Usando o metodo mostrar_informacoes
cliente_1.atualizar_saldo(500.0)  #Atualizando o valor do saldo
cliente_1.mostrar_informacoes()  #Mostrando informaçao atualizada
