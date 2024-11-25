import sys
import os

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

from cliente import Cliente

def main():

    cliente1 = Cliente("Joao Silva", 30, 1000.0)

    print("Informações iniciais do cliente:")
    cliente1.mostrar_informacoes()

    print("\nAtualizando saldo: +500.00")
    cliente1.atualizar_saldo(500.0)
    cliente1.mostrar_informacoes()

    print("\nAtualizando saldo: -200.00")
    cliente1.atualizar_saldo(-200.0)
    cliente1.mostrar_informacoes()


if __name__ == "__main__":
    main()
