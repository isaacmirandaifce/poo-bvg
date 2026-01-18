from src.cliente import Cliente

def main():
    cliente1 = Cliente("João Silva", 30, 1000.0)
    cliente1.mostrar_informacoes()   # mostra saldo inicial

    cliente1.atualizar_saldo(500.0)  # adiciona 500
    cliente1.mostrar_informacoes()   # mostra saldo após atualização

    # acessando via getters
    print("Nome via getter:", cliente1.get_nome())
    print("Saldo via getter:", cliente1.get_saldo())

if __name__ == "__main__":
    main() 
