from models.ContaBancaria import ContaBancaria
from models.Transacao import Transacao

def validar_transacao(conta: ContaBancaria, transacao: Transacao) -> bool:
    """
    Simula uma 'friend function'. 
    Acessa diretamente os atributos da conta e da transação sem getters.
    """
    saldo_atual = conta._saldo 
    valor_transacao = transacao._Transacao__valor 
    
    print("\n--- Iniciando Auditoria de Transação ---")
    if valor_transacao <= saldo_atual:
        print("Transação Válida. Valor dentro do limite de saldo.")
        return True
    else:
        print("Transação Inválida! O valor excede o saldo disponível.")
        return False

if __name__ == "__main__":
    conta_cliente = ContaBancaria("Emyliano Carvalho Costa", "123.456.789-10", 2500.00)
    tentativa_transacao = Transacao(3000.00, "02-08-2026")
    transacao_segura = Transacao(450.00, "02-08-2026")

    print("=== Dados da Conta ===")
    conta_cliente.exibirDaddos()

    validar_transacao(conta_cliente, tentativa_transacao)
    validar_transacao(conta_cliente, transacao_segura)