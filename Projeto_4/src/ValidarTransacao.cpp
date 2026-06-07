#include "ContaBancaria.h"
#include "Transacao.h"
#include <iostream>

// Função amiga de ContaBancaria e Transacao
// Acessa diretamente: conta.saldo (protected) e transacao.valor (private)
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    std::cout << "\n[AUDITORIA] Iniciando validacao da transacao..." << std::endl;
    std::cout << "[AUDITORIA] Saldo disponivel: R$ " << conta.saldo      << std::endl;
    std::cout << "[AUDITORIA] Valor solicitado: R$ " << transacao.valor   << std::endl;

    if (transacao.valor <= 0) {
        std::cout << "[AUDITORIA] NEGADA — valor invalido." << std::endl;
        return false;
    }

    if (transacao.valor > conta.saldo) {
        std::cout << "[AUDITORIA] NEGADA — saldo insuficiente." << std::endl;
        return false;
    }

    std::cout << "[AUDITORIA] APROVADA — transacao legitima." << std::endl;
    return true;
}