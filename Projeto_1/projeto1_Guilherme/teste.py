# Teste de funcionamento
from cliente import Cliente

#criacao de um objeto da classe cliente
cliente1 = Cliente("Guilherme", 19, 1000.0)

#informacoes iniciais do objeto
print("Antes da atualização:")
cliente1.mostrar_informacoes()
#alteraçao do saldo
cliente1.atualizar_saldo(500.0)
#resultado da alteraçao
print("\nDepois da atualização:")
cliente1.mostrar_informacoes()