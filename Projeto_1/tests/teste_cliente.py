from src.cliente import Cliente

# Criação de instância do cliente
cliente1 = Cliente("João Silva", 30, 1000.0)

# Exibe as informações iniciais
cliente1.mostrar_informacoes()

# Atualiza o saldo
cliente1.atualizar_saldo(500.0)

# Exibe novamente para confirmar a atualização
cliente1.mostrar_informacoes()
