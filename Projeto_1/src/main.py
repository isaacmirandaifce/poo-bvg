
from models.cliente import Cliente


cliente1 = Cliente("João Silva", 30, 1000.0, True)
cliente2 = Cliente("Maria Souza", 25, 500.0, True)


print("=== SALDOS INICIAIS ===")
print("João:", cliente1.saldo)
print("Maria:", cliente2.saldo)


print("\n=== DEPÓSITO ===")
cliente1.depositar(200)


print("\n=== SAQUE ===")
cliente1.sacar(300)

# Tentando sacar mais do que possui
print("\n=== SAQUE INVÁLIDO ===")
cliente1.sacar(1500)

# Exibindo os saldos finais
print("\n=== RELATÓRIO FINAL ===")

clientes = [cliente1, cliente2]

for cliente in clientes:
    print("Nome:", cliente.nome)
    print("Idade:", cliente.idade)
    print("Saldo: R$", cliente.saldo)
    print("Ativo:", cliente.status)
    print("--------------------")
