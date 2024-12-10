
#from 'C:\Users\bolinha\Downloads\ISAAC\cliente.py' import Cliente 
from cliente.py import Cliente

cliente1 = Cliente("Williams Torres", 21, 10000.0)
    
cliente1.mostrar_informacoes()
    
cliente1.atualizar_saldo(500.0)
    
cliente1.mostrar_informacoes()
    
cliente1.atualizar_saldo(-2000.0)
    
cliente1.atualizar_saldo(-300.0)
    
cliente1.mostrar_informacoes()