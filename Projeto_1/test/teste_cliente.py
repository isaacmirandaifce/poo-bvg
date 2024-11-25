# test/teste_cliente.py

from classes.cliente import Cliente

# Criando uma instância do cliente
cliente1 = Cliente("João Silva", 30, 1000.00)

# Exibindo informações do cliente
cliente1.mostrar_informacoes()

# Atualizando o saldo do cliente
cliente1.atualizar_saldo(500.0)

# Exibindo as informações após a atualização do saldo
cliente1.mostrar_informacoes()

# Atualizando com um valor negativo
cliente1.atualizar_saldo(-200.0)

# Exibindo as informações após nova atualização
cliente1.mostrar_informacoes()
