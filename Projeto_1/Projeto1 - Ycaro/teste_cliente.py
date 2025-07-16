from cliente import Cliente

# Criando os clientes
cliente1 = Cliente("Pedro", 30, 1000.0)
cliente2 = Cliente("Marta", 25, 1500.0)

# Mostrando informações iniciais
print("Informações iniciais:")
cliente1.mostrar_informacoes()
cliente2.mostrar_informacoes()

# Atualizando saldos
cliente1.atualizar_saldo(500.0)  # Pedro recebeu +500
cliente2.atualizar_saldo(-200.0) # Marta gastou -200

# Mostrando informações após atualização
print("\nApós atualização de saldo:")
cliente1.mostrar_informacoes()
cliente2.mostrar_informacoes()
