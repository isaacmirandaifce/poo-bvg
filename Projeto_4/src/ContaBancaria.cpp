#include "ContaBancaria.h"
#include <iostream>

ContaBancaria::ContaBancaria(std::string titular, std::string cpf, double saldo) {
    this->titular = titular;
    this->cpf     = cpf;
    this->saldo   = saldo;
}

void ContaBancaria::exibirDados() const {
    std::cout << "Titular: " << this->titular << std::endl;
    std::cout << "CPF:     " << this->cpf     << std::endl;
    std::cout << "Saldo:   R$ " << this->saldo << std::endl;
}