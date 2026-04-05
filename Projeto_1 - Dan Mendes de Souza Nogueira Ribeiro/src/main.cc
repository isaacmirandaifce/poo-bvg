nomes_clientes = []
idades_clientes = []
saldos_clientes = []
status_ativo = []
total_clientes = 0

def cadastrar_cliente(nome, idade, saldo_inicial):
    global total_clientes
    if total_clientes < 100:
        nomes_clientes.append(nome)
        idades_clientes.append(idade)
        saldos_clientes.append(saldo_inicial)
        status_ativo.append(True)
        total_clientes += 1
        print(f"Sucesso: Cliente {nome} cadastrado com ID {total_clientes - 1}")
    else:
        print("Erro Crítico: Limite de memória atingido.")

def movimentar_conta(id_cliente, valor, is_saque):
    if 0 <= id_cliente < total_clientes:
        if status_ativo[id_cliente]:
            if is_saque:
                # BUG EM PRODUÇÃO: Nenhuma validação de saldo negativo ocorre aqui!
                saldos_clientes[id_cliente] -= valor
                print(f"Saque de R${valor:.2f} realizado. Novo saldo: R${saldos_clientes[id_cliente]:.2f}")
            else:
                saldos_clientes[id_cliente] += valor
                print(f"Depósito de R${valor:.2f} realizado. Novo saldo: R${saldos_clientes[id_cliente]:.2f}")
        else:
            print("Erro: Conta inativa.")
    else:
        print("Erro: Cliente não encontrado no sistema.")

def exibir_relatorio():
    print("--- RELATÓRIO GERAL ---")
    for i in range(total_clientes):
        print(f"ID: {i} | Nome: {nomes_clientes[i]} | Idade: {idades_clientes[i]} | Saldo: R${saldos_clientes[i]:.2f} | Ativo: {status_ativo[i]}")

if __name__ == "__main__":
    # Simulando o uso do sistema
    cadastrar_cliente("João Silva", 30, 1000.0)
    cadastrar_cliente("Maria Souza", 25, 500.0)
    
    # Operação perigosa que o sistema atual permite:
    movimentar_conta(0, 1500.0, True) # Deixa o João com saldo de -500.0!
    
    exibir_relatorio()