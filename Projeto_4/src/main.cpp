#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

int main() {
    std::cout << "\n======================================\n";
    std::cout << "   SecureBank Pro — Módulo de Auditoria\n";
    std::cout << "======================================\n\n";

    // Criação da conta bancária
    ContaBancaria conta("Ana Paula Ferreira", "123.456.789-00", 1500.00);
    conta.exibirDados();

    // --- Cenário 1: Transação APROVADA ---
    std::cout << "\n--- Cenário 1: Transação dentro do saldo ---\n";
    Transacao t1(800.00, "19/06/2025");
    t1.exibirDados();
    bool resultado1 = validarTransacao(conta, t1);
    std::cout << "[SISTEMA] Status final: " << (resultado1 ? "APROVADA" : "REJEITADA") << "\n";

    // --- Cenário 2: Transação REJEITADA por saldo insuficiente ---
    std::cout << "\n--- Cenário 2: Transação acima do saldo ---\n";
    Transacao t2(2000.00, "19/06/2025");
    t2.exibirDados();
    bool resultado2 = validarTransacao(conta, t2);
    std::cout << "[SISTEMA] Status final: " << (resultado2 ? "APROVADA" : "REJEITADA") << "\n";

    // --- Cenário 3: Transação REJEITADA por valor inválido ---
    std::cout << "\n--- Cenário 3: Transação com valor inválido ---\n";
    Transacao t3(-50.00, "19/06/2025");
    t3.exibirDados();
    bool resultado3 = validarTransacao(conta, t3);
    std::cout << "[SISTEMA] Status final: " << (resultado3 ? "APROVADA" : "REJEITADA") << "\n";

    std::cout << "\n======================================\n";
    std::cout << "   Auditoria concluída.\n";
    std::cout << "======================================\n\n";

    return 0;
}
