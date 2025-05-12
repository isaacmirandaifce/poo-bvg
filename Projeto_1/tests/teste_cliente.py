from cliente import Cliente

# criando um cliente
cliente1 = Cliente("João Silva", 30, 1000.0)

print("Informações iniciais:")
cliente1.mostrar_informacoes()

cliente1.atualizar_saldo(500.0)

print("\nSaldo atualizado:")
cliente1.mostrar_informacoes()

# criando outro cliente
cliente2 = Cliente("Ana Souza", 25, 200.0)

print("\nNovo cliente:")
cliente2.mostrar_informacoes()

# testando os getters
print("Nome:", cliente2.get_nome())
print("Idade:", cliente2.get_idade())
print(f"Saldo: R${cliente2.get_saldo():.2f}")

