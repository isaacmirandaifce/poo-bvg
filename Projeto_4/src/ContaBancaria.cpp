#include "ContaBancaria.h"
#include <iostream>

ContaBancaria::ContaBancaria(std::string titular, std::string cpf, double saldo) 
    : titular(titular), cpf(cpf), saldo(saldo) {}

void ContaBancaria::exibirDados() const {
    std::cout << "Titular: " << titular << " | CPF: " << cpf << std::endl;
}