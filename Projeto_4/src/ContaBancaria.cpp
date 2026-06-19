#include "ContaBancaria.h"
#include <iostream>
#include <iomanip>

ContaBancaria::ContaBancaria(const std::string& titular, const std::string& cpf, double saldoInicial)
    : titular(titular), cpf(cpf), saldo(saldoInicial) {}

void ContaBancaria::exibirDados() const {
    std::cout << "========================================\n";
    std::cout << "  DADOS DA CONTA\n";
    std::cout << "========================================\n";
    std::cout << "  Titular : " << titular << "\n";
    std::cout << "  CPF     : " << cpf << "\n";
    std::cout << "  Saldo   : R$ " << std::fixed << std::setprecision(2) << saldo << "\n";
    std::cout << "========================================\n";
}
