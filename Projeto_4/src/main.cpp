#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

// Implementação da Função Amiga (Friend Function)
// Tem acesso direto aos membros protegidos de ContaBancaria e privados de Transacao
bool validarTransacao(ContaBancaria& conta, Transacao& transacao) {
    std::cout << "\n[AUDITORIA] Analisando transacao realizada em: " << transacao.data << "\n";
    std::cout << "[AUDITORIA] Valor solicitado: R$ " << transacao.valor << "\n";
    
    if (transacao.valor <= conta.saldo) {
        std::cout << "=> STATUS: APROVADA. Margem de seguranca valida.\n";
        return true;
    } else {
        std::cout << "=> STATUS: REJEITADA. Valor excede o saldo de R$ " << conta.saldo << ".\n";
        return false;
    }
}

int main() {
    std::cout << "=== SecureBank Pro - Modulo de Auditoria ===\n\n";

    // Criação da conta para testes
    ContaBancaria contaValidada("Ana Marques", "123.456.789-00", 2500.00);
    contaValidada.exibirDados();

    // Criação de cenários de transação (Legítima e Abusiva)
    Transacao t1(800.00, "01/06/2026");
    Transacao t2(3200.00, "02/06/2026");

    // Execução da auditoria via função amiga
    validarTransacao(contaValidada, t1);
    validarTransacao(contaValidada, t2);

    return 0;
}