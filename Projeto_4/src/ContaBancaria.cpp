#include "ContaBancaria.h"

ContaBancaria::ContaBancaria(std::string titular, std::string cpf, double saldoInicial)
    : titular(titular), cpf(cpf), saldo(saldoInicial) {}

void ContaBancaria::exibirDados() const {
    std::cout << "Titular: " << this->titular 
              << " | CPF: ***.***.***-**" 
              << " | Saldo: R$ " << this->saldo << std::endl;
}