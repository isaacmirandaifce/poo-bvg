#include "ContaBancaria.h"
#include "Transacao.h"
#include <iostream>

ContaBancaria::ContaBancaria(std::string t, std::string c, double s) : titular(t), cpf(c), saldo(s) {}

void ContaBancaria::exibirDados() const {
    std::cout << "Titular: " << titular << "\n" << "CPF: " << cpf << "\n" << "Saldo Atual: R$ " << saldo << "\n";
}

bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    if (transacao.valor > conta.saldo) {
        std::cout << "[ALERTA] Transação recusada Valor (R$ " << transacao.valor << ") maior que o saldo (R$ " << conta.saldo << ").\n";
        return false;
    }

    std::cout << "[SUCESSO] Transação de R$ " << transacao.valor << " autorizada para processamento.\n";
    return true;
}