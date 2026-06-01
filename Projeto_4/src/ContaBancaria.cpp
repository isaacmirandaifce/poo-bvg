#include "ContaBancaria.h"
#include <iostream>

// Implementação do construtor
ContaBancaria::ContaBancaria(std::string titular, std::string cpf, double saldo) {
    this->titular = titular;
    this->cpf = cpf;
    this->saldo = saldo;
}

// Implementação do método público
void ContaBancaria::exibirDados() {
    std::cout << "--- Dados da Conta ---\n";
    std::cout << "Titular: " << this->titular << "\n";
    std::cout << "CPF: " << this->cpf << "\n";
    // O saldo não é exibido aqui por questões de segurança, sendo acedido apenas pela auditoria.
}