import sys
import os

# Adiciona o diretório raiz ao caminho do Python
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src')))

from cliente import Cliente

def main():
    # Criando uma instância de Cliente
    cliente1 = Cliente("Joao Silva", 30, 1000.0)

    # Teste: Exibir informações do cliente
    print("Informações iniciais do cliente:")
    cliente1.mostrar_informacoes()

    # Teste: Atualizar saldo com valor positivo
    print("\nAtualizando saldo: +500.00")
    cliente1.atualizar_saldo(500.0)
    cliente1.mostrar_informacoes()

    # Teste: Atualizar saldo com valor negativo
    print("\nAtualizando saldo: -200.00")
    cliente1.atualizar_saldo(-200.0)
    cliente1.mostrar_informacoes()


if __name__ == "__main__":
    main()