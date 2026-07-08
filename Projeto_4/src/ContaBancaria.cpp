#include "ContaBancaria.h"
#include "Transacao.h"
#include <iostream>

ContaBancaria::ContaBancaria(std::string titular, std::string cpf, double saldo) {
    this->titular = titular;
    this->cpf = cpf;
    this->saldo = saldo;
}
// Implementação da função amiga
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    if (transacao.valor <= conta.saldo) {
        return true;
    }
    return false;
}
