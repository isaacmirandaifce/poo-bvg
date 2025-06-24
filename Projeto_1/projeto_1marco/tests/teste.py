import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from src.cliente import Cliente


cliente1 = Cliente("Marco Rocha", 21, 10000.0)
    
cliente1.mostrar_informacoes()
    
cliente1.atualizar_saldo(500.0)
    
cliente1.mostrar_informacoes()
    
cliente1.atualizar_saldo(-2000.0)
    
cliente1.atualizar_saldo(-300.0)
    
cliente1.mostrar_informacoes()
