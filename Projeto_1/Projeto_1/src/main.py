from models.cliente import Cliente
if __name__ == "__main__":
    # Simulando o uso do sistema
    cliente1 = Cliente("Luiz", 17, 3000)
    cliente2 = Cliente("Emy", 19, 1500)
        
    # Operação perigosa que o sistema atual permite:
    cliente1.movimentarConta(1500.0, True)
    cliente2.movimentarConta(500.0, True)
        
    cliente1.exibirRelatorio()
    cliente2.exibirRelatorio()
        
    