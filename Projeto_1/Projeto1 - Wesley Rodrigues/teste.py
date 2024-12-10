from cliente import Cliente

#Adicionando valores na variavel c1 (cliente 1)
c1 = Cliente('Wesley', 19, 900)

#chamando os metodos para exibir os valores
c1.showInfor()

#atualizando o valor do saldo para 200
c1.updateSaldo(200)

#mostrando as informacoes novamente com os valores atualizados 
c1.showInfor()
