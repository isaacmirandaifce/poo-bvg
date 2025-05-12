import classes as c

Cliente1 = c.cliente("Marcos", 37, 5800)
Cliente2 = c.cliente("Juliana", 24, 10200)

#mostrar as informacoes do marcos e da julia
Cliente1.mostrar_informacoes() 
Cliente2.mostrar_informacoes()

#atualizar o saldo dos dois clientes
Cliente1.atualizar_saldo(2300) #saldo de 8100
Cliente2.atualizar_saldo(680) #saldo de 10880