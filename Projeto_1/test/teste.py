import sys
import os

#Aqui eu importo o caminho da pasta src ao PYTHONPATH
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

#Eu pego a classe "Cliente" que tá dentro do arquivo "cliente.py" dentro da pasta src

from cliente import Cliente

#Crio um cliente1 que pega os parametros da classe Cliente atribui valores a eles
cliente1 = Cliente(nome="João Silva", idade=30, saldo=1000.0)
cliente1.mostrar_informacoes() #Chama o metodo mostrar_informações
cliente1.atualizar_saldo(500.0) #Atualiza o saldo adicionando 500 conto
cliente1.mostrar_informacoes() #Mostra novamente as informações, dessa vez mostrando o novo saldo