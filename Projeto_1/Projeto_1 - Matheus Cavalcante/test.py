from Cliente import Cliente

print("\nCadastro de cliente")
nome = input("Digite o nome do cliente: ")
idade = int(input("Digite a idade do cliente: "))
saldo = float(input("Digite o saldo inicial do cliente: "))

cliente1 = Cliente(nome, idade, saldo)
cliente1.mostrar_informacoes()

print("\nAtualizar Saldo")
valor = float(input("Digite o valor para atualizar o saldo: "))
cliente1.atualizar_saldo(valor)

cliente1.mostrar_informacoes()