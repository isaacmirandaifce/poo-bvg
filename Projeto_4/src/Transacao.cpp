#include "Transacao.h"
#include "ContaBancaria.h"
#include <iostream>
#include <iomanip>

Transacao::Transacao(double valor, const std::string& data)
    : valor(valor), data(data) {}

void Transacao::exibirDados() const {
    std::cout << "========================================\n";
    std::cout << "  DADOS DA TRANSAÇÃO\n";
    std::cout << "========================================\n";
    std::cout << "  Valor   : R$ " << std::fixed << std::setprecision(2) << valor << "\n";
    std::cout << "  Data    : " << data << "\n";
    std::cout << "========================================\n";
}

// Definição da função amiga — acessa membros privados/protected diretamente
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    std::cout << "\n[AUDITORIA] Iniciando validação da transação...\n";
    std::cout << "[AUDITORIA] Saldo disponível  : R$ " << std::fixed << std::setprecision(2) << conta.saldo << "\n";
    std::cout << "[AUDITORIA] Valor da transação: R$ " << std::fixed << std::setprecision(2) << transacao.valor << "\n";

    if (transacao.valor <= 0.0) {
        std::cout << "[AUDITORIA] RESULTADO: REJEITADA — valor inválido (deve ser positivo).\n";
        return false;
    }

    if (transacao.valor > conta.saldo) {
        std::cout << "[AUDITORIA] RESULTADO: REJEITADA — saldo insuficiente.\n";
        return false;
    }

    std::cout << "[AUDITORIA] RESULTADO: APROVADA — transação dentro do limite permitido.\n";
    return true;
}
