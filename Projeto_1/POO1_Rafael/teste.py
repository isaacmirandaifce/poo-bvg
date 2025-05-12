# Importando classe do arquivo src
from src.cliente import Cliente

# Criando uma instância de Cliente
cliente1 = Cliente("Rafael", 19, 3000.0)

# Input para receber o valor do aumento, estou usando um getter pois o atributo nome é privado
aumento = float(input("Qual será o aumento de " + cliente1.get_nome() + "? "))

# Exibindo informações iniciais
cliente1.mostrar_informacoes()

# Atualizando o saldo
cliente1.atualizar_saldo(aumento)

# Exibindo informações após atualização
cliente1.mostrar_informacoes()