"""
Arquivo principal de execução do sistema bancário.
Responsável por interagir com o usuário, coletar dados e instanciar os clientes.

OBS: Adicionei uma parte interativa simples ao código, onde recebe entradas do usuário possibilitando modificar valores de saque e deposito
"""

from models.cliente import Cliente

if __name__ == "__main__":
    print("CADASTRO DO PRIMEIRO CLIENTE")
    nome = input("Diga seu nome: ")
    idade = int(input("Diga sua idade: "))
    saldo_ini = float(input("Diga seu saldo: "))

    cliente1 = Cliente(nome, idade, saldo_ini)

    print("\nCADASTRO DO SEGUNDO CLIENTE")
    nome = input("Diga seu nome: ")
    idade = int(input("Diga sua idade: "))
    saldo_ini = float(input("Diga seu saldo: "))
     
    cliente2 = Cliente(nome, idade, saldo_ini)

    print("\n--- MOVIMENTAÇÕES ---")
    valor_saque = float(input(f"({cliente1.nome}) Digite a quantidade do saque: "))
    cliente1.sacar(valor_saque)
    
    valor_deposito = float(input(f"({cliente2.nome}) Digite a quantidade do deposito: "))
    cliente2.depositar(valor_deposito)
    
    cliente1.exibir_relatorio()
    cliente2.exibir_relatorio()  