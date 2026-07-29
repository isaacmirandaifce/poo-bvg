#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

int main() {
    std::cout << "=== SecureBank Pro: Modulo de Auditoria de Transacoes ===" << std::endl << std::endl;

    // 1. Criando conta bancária do cliente
    ContaBancaria conta("Kelvin", "123.456.789-00", 2500.00);
    conta.exibirDados();

    // 2. Simulação 1: Tentativa de transação legítima
    std::cout << "\n--------------------------------------------------" << std::endl;
    Transacao t1(1200.00, "2026-07-29");
    t1.exibirTransacao();

    if (validarTransacao(conta, t1)) {
        std::cout << "=> Processando transferencia bancaria..." << std::endl;
    }

    // 3. Simulação 2: Tentativa de transação com saldo insuficiente (Alerta de fraude/inconsistência)
    std::cout << "\n--------------------------------------------------" << std::endl;
    Transacao t2(5000.00, "2026-07-29");
    t2.exibirTransacao();

    if (!validarTransacao(conta, t2)) {
        std::cout << "=> Operacao bloqueada pelo sistema de auditoria." << std::endl;
    }

    return 0;
}