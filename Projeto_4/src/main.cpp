#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

// Protótipo da função amiga para o compilador reconhecer
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao);

int main() {
    // 1. Criando conta
    ContaBancaria conta("Joao Silva", "123.456.789-00", 1000.0);

    // 2. Criando uma transacao
    Transacao t1(500.0, "2026-07-07");

    // 3. Auditoria via funcao amiga
    std::cout << "--- Auditoria SecureBank ---\n";
    if (validarTransacao(conta, t1)) {
        std::cout << "Status: Transacao APROVADA.\n";
    } else {
        std::cout << "Status: Transacao NEGADA (Saldo insuficiente).\n";
    }

    return 0;
}
