# Exemplo de uso:

from cliente import Cliente

cli1 = Cliente (nome= "João Silva", idade= 30, saldo= 1000.0)
cli1.mostrar_informacoes ()

# Atualizando o saldo:

cli1.att_saldo (500.0)
cli1.mostrar_informacoes () 