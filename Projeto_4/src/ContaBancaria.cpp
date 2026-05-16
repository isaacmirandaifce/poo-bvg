#include "ContaBancaria.h"
#include "Transacao.h"

ContaBancaria::ContaBancaria(string titular, string cpf, double saldo) {
    this->titular = titular;
    this->cpf = cpf;
    this->saldo = saldo;
}

void ContaBancaria::exibirDados() {
    cout << "Titular: " << this->titular << endl;
    cout << "CPF: " << this->cpf << endl;
    cout << "Saldo atual: R$ " << this->saldo << endl;
}