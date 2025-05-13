from cliente import Cliente

# Criando instância
cliente1 = Cliente("João Silva", 30, 1000.0)

# Exibindo informações
cliente1.mostrar_informacoes()

# Atualizando saldo
cliente1.atualizar_saldo(500.0)
cliente1.mostrar_informacoes()
